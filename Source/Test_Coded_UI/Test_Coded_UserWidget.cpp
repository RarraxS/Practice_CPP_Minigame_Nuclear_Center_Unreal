// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Coded_UserWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"

void UTest_Coded_UserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // Verificar que el botón no sea nullptr antes de asignar el evento
    /*if (MyButton)
    {
        MyButton->OnClicked.AddDynamic(this, &UTest_Coded_UserWidget::OnMyButtonClicked);
    }*/

}

void UTest_Coded_UserWidget::OnMyButtonClicked()
{
    UE_LOG(LogTemp, Warning, TEXT("¡Botón presionado!"));
}

void UTest_Coded_UserWidget::SetImageTexture(UTexture2D* NewTexture)
{
    /*if (MyImage && NewTexture)
    {
        MyImage->SetBrushFromTexture(NewTexture);
        UE_LOG(LogTemp, Warning, TEXT("¡Textura cambiada!"));
    }*/

}
