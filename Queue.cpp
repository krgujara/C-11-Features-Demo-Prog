//
//  Queue.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"
#include <queue>
#include <string>
using namespace std;
void sample::print()
{
    std::cout << id << " " <<name;
}

#if 0
int main()
{
    queue<string> q;
    q.push("Komal");
    q.push("Sneha");
    q.push("Vineet");
    q.push("Mishra");
    
    std::cout << "" << q.front();
    
    std::cout << "" << q.back();
    
    queue<sample> qs;
    qs.push(sample(1,"Love you Zindagi"));
    qs.push(sample(2,"Love you too Zindagi"));
    qs.push(sample(3,":)"));

    sample front = qs.front();
    front.print();
    sample back = qs.back();
    back.print();
    
    std::cout << qs.size();
    
    return 0;
}

#endif