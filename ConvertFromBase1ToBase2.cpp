//
//  ConvertFromBase1ToBase2.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/24/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include "ConvertFromBase1ToBase2.hpp"
#include <string>
#include<math.h>
#include <iostream>
using namespace std;

// Convert arbitrary base to base 10
long ConvertTo10(const string &input, int base)
{
    if(base < 2 || base > 36)
        return 0;
    
    bool isNegative = (input[0] == '-');
    
    int startIndex = (int)input.length() - 1; // len and size both same, (they gave size to match stl container interface, and length because its by intuition
    int endIndex = isNegative? 1: 0;
    
    long value = 0;
    int digitValue = 1;
    
    for(int i = startIndex; i>=endIndex; --i)
    {
        char c = input[i];
        
        // uppercase it - Note: could be also done with std::toupper
        if(c >= 'a' && c <= 'z')
            c -= ('a'-'A');
        
        // Convert char to int value - Note: could be donewith std::atoi
        // 0-9
        if(c >= '0' && c <= '9')
            c-='0';
        // A-Z
        else
            c = c- 'A'+10;
        
        if(c >= base)
            return 0;
        
        // Get the base 10 value of this digit
        value += c * digitValue;
        
        // Each digit has value base^digit position - Note this avoids pow
        digitValue *= base;
        
    }
    if(isNegative)
        value *= -1;
    
    return value;
}


// Convert base 10 to arbitrary base
// - Base must be between 2 and 36
//if base is invalud, returns "0"
// Note - this whoel function could be done with itoa
string ConvertFrom10(long value, int base)
{
    if(base < 2 || base > 36)
        return "0";
    
    bool isNegative = (value < 0);
    if(isNegative)
        value *= -1;
    
    // Note: it's possible to reserve string based on value string output;
    string output;
    do
    {
        char digit = value % base;
        //0-9
        if(digit < 10)
            digit += '0';
        // A-Z
        else
            digit = digit + 'A' - 10;
        
        // Append digit to string (in reverse order)
        output += digit;
        
        value /= base;
        
    } while (value > 0);
    
    if(isNegative)
        output += '-';
    
    /*
    // Reverse the string - Note: could be done with std::reverse
    int len = (int)output.size() -1;
    for(int i = 0 ; i<= len/2; ++i)
    {
        // Swap characters - Note could be done with std::swap
        //char temp = output[i];
        //output[i] = output[len-i];
        //output[len - i] = temp;
        swap(output[i], output[len-i]);
    }
    */
    reverse(output.begin(), output.end());
    
    return output;
}

string ConvertBase(const string& input, int baseFrom, int baseTo)
{
    return ConvertFrom10(ConvertTo10(input, baseFrom), baseTo);
}

#if 0

int main()
{
    cout << ConvertBase("615", 7, 13) << std::endl; // 1A7
    cout << ConvertBase("1A7", 13, 7) << std::endl; // 1A7
    
    
    cout << ConvertBase("1234", 26, 13) << endl; // 1234(26) = 8864(13)
    cout << ConvertBase("8864", 13, 26) << endl; // 8864(13) = 1234(26)
}


#endif