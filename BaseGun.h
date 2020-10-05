#pragma once
#include "BaseMelee.h"
class BaseGun : public BaseWeapon
{
protected:
	int16_t clip;
	int16_t reserve;

	float reloadTime;
	std::string name;
public:
	BaseGun(float attackRate, float damage, int16_t clip, int16_t reserve, float reloadTime, std::string name) : BaseWeapon(attackRate, damage)
	{
		this->clip = clip;
		this->reserve = reserve;
		this->reloadTime = reloadTime;
		this->name = name;
	}

	virtual ~BaseGun() 
	{
		
	}

	virtual void PrimaryAttack() = 0;
	virtual void SecondaryAttack() = 0;

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
};