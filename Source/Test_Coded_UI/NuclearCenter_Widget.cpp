// Fill out your copyright notice in the Description page of Project Settings.

#include "NuclearCenter_Widget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"

void UNuclearCenter_Widget::NativeConstruct()
{
    Super::NativeConstruct();

    // Verificar que el botón no sea nullptr antes de asignar el evento
    /*if (MyButton)
    {
        MyButton->OnClicked.AddDynamic(this, &UTest_Coded_UserWidget::OnMyButtonClicked);
    }*/

}

//void UNuclearCenter_Widget::OnMyButtonClicked()
//{
//    UE_LOG(LogTemp, Warning, TEXT("¡Botón presionado!"));
//}
//
//void UNuclearCenter_Widget::SetImageTexture(UTexture2D* NewTexture)
//{
//    /*if (MyImage && NewTexture)
//    {
//        MyImage->SetBrushFromTexture(NewTexture);
//        UE_LOG(LogTemp, Warning, TEXT("¡Textura cambiada!"));
//    }*/
//
//}
