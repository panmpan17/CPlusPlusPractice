//
//  random.cpp
//  CPlusPlus
//
//  Created by Pan Michael on 2024/7/6.
//

#include "random.hpp"
#include <iostream>
//#include "mathlib.hpp"



int random_int(int min, int max)
{
    return rand() % (max - min) + min;
}
