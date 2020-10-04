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
	virtual void Update() = 0;
	virtual void Render() = 0;

};