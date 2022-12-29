#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	maxHealth = 100.0f;
}

float UHealthComponent::GetCurrentHealth() const
{
	return currentHealth;
}

void UHealthComponent::ReceiveDamage(float damageReceived)
{
	ModifyHealth(-damageReceived);
}

void UHealthComponent::ReceiveHealing(float healAmount)
{
	ModifyHealth(healAmount);
}

void UHealthComponent::ModifyHealth(float healthModifier)
{
	const float newHealth = FMath::Clamp(currentHealth + healthModifier, 0.0f, maxHealth);
	SetCurrentHealth(newHealth);
}

void UHealthComponent::SetCurrentHealth(float newHealth)
{
	currentHealth = newHealth;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetCurrentHealth(maxHealth);
}