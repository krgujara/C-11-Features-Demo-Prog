//
//  vector.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/3/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#if 0
int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    vector<vector<int>> res;
    res.push_back(vec);
    
    res.push_back({1,2});
    
    vec.size();
    
    
    vector<int>:: iterator it = vec.begin();
    
    while(it != vec.end())
    {
        std::cout << *it;
        it++;
    }

    
    vec.pop_back();
    vec.pop_back(); // this doesnot affect the vector already added in res
    
    
    vector<int>:: iterator it1 = vec.begin();
    
    while(it1 != vec.end())
    {
        std::cout << *it1;
        it1++;
    }
    
    
    std::cout << "printing 2d vector";
    
    //assuming you have a "2D" vector vvi (vector of vector of int's)
    
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;
    
    for (row = res.begin(); row != res.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            // do stuff ...
            std::cout << *col;
        }
        std::cout << "\n";
    }
    
    int arr[5] = {1,5,7,0};
    sort(arr, arr + (sizeof(arr)/sizeof(int)));
    
    cout << "printing array";
    for(int i = 0 ; i < (sizeof(arr)/sizeof(int)); i++)
    {
        std::cout << arr[i];
    }
    vector<int> c1(arr, arr + (sizeof(arr)/sizeof(int)));
    std::cout << "size of vec" << c1.size();
    
    c1.erase(c1.begin()); // erase takes the iterator as a parameter
    std::cout << "size of vec" << c1.size();
    
    c1.erase(c1.begin()+2, c1.end());
    std::cout << "size of vec" << c1.size();
    
    vec.insert(c1.begin(), 1);
    
    return 0;
}
#endif