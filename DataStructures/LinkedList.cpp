//
//  LinkedList.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>
using namespace std;
Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
}
LinkedList:: LinkedList() : first(nullptr), last(nullptr) {}


void LinkedList::addNode(int val)
{
    if(first == nullptr)
    {
        first = new Node(val);
        last = first;
    }
    else
    {
        last->next = new Node(val);
        last = last->next;
    }
}


void LinkedList:: print()
{
    Node* ptr = first;
    while(ptr!= nullptr)
    {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

// delete second node
void LinkedList:: deleteSecond()
{
    if(first == nullptr || first->next == nullptr)
        return ;
    Node *nodeToDel = first->next;
    Node *next = nodeToDel->next;
    first->next = next;

    nodeToDel = nullptr;
}

#if 0

int main()
{
    std::cout << "Hi komal" << std::endl;
    LinkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    
    
    ll.print();
    ll.deleteSecond();
    ll.print();
}

#endif