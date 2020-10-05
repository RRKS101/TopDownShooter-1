#pragma once
#include "PlayerModelFacingComponent.h"
class BaseWeapon : public Entity 
{
protected:

	float timeSinceAttack = 0.0f;

	// Weapon Stats
	float damage = 0.0f;
	float timeBetweenShots = 0.0f;
	



private:
	
public:
	BaseWeapon(float attackRate, float dmg)
	{
		this->damage = dmg;
		this->timeBetweenShots = 1/attackRate;
	}

	virtual ~BaseWeapon() 
	{
		
	}

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	virtual void PrimaryAttack() = 0;
	virtual void SecondaryAttack() = 0;


};