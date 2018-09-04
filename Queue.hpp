//
//  Queue.hpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//
#include <iostream>
#ifndef Queue_hpp
#define Queue_hpp
#include <string>
#include <stdio.h>

using namespace std;
class sample
{
    int id;
    string name;
    
public:
    sample(const int& id, const string& name) : id(id), name(name) {}
    void print();
};


#endif /* Queue_hpp */
