//
//  Stack.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//
#include <iostream>
#include "Stack.hpp"
#include <stack>
using namespace std;

#if 0
int main()
{
    std::cout << "Hi Komal" << std::endl;
    
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    
    
    s.pop();
    s.pop();
    
    while(!s.empty())
    {
        std::cout << s.top() <<std::endl;
        s.pop();
    }
    
    std::cout << s.size();
    
    return 0;
}
#endif