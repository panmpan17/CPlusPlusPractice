//
//  mathlib.cpp
//  CPlusPlus
//
//  Created by Michael Pan on 2023/2/16.
//

#include "mathlib.hpp"



float sqaure(float number, int power)
{
    float result = 1;

    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

int sqaure(int number, int power)
{
    int result = 1;

    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}
