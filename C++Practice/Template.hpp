//
//  Template.hpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/22/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#ifndef Template_hpp
#define Template_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
template <typename T>
T square(T x)
{
    return x*x;
}

template <typename T>
class BoVector
{
    T arr[1000];
    size_t size;
    
    public:
    
        BoVector() : size(0){}
        void push(T data) {arr[size] = data; size++;}
        T get(int i) const { return arr[i];}
        size_t getSize() const { return size;}
    void print() { for(int i = 0; i < size; i++) std::cout << arr[i] << std::endl;}
};

template <typename T>
BoVector<T> operator* (const BoVector<T>& lhs, const BoVector<T>&rhs)
{
    BoVector<T> ret;
    for(int i = 0; i < rhs.getSize(); i++)
    {
        ret.push(lhs.get(i) * rhs.get(i));
    }
    return ret;
}


#endif /* Template_hpp */
