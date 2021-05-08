//
//  main.cpp
//  learn_c++
//
//  Created by Wung Jae Lee on 5/8/21.
//

#include <iostream>
#include "header1.h"
#include "header2.h"

namespace header1 {
int func() {
    foo();
    header2::foo();
    return 1;
}
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::cout << header1::func() << std::endl;
    return 0;
}
