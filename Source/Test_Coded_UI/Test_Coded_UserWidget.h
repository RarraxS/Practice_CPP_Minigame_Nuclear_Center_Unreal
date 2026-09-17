// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Test_Coded_UserWidget.generated.h"

UCLASS()
class TEST_CODED_UI_API UTest_Coded_UserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    //Esta es la versión en C++ de la función Event Construct de los widget blueprint
    virtual void NativeConstruct() override;

public:
    #pragma region CORE 1

    #pragma region PREASURE

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Preasure_1;

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* ProgressBar_Preasure_1;

    UPROPERTY(meta = (BindWidget))
    class UImage* Image_Preasure_1;

    #pragma endregion

    #pragma region TEMPERATURE

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Temperature_1;

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* ProgressBar_Temperature_1;

    UPROPERTY(meta = (BindWidget))
    class UImage* Image_Temperature_1;

    #pragma endregion

    #pragma region LEAKING

    UPROPERTY(meta = (BindWidget))
    class UButton* Button_Leaking_1;

    UPROPERTY(meta = (BindWidget))
    class UImage* Image_Leaking_1;

    #pragma endregion

    #pragma endregion


    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Nuclear")
    //class ANuclearCore* NuclearCoreRef;

    //// Referencia a una barra de progreso en la UI
    //UPROPERTY(meta = (BindWidget))
    //class UProgressBar* MyProgressBar;

    //// Referencia a un texto en la UI
    //UPROPERTY(meta = (BindWidget))
    //class UTextBlock* MyText;

    //// Referencia a un botón en la UI
    //UPROPERTY(meta = (BindWidget))
    //class UButton* MyButton;

    //// Referencia a una imagen en la UI
    //UPROPERTY(meta = (BindWidget))
    //class UImage* MyImage;
    

    // Método para manejar la pulsación del botón
    UFUNCTION()
    void OnMyButtonClicked();

    // Método para cambiar la textura de la imagen
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetImageTexture(UTexture2D* NewTexture);


};
