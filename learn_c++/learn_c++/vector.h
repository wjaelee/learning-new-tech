//
//  vector.h
//  learn_c++
//
//  Created by Wung Jae Lee on 5/9/21.
//

#ifndef vector_h
#define vector_h

//template <class T>  // this works the same
template <typename T> // this is preferred
class Vector {
    T* data;
    int capacity;
    int length;
public:
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}
    
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity*2];
            for (int i = 0; i < length; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[length] = s;
        length++;
    }
    
    T operator[](int i) { return data[i]; };
    
    void remove(int i) {
        for (int j = i+1; j < length; ++j) {
            data[j-1] = data[j];
        }
        length--;
    }
    
    int size() { return length; }
    
    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

// template specialization
template <>
class Vector<bool> {
    unsigned int* data;
    int capacity;
    int length;
    
public:
    typedef bool value_type;
    
    Vector(int n = 1)
    : data(new unsigned int[n/32 + 1]), capacity(n/32 + 1), length(0) {
        for (int i = 0; i < capacity; ++i) {
            data[i] = 0;
        }
    }
    
    void push_back(bool s) {
        if (capacity * 32 <= length) {
            unsigned int* temp = new unsigned int[capacity*2];
            for (int i = 0; i < capacity; ++i) {
                temp[i] = data[i];
            }
            for (int i = capacity; i < 2*capacity; ++i) {
                temp[i] = 0;
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        if (s) {
            data[length/32] |= (1 << (length % 32));
        }
        length++;
    }
};

#endif /* vector_h */
