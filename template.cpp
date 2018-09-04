//
//  template.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
// Practice - templates, operator overloading, const reference, const member functions, passing Custom class as a template argument.
//
#include <iostream>
#include "template.h"
using namespace std;

// has to be a const function (const keyword after the function defination)
// because this function is used by the const reference
// this const (2nd ) says that I am not going to modify the state of the object! - > also called as a const member

bool Widget::operator<(const Widget &w1) const
{
    return ( *s < *(w1.s));
}

void Widget:: print()
{
    std::cout << *s << " " << val;
    
}
const int& Widget::getV() const {
    return val;
}

const string& Widget::getS() const{
    return *s;
}

void Widget::setval(int val)
{
    this->val = val;
}

// copy constructor
Widget :: Widget(const Widget& w) : s(new string(w.getS())), val(w.getV())
{
    std::cout << "copy constr";
}

// copy assignment
Widget& Widget :: operator= (const Widget& w)
{
    std::cout << "copy assignment";
    delete s;
    s = new string(w.getS());
    val = w.getV();
    return *this;
}


// move contructor // no const in the argument, because we want to eventually delete this pointer! 
Widget:: Widget(Widget&& widget) : s(widget.s), val(widget.val)
{
    std::cout << "move cnstr";
    widget.s = nullptr;
}

Widget& Widget::operator=(Widget&& widget)
{
    std::cout << "move assignment";

    delete s;
    s = widget.s;
    val = widget.val;
    return *this;
}

#if 0

int main()
{
    double a = 12.0, b = 18.0;
    double res = getMax<double>(a,b);  // 18
    cout << res;
    
    string s = "komal", t = "sneha";
    std::cout << getMax<string>(s,t);  // sneha
    
    Widget w(s, 12); // delete cannot be called on this, because memory is not allocated!- this variable is on stack
    Widget v(t, 13);
    
    std::cout << "\n";
    Widget wres = getMax<Widget>(w,v); // sneha 13
    wres.print();
    
    std::cout << "\n";
    bool wres1 = w.operator<(v); //1
    std::cout << wres1;
    
    
    
    std::cout << "\n";
    Widget* wptr = new Widget("komal",3);
    Widget* vptr = new Widget("sheetal",4);
    Widget wres3 = getMax(*wptr, *vptr);  // sheetal 4
    wres3.print();
    std::cout << "\n";
    
    wptr->print();
    Widget w4 = *wptr;
    Widget w3(w4);
    w3.setval(15);
    w3.print();
    
    std::cout << "\n Again printing w4 to see that this is completely different object";
    w4.print();
    
    Widget w5("abc", 2);  // constr with args called
    
    Widget *w6ptr = &wres;
    *w6ptr = w5;
    w6ptr->setval(99);
    w6ptr->print();  // abc 99
    w5.print();     // abc 2
    
    Widget ws = w3; // copy contrucr
    
    ws = w4; // copy assignment
    
    Widget w6 = Widget("cd",1); // move constructr
    
    w6 = Widget("aa", 1); // move assignment
    
    return 0;
}
#endif