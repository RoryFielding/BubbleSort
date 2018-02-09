//
//  main.cpp
//  Bubble Sort
//
//  Created by Rory John Fielding on 08/03/2017.
//  Copyright © 2017 Rory John Fielding. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define POSITIVE_ZERO 0.0
#define NEGATIVE_ZERO -0.0
#define POSITIVE_INFINITY std::numeric_limits<float>::infinity()
#define NEGATIVE_INFINITY -std::numeric_limits<float>::infinity()


bool isMinusZero(float x) {
    if (signbit(x) && x == 0)
        return true;
    return false;
}


//If x > y, return true
bool isGreaterThan(float x, float y)
{
    if (isMinusZero(x) && y == 0)
        return false;
    
    if (isMinusZero(y) && x == 0)
        return true;
    
    return x > y;
}

//function that only holds one value at a time
//input hex for NaNs.
float generateFloat(unsigned int pattern) {
    union FloatInt {
        float f;
        unsigned int l;
    };
    
    FloatInt A;
    A.l = pattern;
    
    return A.f;
}


int main (void)
{
    float NANs[] = { generateFloat(0x7fc00000), generateFloat(0x7ff00000), generateFloat(0x7ff80000), generateFloat(0x7ff82000), generateFloat(0x7ff82400) };
    
    cout << "0.0 > -0.0 ? " << isGreaterThan(0.0, -0.0) << endl;
    cout << "-0.0 > 0.0 ? " << isGreaterThan(-0.0, 0.0) << endl;
    
    
    float hold;
    float array[] = { 4, 3, 1, 1.1, POSITIVE_INFINITY, NEGATIVE_INFINITY, POSITIVE_ZERO, NEGATIVE_ZERO, 8, NANs[1] };
    int arraylength = 10;
    
    for (int j = 0; j<arraylength; j++)
    {
        cout << array[j];
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i<arraylength-1; i++)
    {
        
        for (int j = 0; j<arraylength-1; j++)
        {
            if (isGreaterThan(array[j], array[j + 1]))
            {
                hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        } 
        
    } 
    cout << "Sorted Array is: " << endl;
    if (arraylength == 0)
    {
        cout << "0 \n";
    }
    else {
        for (int i = 0; i < arraylength; i++)
        {
            cout << array[i] << endl;
        }
    }
    return 0;
}
