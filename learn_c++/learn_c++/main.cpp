//
//  main.cpp
//  learn_c++
//
//  Created by Wung Jae Lee on 5/8/21.
//

#include <iostream>
#include <string>
#include "header1.h"
#include "header2.h"
#include "MyString.h"
#include "vector.h"
#include <thread>
using namespace header1;
using header1::foo;

namespace header1 {
int func() {
    foo();
    header2::foo();
    return 1;
}
}


void func1() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 1 in work!\n";
    }
}

void func2() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 2 in work!\n";
    }
}
void func3() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 3 in work!\n";
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
    
    /* reference */
    /*
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
     */
    
    /*
    MyString s('a');
    std::cout << s.length() << std::endl;
    
    MyString s2("hello my name is wungjae");
    std::cout << s2.length() << std::endl;
    s2.println();
    
    MyString s3(s2);
    s3.println();
    std::cout << s3.length() << std::endl;
    */
    
    /*
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(4);
    
    std::cout << "------ int vector -------" << std::endl;
    std::cout << int_vec[0] << std::endl;
    std::cout << int_vec[1] << std::endl;
    
    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    
    std::cout << "------ str vector -------" << std::endl;
    std::cout << str_vec[0] << std::endl;
    std::cout << str_vec[1] << std::endl;
    */
    
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);
    
    t1.join(); // return after finishing execution
    t2.join();
    t3.join();
    return 0;
}
