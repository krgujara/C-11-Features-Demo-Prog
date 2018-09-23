//
//  STLContainters.hpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/23/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#ifndef STLContainters_hpp
#define STLContainters_hpp

#include <stdio.h>
/*
 
 There are 3 types of containers.
 
 Sequence Containers (array and linkedlist
 - vector, deque, list, forward list, array
 
 Associative Containers (binary tree)
 - set, multiset
 - map, multimap
 
 Unordered Containers (hash table)
 - Unordered set/ multiset
 - Unordered map/ multimap
 
 STL Headers -
 
 #include<vector>
 #include<deque>
 #include<list>
 #include<set> // set and multiset
 #include<map> // map and multimap
 #include<unordered_set> // unordered set/ multiset
 #include<unordered_map> // unordered map and multimap
 #include <iterator>
 #include<algorithm>
 #include<functional> // for functors
 
 */


// Since the containers have some common apis, you may expect that there is some inheritance and polymorphism involved. But NO PENALTY OF ABSTRACTION. VERY EFFICIENT.

// STL is v efficient. All the penalty of abstraction is handled v efficiently. It can load as fast as well crafted c program.



/*
 Vector - dynamic Array which loads in a one direction

 VECTOR
 
 ------------------------------------
 |  |   |   |   |   |   |   |   |   ---->
 ------------------------------------

 
 Properties of a Vector.
 
 1. Fast insert/ remove at the end: O(1)
 2. Slow insert/ remove at the beginning or in the middle : O(n)
 3. Slow search: O(n)
 4. Allows random access.
 
 */

/*
 

 
 DEQUE
 
     --------------------------------
<---- |  |   |   |   |   |   |   |   |   ---->
     --------------------------------

 
 BOTH VECTOR AND DEQUE HAS SIMILAR INTERFACES. 
 BIG DIFFERENCE BETWEEN 2 IS VECTOR CAN GROW ONLY AT THE END. 
 DEQUE CAN GROW BOTH AT THE END AND AT THE BEGINNING.
 
 

 A deque is somewhat recursively defined: internally it maintains a double-ended queue of chunks (“blocks” in the graphic below) of fixed size. Each chunk is a vector, and the queue (“map” in the graphic below) of chunks itself is also a vector.
 
 
 https://i.stack.imgur.com/QullW.png
 
 
 Properties of a Deque.
 
 1. Fast insert/ remove at the end and BEGINNING: O(1)
 2. Slow insert/ remove in the middle : O(n)
 3. Slow search: O(n)
 4. Allows random access.
 
 */


/*
 
 LIST
 
 
    --> |   |--> |  | --> |  | -->
    <-- |   |<-- |  | <-- |  | <--
 
    - 2 pointers, one to item at begin, and next

Properties of List.
 
1. Fast insert and fast remove, at front, back middle!! 0(1)
2. slow search : O(n), this is even more slower than vector!  
 (even though both vector and list have O(n) search). Because of locality. Comutation power of modern processors is dominated by the memory access, that is why we use cache. As we said, vector stores data in the contiguous memory locations, and thus when we swap that chunk of memory in the cache, it is more likely tht you   use every thing in the cache and you get a lot of cache hits! While in the list, you will face a lot of cache misses.
 
 
 Also, list will consume more memory than a corresponding vector (because of pointers). And more memory means more cache misses. Thus LIST IN GENERAL IS SLOW!!!

 
3. no random access, no [] operator

 BESIDES ALL THESE, there is a method in list, which no other container can match!! (splice)
 
 */

/*

 Forward List
 
 --> |   |--> |  | --> |  | -->
     |   |    |  |     |  |
 only next pointers. No prev pointers
 
 */


/*
 Array
 
 very thin layer around the native array.
 
 2 BIG Problems with array container -
  1. Size cannot be changed
  2. 2 Array of integer may have different types.
  array<int, 3> is different type than array<int, 4>.
  thus if I define a function which takes the array of 3 elements, won't take the array of 4 elements.
 
 
 
 */


/*
 
 ASSOCIATIVE CONTAINERS 
 
 1. Set or Multiset
 2. Map or Multimap
 
 Associative containers are implemented in the form of a TREE.
 
 Elements in the ASSOCIATIVE Container are sorted based on certain criteria.
 
 Default criteria is <
 
 NO push_back() or push_front() - Because the container is always sorted!!!!
 
 ASSOCIATIVE CONTAINERS ARE READ ONLY! YOU CANNT MODIFY THE ITEM AT A LOCATION POINTED BY ITERATOR.
 

 */

/*
SEQUENCE CONTAINERS DONT HAVE Find() member function.
*/


/*
 
 Multiset
  
 Multiset is a set that allows duplicate items.

 // set/ multiset: value of the elements cannot be modified.
// it is read only!
 *it = 10; // will give error!
 
 Properties:
 
 1. Fast Search : O(log(n))
 2. Traversing is slow : locality problem like list. Traversing is slow than vector or deque.
 3. No Random access.
 
 Multi set allows duplicate values! Thus insertion in the multiset is always successful.

*/

/*
 Map and Multi Map -
 
 Have same interface as set and multiset. Except that map and multi map has every element as a key and a value pair.
 
 Map doesnt allow elements with duplicate keys.
 

 */

/*
 
 Name associative actually came from a map, where a value is actually associated with a key.
 
 for set you can think of as a key of each element as a value of each element. This is why they are all called associative containers.
 
 */

/*
 Unordered Associative containers. (C++ 11)
 
 Unordered set/ multiset
 
 Unordered map/ multimap
 
 Order of elemts is not defined.
 
 HashTable  -> Array (array of buckets) of linkedlist 
 
 
 Property - 
 
 Fastest Find/ Insert among all the containers
 

 */

/*
 
 unordered multiset : unordered set tht allows duplicated elements
 unordered map : unordered set of pairs
 unordered multimap : unordered map that allows duplicate keys
 
 hash collision =>performance degradation
 
 
 Properties :
 
 1. Fastest search/ insert at any place: O(1)
    Associative Containers takes O(log(n))
    Vector Deq, = O(n)
    list takes O(1) to insert, O(n) to search
 
 2. Unordered set/ multiset: element value cannot be changed
    Unordered map/ multimap: element key cannot be changed
 
 Because of change VALUE (in set/ multiset) will corrupt the database
 Because of change KEY (in map/ multimap) will corrupt the database
 
 */

/*
 
 Associative Array -
1. Search time : unordered_map, O(1); map O(log(n))
2. Unordered_map may degrade to O(n)
3. Can't use multimap and unordered_multimap, they dont have [] ooperator
 
 */

/*
 
 Container Adaptor
 
 - provide a restricted interface to meet special needs
 
 1. stack: LIFO, push(), pop(), top()
 2. queue: FIFO, push(), pop(), front(), back()
 3. priority qurur: first item always has a greatest priority
    - push(), pop(), top()
 
 */

/*
 
 Another way of categrizing containers
 
 1. Array based containers : vector, deque
 2. Node based containers : list + associative containers + unordered containers
 
 Array based containers invalidates pointers:
 - native pointers, iterators, references

 vector<int> vec = {1,2,3};
 int* p = &vec[2]; // p points to 3
 vec.insert(vec.begin(), 0);
 cout << *p << endl; // 2 or undefined behavior, or program may crash.
 
 
 */


#endif /* STLContainters_hpp */





















































