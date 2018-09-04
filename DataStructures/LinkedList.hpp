//
//  LinkedList.hpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

// struct is similar to class, except that the data members of the struct are public by default
struct Node
{
    int data;
    Node* next;
    Node(int val);
    
};

class LinkedList
{
    Node* first;
    Node* last;
    
    public:
    LinkedList();
    
    void addNode(int val);
    
    void print();
  
    void deleteSecond();
};



#endif /* LinkedList_hpp */
