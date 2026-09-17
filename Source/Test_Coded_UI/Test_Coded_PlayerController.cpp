// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Coded_PlayerController.h"

void ATest_Coded_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (Test_WidgetClass)
    {
        UTest_Coded_UserWidget* MyWidget = CreateWidget<UTest_Coded_UserWidget>(this, Test_WidgetClass);
        if (MyWidget)
        {
            MyWidget->AddToViewport();
        }
    }
}