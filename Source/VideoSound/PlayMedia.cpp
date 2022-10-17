// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayMedia.h"
#include "MediaSource.h"
#include "MediaPlayer.h"
//MEDIA_SOUND_START
#include "MediaSoundComponent.h"
//MEDIA_SOUND_END

#pragma optimize( "", off )
// Sets default values
APlayMedia::APlayMedia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//MEDIA_SOUND_START
	mMediaSoundCmp = CreateDefaultSubobject<UMediaSoundComponent>(TEXT("MediaSoundCmp"));
	//MEDIA_SOUND_END
}

// Called when the game starts or when spawned
void APlayMedia::BeginPlay()
{
	Super::BeginPlay();

	if (mMediaUI == nullptr && mMediaUIClass != nullptr)
	{
		mMediaUI = CreateWidget(GWorld->GetGameInstance(), mMediaUIClass);
	}
	mMediaUI->AddToViewport();

	UMediaSource* SampleVideo = LoadObject<UMediaSource>(nullptr, TEXT("FileMediaSource'/Game/movie/NewFileMediaSource.NewFileMediaSource'"));

	mMediaPlayer = LoadObject<UMediaPlayer>(nullptr, TEXT("MediaPlayer'/Game/movie/NewMediaPlayer.NewMediaPlayer'"));
	mMediaPlayer->OpenSource(SampleVideo);
	mMediaPlayer->Play();

	//MEDIA_SOUND_START
	mMediaSoundCmp->SetMediaPlayer(mMediaPlayer);
	//MEDIA_SOUND_END
}

// Called every frame
void APlayMedia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
#pragma optimize( "", on )