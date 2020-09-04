// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"
#include "PlatformSwitcher.h"


void UGameWidget::Load() {

	const FName TextBlockName = FName(TEXT("MessageBlock"));

	if (MessageText == nullptr) {

		MessageText = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));

	}
}

void UGameWidget::OnGameOver(bool win) {

	if (MessageText != nullptr) {

		if (win) {

			MessageText->SetText(FText::FromString(FString(TEXT("You won!\n Press R to restart to play again"))));

		}
		else {
			

				MessageText->SetText(FText::FromString(FString(TEXT("You lose!\n Press R to restart to play again"))));

			}
		

	}

}


