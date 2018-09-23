//
//  Template.cpp
//  C++Practice
//
//  Created by Komal Gujarathi on 9/22/18.
//  Copyright © 2018 Komal Gujarathi. All rights reserved.
//

#include "Template.hpp"
#include <iostream>
#if 0
int main()
{
    
    // Good thing about function template is that its time is infered by the compiler implicitly.
    // You dont have to specify any parameters to the function template. This is not true with the Class Template.
    // For class template, compiler cannot invoke the type of the parameter implicitly. You should provide the
    // type of the parameter to the Class Template.
    
    std::cout << square(5)<< std::endl;
    std::cout << square(3.5)<< std::endl;
    std::cout << square<int>(2)<< std::endl;
    std::cout << square<double>(12.5)<< std::endl;
    
    BoVector<int> bv;
    bv.push(1);
    bv.push(2);
    bv.push(3);
    bv.push(4);
    
    std::cout << bv.get(2) << std::endl;
    std::cout << bv.getSize() << std::endl;
    
    bv.print();
    
    std::cout << "Passing the Object type as a template parameter :" << std::endl;
    
    BoVector<int> res = square(bv);
    res.print();
    return 0;
}

#endif