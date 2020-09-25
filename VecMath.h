#pragma once
#include "Definitions.h"
namespace Engine
{
    float getAngle(sf::Vector2f a, sf::Vector2f b)
    {
        float length1 = sqrt(a.x * a.x + a.y * a.y);// calculate modulus of Vector V1 i.e. |V1| 
        float length2 = sqrt(b.x * b.x + b.y * b.y);
        // calculate modulus of Vector V2 i.e. |V2| 
        float dot = a.x * b.x + a.y * b.y; // calculate dot product between two vectors. 

        float ab = dot / (length1 * length1);

        std::cout << ab << std::endl;

        if (ab >= 1.0)
            return 0.0;
        else if (ab <= -1.0)
            return PI;// PI means π  
        else
            return acos(ab); // 0..PI 
    }
}