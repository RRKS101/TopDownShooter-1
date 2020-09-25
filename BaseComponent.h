#pragma once
#include "Definitions.h"

class Entity;
class BaseComponent
{
protected:
	

public:
	Entity* owner;
	BaseComponent(Entity* o) { this->owner = o; }
	virtual ~BaseComponent() { }

	virtual void Update() = 0;
	virtual void Render() = 0;
};