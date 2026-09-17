#include "NuclearCore.h"

//Constructor
ANuclearCore::ANuclearCore()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	state = State::SAFE;

	reducingPressure = false;
	reducingTemperature = false;
	leaking = false;
}

// Iniciate values and timers
void ANuclearCore::BeginPlay()
{
	Super::BeginPlay();

	previousState = state;

	pressure = normalPressure;
	temperature = normalTemperature;

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandlerRisePressure,
		this,
		&ANuclearCore::ChangePressure,
		0.75f,
		true
	);

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandlerRiseTemperature,
		this,
		&ANuclearCore::ChangeTemperature,
		0.75f,
		true
	);

	GetWorld()->GetTimerManager().SetTimer(
		TimerHandlerCheckLeak,
		this,
		&ANuclearCore::ChangeLeak,
		0.75f,
		true
	);
}

// Check state and update timers
void ANuclearCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckState();

	UpdateTimers(DeltaTime);
}

// Manage timers for WARNING state and detect Game Over
void ANuclearCore::UpdateTimers(float DeltaTime)
{
	if (state == State::WARNING && previousState != State::WARNING)
	{
		warningTimes.Add(0.0f);
		isCountingWarning = true;
	}

	if (isCountingWarning && state == State::WARNING && warningTimes.Num() > 0)
	{
		warningTimes.Last() += DeltaTime;

		if (warningTimes.Last() >= maxWarningTime)
			HandleGameOver();
	}

	if (previousState == State::WARNING && state != State::WARNING)
		isCountingWarning = false;

	previousState = state;
}

// Logic for Game Over
void ANuclearCore::HandleGameOver()
{
	gameOver = true;
}

// Reset game
UFUNCTION(BlueprintCallable, Category = "Gameplay")
void ANuclearCore::ResetCore()
{
	// Reset values
	pressure = normalPressure;
	temperature = normalTemperature;
	reducingPressure = false;
	reducingTemperature = false;
	leaking = false;
	state = State::SAFE;
	previousState = State::SAFE;
	isCountingWarning = false;
	gameOver = false;

	// Clear warning times array
	warningTimes.Empty();
}

// Check the state of the core based on pressure, temperature and leaking status
void ANuclearCore::CheckState()
{
	if (reducingPressure || reducingTemperature)
	{
		state = State::REDUCING;
		return;
	}

	if (CheckPressure() && CheckTemperature() && !leaking)
	{
		state = State::SAFE;
		return;
	}

	state = State::WARNING;
}

// Check if pressure is below the high pressure threshold
bool ANuclearCore::CheckPressure()
{
	return pressure < highPressure;
}

// Check if temperature is below the high temperature threshold
bool ANuclearCore::CheckTemperature()
{
	return temperature < highTemperature;
}

// Logic to change pressure
// If the core is in SAFE state, it will increase the values
// If it's in REDUCING state, it will decrease the values until they reach normal levels
void ANuclearCore::ChangePressure()
{
	if (state == State::SAFE)
	{
		if (FMath::RandRange(1, 100) <= pressureHighRiseProbability)
		{
			int32 randomNumber = FMath::RandRange(highPressure, maxPressure);
			pressure = FMath::Max(pressure, randomNumber);
			return;
		}

		pressure += pressureIncrement;
	}

	else if (state == State::REDUCING && reducingPressure)
	{
		pressure -= pressureIncrement;

		if (pressure <= normalPressure)
		{
			pressure = normalPressure;
			reducingPressure = false;
		}
	}
}

// Logic to change temperature
// If the core is in SAFE state, it will increase the values
// If it's in REDUCING state, it will decrease the values until they reach normal levels
void ANuclearCore::ChangeTemperature()
{
	if (state == State::SAFE)
	{
		if (FMath::RandRange(1, 100) <= temperatureHighRiseProbability)
		{
			int32 randomNumber = FMath::RandRange(highTemperature, maxTemperature);
			temperature = FMath::Max(temperature, randomNumber);
			return;
		}

		temperature += temperatureIncrement;
	}

	else if (state == State::REDUCING && reducingTemperature)
	{
		temperature -= temperatureIncrement;

		if (temperature <= normalTemperature)
		{
			temperature = normalTemperature;
			reducingTemperature = false;
		}
	}
}

// Logic to rise leak
void ANuclearCore::ChangeLeak()
{
	if (state == State::SAFE && FMath::RandRange(1, 100) <= leakingProbability)
		leaking = true;
}

// Logic for enabling pressure reduction
void ANuclearCore::ReducePressure()
{
	if (pressure > highPressure)
		reducingPressure = true;
}

// Logic for enabling temperature reduction
void ANuclearCore::ReduceTemperature()
{
	if (temperature > highTemperature)
		reducingTemperature = true;
}

// Logic for stopping leaking
void ANuclearCore::StopLeaking()
{
	if (leaking)
		leaking = false;
}