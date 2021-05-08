//
//  main.cpp
//  learn_c++
//
//  Created by Wung Jae Lee on 5/8/21.
//

#include <iostream>
#include "header1.h"
#include "header2.h"
using namespace header1;
using header1::foo;

namespace header1 {
int func() {
    foo();
    header2::foo();
    return 1;
}
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /* namespace */
    /*
    std::cout << "Hello, World!\n";
    std::cout << header1::func() << std::endl;
    std::cout << func() << std::endl;
    std::cout << foo() << std::endl;
    std::cout << header2::foo() << std::endl;
     */
    
    int a = 3;
    int& another_a = a;
    
    another_a = 5;
    std::cout << "a: " << a << std::endl;
    std::cout << "another_a: " << another_a << std::endl;
    
    // int& ref = 4; // this is not valid
    const int& ref2 = 4; // this is okay
    
    int arr[3] = { 1, 2, 3 };
    int(&ref)[3] = arr;
    
    ref[0] = 2;
    ref[1] = 3;
    ref[2] = 1;
    
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}
