//
//  NumericLimits.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/24/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include "NumericLimits.hpp"

// numeric_limits class template provides a standarsized way to query various proeprties of arithmetic types -

// e.g. Largest possible value of type int

#include<iostream>
using namespace std;
int main()
{
    std::cout << "Max Int Value " <<numeric_limits<int>::max() << std::endl; // This is like integer.max value in java
    
    std::cout << "Min Int Value " <<numeric_limits<int>::min() << std::endl; // This is like integer.max value in java
    
    // Above results show that int in C++ is 32 BIT SIGNED INTEGER WITH
    // MAX VALUE = 2147483647
    // MIN VALUE = -2147483648
    
    // SHORT (16 BITS SIGNED) // when ever you say short, it is by default unsigned short
    cout << "Max Short Value " << numeric_limits<short>::max() <<endl;
    cout << "Min Short Value " << numeric_limits<short>::min() << endl;
    
    cout << "Max Long Value " << numeric_limits<long>::max() <<endl;
    cout << "Min Long Value " << numeric_limits<long>::min() << endl;
    
    cout << "Max Unsigned Short Value " << numeric_limits<unsigned short>::max() <<endl;
    cout << "Min Unsigned Short Value " << numeric_limits<unsigned short>::min() << endl;
    
    cout << "Max Unsigned Short Value " << numeric_limits<char>::max() <<endl;
    cout << "Min Unsigned Short Value " << numeric_limits<unsigned short>::min() << endl;
    
    cout << "Lowest size_t " << numeric_limits<size_t>::lowest() << std::endl;
    cout << "Min size_t " << numeric_limits<size_t>::min() << std::endl; // size_t is unsigned long
    cout << "Max size_t " << numeric_limits<size_t>::max() << std::endl;
}