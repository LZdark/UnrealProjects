#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(Blueprintable)
class TESTDIRTY_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();
	UPROPERTY(EditAnywhere, meta = (ClampMin = 0)) float maxHealth;
	
	UFUNCTION(BlueprintPure) float GetCurrentHealth() const;
	UFUNCTION(BlueprintCallable) void ReceiveDamage(float damageAmount);
	UFUNCTION(BlueprintCallable) void ReceiveHealing(float healAmount);
	
protected:
	virtual void BeginPlay() override;

private:
	float currentHealth;

	void SetCurrentHealth(float newHealth);
	void ModifyHealth(float healthModifier);
};
