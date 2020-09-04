// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "PlatformSwitcher.h"
#include "GameWidget.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"


void AMainGameMode::BeginPlay() {
	Super::BeginPlay();

	ChangeMenuWidget(StartingWidgetClass);

	((UGameWidget*)CurrentWidget)->Load();

	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed,this,&AMainGameMode::OnSwitch);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Restart", IE_Pressed, this, &AMainGameMode::OnRestart).bExecuteWhenPaused=true;
}

void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch()
{
	if (Switched) {

		//Location of the player
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		//Changed the location of the x value
		NewLocation.X = 1200.0f;
		//Set the location to a new modified location
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	else {
		//Location of the player
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		//Changed the location of the x value
		NewLocation.X = 260.0f;
		//Set the location to a new modified location
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->SetActorLocation(NewLocation);
	}
	Switched = !Switched;
}

void AMainGameMode::OnRestart() {
	
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName(),false));

}

void AMainGameMode::OnGameOver(bool win)
{
	((UGameWidget*)CurrentWidget)->OnGameOver(win);

	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AMainGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{

	if (CurrentWidget != nullptr) {

		CurrentWidget->RemoveFromViewport();//Removes any other widget used here
		CurrentWidget = nullptr;

	}

	CurrentWidget = CreateWidget<UUserWidget>((GetWorld()), NewWidgetClass);

	if (CurrentWidget != nullptr) {

		CurrentWidget->AddToViewport();

	}

}
