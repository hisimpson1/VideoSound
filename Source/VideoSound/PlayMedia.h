// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "PlayMedia.generated.h"

UCLASS()
class VIDEOSOUND_API APlayMedia : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayMedia();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY()
	class UMediaPlayer* mMediaPlayer = nullptr;

	//MEDIA_SOUND_START
	UPROPERTY()
	class UMediaSoundComponent* mMediaSoundCmp = nullptr;
	//MEDIA_SOUND_END

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayMedia")
	TSubclassOf<UUserWidget> mMediaUIClass;

private:
	UPROPERTY()
	class UUserWidget* mMediaUI;
};
