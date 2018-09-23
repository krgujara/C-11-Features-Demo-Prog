//
//  Strnig.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/23/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#if 0
int main()
{
    std::string s1 = "Goodbye";
    std::cout << s1[2];
    
    // these both s1[] and s1.at() return the reference to a character inside a string. But they are not identical.
    
    s1[2] = 'x'; // Goxdbye
    s1.at(2) = 'y'; // Goydbye
    
    s1.at(20); // this will throw the exception out_of_range
    s1[20]; // will be undefined behavior.
    
    // This kind of different between the 'at' function and operator []
    // is in all kinds of STL Containers which are capable of random access.
    
    s1.front();
    s1.back();
    
    s1.push_back('z');
    s1.pop_back();
    
    s1.begin(); // returns the iterator pointing to the begin of string
    s1.end(); // returns the iterator pointing to the end of string
    
    // String provides all these methods to be same like other stl containers.

    // STRING CONTAINER is very similar to VECTOR
    
    // like vector, it has push_front and pop_front. These functions are actually expensive for strings
    
    
    // with the support of iterators, we can construct the string from iterator.
    
    std::string s3(s1.begin(), s1.begin() + 3);// s3 = "Goo"
    
    
    // Range Access of a string
    // assign, append, insert, replace
    
    string s2 = "Dragon Land";
    s1.assign(s2); // s1 = s2
    
    // benifit of assign function is, it is more flexible.
    
    s1.assign(s2, 2, 4); // pos and size ("agon")
    s1.assign("Wisdom"); // s1 becomes wisdom

    s1.assign("Wisdom", 3); // this will assign first 3 characters to cstring
    
    
    // notice the difference
    // when first parameter is string, s1.assign(s2, startPos, numChars)
    // when the first param is cstring, e.g. s2.assign("Wisdom", size)
    // thus if you do, s1.assign(s2, 3); // this will be an error. wont compile!
    
    s1.assign(3,'x'); // s1 = "xxx"
    s1.assign({'a','b','c'});
    
    s1.append(" def"); // s1 = abc def
    
    s1.insert(2,"mountain",4); // this will assign the 4(numChars) characters from moun starting from second character "abmounc def"
    
    s1.replace(2, 5, s2, 3, 3); // starting pos, size , s2, position, size "abgon def"
    
    s1.erase(1, 4); // position size "a def"
    
    s2.substr(2,4); // "agon"
    
    s1 = "abc";
    s1.c_str(); // will return "abc\0" (null character at the end)
    s1.data(); // will also return c_string (chars with \0 at the end in c++ 11
    
    swap(s1,s2);
    
}

#endif