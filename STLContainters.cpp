//
//  STLContainters.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/23/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include "STLContainters.hpp"
#include <vector>
#include <iostream>
#include<deque>
#include<list>
#include<array>
#include<set>
#include<iterator>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#if 0
int main()
{
    vector<int> vec;  // size() = 0 because of default constructor
    
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    vector<int> v2 = {1,2,4};
    
    vec[2]; // no range check
    vec.at(2); // (throw range_error exception of out of range
    
    // because of random access,
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i];
    
    // recommended way over random access
    // because it is faster than random access. Universal way of travering any cotaner
    for(vector<int>::iterator it = vec.begin(); it!=vec.end();it++)
        cout << *it;
    
    for(auto &it: vec)
        cout << it; // range based for loop
    
    
    // vector is a dynamically allocated contiguous array in memory.
    // NONE OTHER container provides this contiguous mem locations.
    
    int*p = &vec[0]; // this is possible because vector elements are stored in the contiguous mem locations
    p[2] = 6;
    
    
    // COMMON MEMBER FUNCTIONS OF ALL CONTAINERS
    
    if(vec.empty()) { cout << "Not possible"; }
    cout << vec.size(); // {4,1,8}
    vector<int> vec2(vec); // copy constructor vec2{4,1,8}
    vec.clear(); //removes all items from vec; vec.size()  = 0
    vec2.swap(vec); // swaps the contents of 2 containers. vec2 becomes empty, and vec has 3 elements
    
    
    /////////////
    
    /*
    
     Deque
    
    */
    
    deque<int> deq = {4,6,7};
    deq.push_back(1);
    deq.pop_back();
    deq.push_front(1);
    deq.pop_front();
    
    cout << deq[1]; // even though deque internally not stored as a contigous memory locations, it provides random access operator []. (to match like vector)
    
    /*
        List
        - doubly linked list
     */
    
    list<int> mylist = {5,2,9};
    mylist.push_front(4);
    mylist.push_back(6);
    
    list<int>::iterator it = find(mylist.begin(), mylist.end(), 2); // itr->2
    
    mylist.insert(it, 8); // {4,5,8, 2,9,6}
                          // O(1), fast than vector/deque
    
    it++;   // it->9
    mylist.erase(it); // mylist : {4,8,5,2,6}
    //mylist.splice(it, mylist2, it_a, it_b); // O(1)
                                    // cut it_a to it_b of data from mylist2 and insert in mylist at position of it
                                    // only takes constant time
    
    /* Array */
    int a[3] = {2,3,4};
    cout << a[2];
    array<int, 3> a1 = {3, 4, 5};
    a1.begin();
    a1.end();
    a1.size();
    
    
    
    /*
     Set
     - No Duplicates
     */
    set<int>myset;
    myset.insert(3);
    myset.insert(1);
    myset.insert(7);  // insert takes O(log(n))
    
    set<int>::iterator it1;
    it1 = myset.find(7); // sequence containers don't have find member function
    
    
    pair<set<int>::iterator, bool> ret;
    ret = myset.insert(3); // no new element inserted
    if(ret.second == false)
        it1 = ret.first; // it now points to element 3
    
    myset.insert(it1,9); // myset: {1,3,7,9} O(log(n)) -> O(1), it points to 3. Why does insert function need it then?? because insert function uses it as a hint to find out where in the container value 9 needs to be stored. So if you can always provide a good hint, then you can reduce the insertion time from O(log(n)) to O(1)
    
    myset.erase(it1); // myset: {1,7, 9}
    
    myset.erase(7); // removes 7 from the set
    
    // None of the sequence containers provide this kind of erasure! It is too slow for them.
    
    /*
     Multi set - also in the <set> library
     */
    
    multiset<int> myset1 = {1,4,2,1};
    multiset<int>::iterator it3 = myset1.find(1);

    // *it3 = 10;    // gives compile time error, and says, you cannot assign the value, because operator* returns a constant value.
    

    /*
     
     Map
     - doesnt allow duplicate keys
     
     */
   
    
    map<char, int> mymap;

    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(make_pair('z',200)); // make_pair is a convenient function! You saves some of your typing, you dont have to specify types. types can be inferred from parameters.
    
    /* REMEMBER : A CLASS TEMPLATE DOESNT INFER TEMPLATE PARAMETER TYPES! A FUNCTIONT TEMPLATE DOES */
    
    map<char, int> ::iterator ir = mymap.begin();
    mymap.insert(ir, pair<char, int>('b', 200)); // ir is the hint!
    ir  = mymap.find('z');  // find item in a map based on a KEY
    
    // showing the contents
    for(ir = mymap.begin(); ir!= mymap.end();  ir++)
    {
        cout << (*ir).first << " => " << (*ir).second << std::endl;
    }
    
    
    
    /*
     
     Multimap - is a map, which allows duplicate keys!!
     
     */
    multimap<char, int> mymap1;
    
    // (*it).first = 'd'; // Error
    
    // Important thng about map and multimap is that you cannot modify the key!
    // *it is basically a pair<const char, int> even if we write <char, int>
    
    
    unordered_set<string> ms = {"red", "green", "pink"};
    unordered_set<string>::const_iterator itr1 = ms.find("green");

    if(itr1 != ms.end())
        cout << *it1;
    
    ms.insert("yellow"); // O(1)
    
    // Hashtable specific API
   // ms.load_factor, ms.bucket, ms.bucket_count
    

    /*
     Associative Arrays
     - implemented using map or unordered map. Not with multimap (because they dont provide unique keys)
     
     */
    unordered_map<char, string> day = {{'S', "Sunday"}, {'M', "Monday"}};
    cout << day['S']; // no range check
    cout << day.at('S'); // has range check
    
    vector<int> vec22 = {1,2,3};
    vec22[5] = 7;
    for(vector<int>:: iterator itx = vec22.begin(); itx!=vec22.end(); itx++)
        std::cout << *itx;
    
    std::cout << vec22[5];
    
    day['W'] = "Wednesday"; // insert W, Wednesday
    day.insert(make_pair('F', "Friday"));
    
    day.insert(make_pair('M', "Monday")); // this operation will fail, and wont be inserted, since its already present in the map
    
    day['M'] = "Monday"; // successful to modify
    
    
    
    
    return 0;
}

#endif

void foo(const unordered_map<char, string> & map)
{
    //std::cout << map['S']; // wont compile, because [] gives the write access on container. So compiler thinks that you are trying to modify the container.
    
    // best way to do is -
    unordered_map<char,string>::const_iterator it = map.find('S');
    if(it!=map.end())
        std::cout << (*it).second;
}






















