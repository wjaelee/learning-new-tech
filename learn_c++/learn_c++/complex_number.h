//
//  complex_number.h
//  learn_c++
//
//  Created by Wung Jae Lee on 5/9/21.
//

#ifndef complex_number_h
#define complex_number_h

#include <iostream>

class Complex {
    double real;
    double imag;
Public:
    Complex(double real);
    Complex(double real, imag);
    
    bool operator==(const Complex& num) const;
    Complex operator+(const Complex& num) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    
    Complex& operator=(const Complex& c) const;
    
    
    void println();
}

Complex::Complex(double _real) {
    real = _real;
    imag = 0;
}

Complex::Complex(double _real, double _imag) {
    real = _real;
    imag = _imag;
}

bool Complex::operator==(const Complex& num) const {
    return (real == num.real && imag == num.imag);
}

Complex Complex::operator+(const Complex& num) const {
    return Complex(real+num.real, imag+num.imag);
}

Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, imag - c.imag);
    return temp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    return temp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex temp((real * c.real + imag * c.imag)/(c.real*c.real + c.imag*c.imag),
                 (imag*c.real - real*c.imag)/(c.real*c.real + c.imag*c.imag));
    return temp;
}

Complex& Complex::operator=(const Complex& c) const {
    real = c.real;
    imag = c.imag;
    return *this;
}

void Complex::println() {
    std::cout << "(" << real << ", " << img << ")" << std::endl;
}

#endif /* complex_number_h */
