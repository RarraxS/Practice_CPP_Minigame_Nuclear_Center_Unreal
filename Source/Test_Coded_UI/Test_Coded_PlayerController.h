// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Test_Coded_UserWidget.h"
#include "Test_Coded_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TEST_CODED_UI_API ATest_Coded_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

public:
    // Clase del widget que queremos instanciar
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> Test_WidgetClass;

	
};
