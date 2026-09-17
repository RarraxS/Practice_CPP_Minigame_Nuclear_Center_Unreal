// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NuclearCenter_Widget.generated.h"


UCLASS()
class TEST_CODED_UI_API UNuclearCenter_Widget : public UUserWidget
{
	GENERATED_BODY()

protected:
    //Esta es la versión en C++ de la función Event Construct de los widget blueprint
    virtual void NativeConstruct() override;

public:
    #pragma region CORE 1

    #pragma region PREASURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Preassure_1;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Preassure_1;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Preassure_1;

    #pragma endregion

    #pragma region TEMPERATURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Temperature_1;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Temperature_1;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Temperature_1;

    #pragma endregion

    #pragma region LEAKING

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Leaking_1;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Leaking_1;

    #pragma endregion

    #pragma endregion

    #pragma region CORE 2

    #pragma region PREASURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Preassure_2;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Preassure_2;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Preassure_2;

    #pragma endregion

    #pragma region TEMPERATURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Temperature_2;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Temperature_2;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Temperature_2;

    #pragma endregion

    #pragma region LEAKING

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Leaking_2;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Leaking_2;

    #pragma endregion

    #pragma endregion

    #pragma region CORE 3

    #pragma region PREASURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Preassure_3;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Preassure_3;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Preassure_3;

    #pragma endregion

    #pragma region TEMPERATURE

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Temperature_3;

    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* ProgressBar_Temperature_3;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Temperature_3;

    #pragma endregion

    #pragma region LEAKING

    //UPROPERTY(meta = (BindWidget))
    //class UButton* Button_Leaking_3;

    //UPROPERTY(meta = (BindWidget))
    //class UImage* Image_Leaking_3;

    #pragma endregion

    #pragma endregion

    //// Método para manejar la pulsación del botón
    //UFUNCTION()
    //void OnMyButtonClicked();

    //// Método para cambiar la textura de la imagen
    //UFUNCTION(BlueprintCallable, Category = "UI")
    //void SetImageTexture(UTexture2D* NewTexture);


};
