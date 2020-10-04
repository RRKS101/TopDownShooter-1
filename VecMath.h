#pragma once
#include "Definitions.h"


float getAngle(sf::Vector2f a, sf::Vector2f b)
{
    return fmod(270 - atan2(b.y - a.y, b.x - a.x) * (180 / 3.14159265358979), 360);
}
