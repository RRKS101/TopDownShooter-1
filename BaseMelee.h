#pragma once
#include "BaseWeapon.h"
class BaseMelee : public BaseWeapon
{
protected:

public:
	BaseMelee(float attackRate, float damage) : BaseWeapon(attackRate, damage)
	{
		
	}

	virtual ~BaseMelee() 
	{
		
	}

	virtual void PrimaryAttack() = 0;
	virtual void SecondaryAttack() = 0;

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
};