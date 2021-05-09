//
//  thread_practice.h
//  learn_c++
//
//  Created by Wung Jae Lee on 5/9/21.
//

#ifndef thread_practice_h
#define thread_practice_h

#include <thread>
#include <iostream>
using std::thread;

void func1() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 1 in work!" << std::endl;
    }
}

void func2() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 2 in work!" << std::endl;
    }
}
void func3() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "thread 3 in work!" << std::endl;
    }
}

int main() {
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    
    t1.join();
    t2.join();
    t3.join();
}

#endif /* thread_practice_h */
