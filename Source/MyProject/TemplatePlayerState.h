// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "TemplateData.h"
#include "TemplatePlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ATemplatePlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	ATemplatePlayerState();

	virtual void BeginPlay() override;

	void AddKill(int Amount);
	void AddDeath(int Amount);
	void AddScore(int Amount);
	void AddAssist(int Amount);

	UFUNCTION(BlueprintCallable, Category = "Template")
	int GetKills();
	UFUNCTION(BlueprintCallable, Category = "Template")
	int GetAssists();
	UFUNCTION(BlueprintCallable, Category = "Template")
	int GetDeaths();
	UFUNCTION(BlueprintCallable, Category = "Template")
	int GetScore();
	UFUNCTION(BlueprintCallable, Category = "Template")
	FString GetPlayerName();
	UFUNCTION(BlueprintCallable, Category = "Template")
	int GetPlayerTeamNumber();

	UFUNCTION(BlueprintCallable, Category = "Template")
	void SetPlayerTeamNumber(int NewTeam);

	UFUNCTION(BlueprintCallable, Category = "Template")
	void SetPlayerPower(int phase, EPlayerPower NewPower);

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps)const override;

	UFUNCTION(BlueprintCallable, Category = "Template")
	EPlayerPower GetPower1();
	UFUNCTION(BlueprintCallable, Category = "Template")
	EPlayerPower GetPower2();
	UFUNCTION(BlueprintCallable, Category = "Template")
	EPlayerPower GetPower3();

	void ResetPlayer();

	UFUNCTION(Reliable, Server, WithValidation)
	void ServerChangeTeamNumber(int teamNumber, const FString& theName);
	virtual void ServerChangeTeamNumber_Implementation(int teamNumber, const FString& theName);
	virtual bool ServerChangeTeamNumber_Validate(int teamNumber, const FString& theName);

	UFUNCTION(Reliable, NetMulticast, WithValidation)
	void MulticastChangeTeamNumber(int teamNumber, const FString& theName);
	virtual void MulticastChangeTeamNumber_Implementation(int teamNumber, const FString& theName);
	virtual bool MulticastChangeTeamNumber_Validate(int teamNumber, const FString& theName);

protected:

	UPROPERTY(Replicated)
	int _playerScore;

	UPROPERTY(Replicated)
	FString _playerName;

	UPROPERTY(Replicated)
	int _death;

	UPROPERTY(Replicated)
	int _kills;
	
	UPROPERTY(Replicated)
	int _assist;

	UPROPERTY(Replicated)
	int _playerTeamNumber;

	UPROPERTY(Replicated)
	EPlayerPower _playerPower;

	UPROPERTY(Replicated)
	EPlayerPower _playerPower2;

	UPROPERTY(Replicated)
	EPlayerPower _playerPower3;
};
