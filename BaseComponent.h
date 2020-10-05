#pragma once
#include "VecMath.h"

class Entity;
class BaseComponent
{
protected:
	

public:
	Entity* owner;
	BaseComponent(Entity* o) { this->owner = o; }
	virtual ~BaseComponent() { }

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
};