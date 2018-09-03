//
//  template.h
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//


#ifndef template_h
#define template_h

#include <iostream>
using namespace std;

// Practice - templates, operator overloading, const reference, const member functions, passing Custom class as a template argument, destructor, copy constructor.

class Widget
{
    string *s;
    int val;
    
    
    public :
    
    Widget(string str, int val) : s(new string(str)), val(val){}
    
    // myVar = 8; //not dynamically allocated. Can't call delete on it.
    // myPointer = new int; // dynamically allocated, can call delete on it.
    ~Widget(){ //delete s;
    }  // delete has to be called only if the memory is allocated dynamically.. Widget w("acb", 7); = memory is allocated on stack, thus you cannot call delete on this! but if you write - Widget* w = new Widget("abc", 5); => then you can call delete on this dynamically allocated memory!
    void print();
    bool operator<(const Widget &w1) const;

    void setval(int val);
    
    // copy constructor
    Widget(const Widget& w);
    
    // copy assignment
   Widget& operator=(const Widget& w);


    const string& getS() const;
    const int& getV() const;
    
    //Widget& operator=(Widget const &rhs);
};

// const objects are only limited to access the member functions marked as const!
// (thus in case of Widget instantiation of template, const Widget &a can only access const functions!
// (thus function operator< has to be a const member function)

template <typename T>
const T& getMax (const T &a, const T &b)
{
    return (a < b) ? b : a;
}


#endif /* template_h */
