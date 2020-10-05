#pragma once
#include "ScreenBounder.h"
class BaseFacingComponent : public BaseComponent
{
private:

public:
	BaseFacingComponent(Entity* o) : BaseComponent(o) 
	{
		
	}

	virtual ~BaseFacingComponent() 
	{
		
	}
protected:
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;

	virtual float getAngle(sf::Vector2f a, sf::Vector2f b)
	{
		return 360 - fmod(270 - atan2(b.y - a.y, b.x - a.x) * (180 / 3.14159265358979), 360);
	}

};