#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NuclearCore.generated.h"


// Enum to represent the state of the nuclear core
UENUM(BlueprintType)
enum class State : uint8
{
	SAFE     UMETA(DisplayName = "Safe"),
	WARNING  UMETA(DisplayName = "Warning"),
	CRITICAL UMETA(DisplayName = "Critical"),
	REDUCING UMETA(DisplayName = "Reducing"),
};

UCLASS()
class TEST_CODED_UI_API ANuclearCore : public AActor
{
	GENERATED_BODY()

public:
	ANuclearCore();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Mesh component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	// State of the core
	UPROPERTY(BlueprintReadOnly)
	State state;

	// Array to save the player's time reaction
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	TArray<float> warningTimes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float maxWarningTime = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	bool gameOver = false;

#pragma region PRESSURE

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure")
	int32 normalPressure = 135;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure")
	int32 highPressure = 175;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure")
	int32 criticalPressure = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure")
	int32 maxPressure = 220;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure")
	int32 pressureIncrement = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Pressure",
		meta = (ClampMin = "0", ClampMax = "100"))
	int32 pressureHighRiseProbability = 20;

	UPROPERTY(BlueprintReadOnly)
	int32 pressure;

	UPROPERTY(BlueprintReadOnly)
	bool reducingPressure;

#pragma endregion

#pragma region TEMPERATURE

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature")
	int32 normalTemperature = 290;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature")
	int32 highTemperature = 350;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature")
	int32 criticalTemperature = 450;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature")
	int32 maxTemperature = 480;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature")
	int32 temperatureIncrement = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Temperature",
		meta = (ClampMin = "0", ClampMax = "100"))
	int32 temperatureHighRiseProbability = 20;

	UPROPERTY(BlueprintReadOnly)
	int32 temperature;

	UPROPERTY(BlueprintReadOnly)
	bool reducingTemperature;

#pragma endregion

#pragma region LEAKING

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuration|Leaking",
		meta = (ClampMin = "0", ClampMax = "100"))
	int32 leakingProbability = 20;

	UPROPERTY(BlueprintReadOnly)
	bool leaking;

#pragma endregion


	UFUNCTION(BlueprintCallable)
	void ReducePressure();

	UFUNCTION(BlueprintCallable)
	void ReduceTemperature();

	UFUNCTION(BlueprintCallable)
	void StopLeaking();

	UFUNCTION(BlueprintCallable)
	void ResetCore();

private:

	State previousState;

	bool isCountingWarning = false;

	void UpdateTimers(float DeltaTime);


	FTimerHandle TimerHandlerRisePressure;
	FTimerHandle TimerHandlerRiseTemperature;
	FTimerHandle TimerHandlerCheckLeak;

	void CheckState();

	bool CheckPressure();
	bool CheckTemperature();

	void ChangePressure();
	void ChangeTemperature();
	void ChangeLeak();

	void HandleGameOver();
};