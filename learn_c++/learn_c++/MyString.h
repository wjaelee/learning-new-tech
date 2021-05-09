//
//  MyString.h
//  learn_c++
//
//  Created by Wung Jae Lee on 5/9/21.
//

#ifndef MyString_h
#define MyString_h


class MyString {
    char* content;
    size_t string_length;
    size_t memory_capacity;
public:
    MyString(char c);
    MyString(const char* c);
    MyString(const MyString& str);
    ~MyString();
    
    size_t length() const;
    void print() const;
    void println() const;
    MyString& assign(const char* str);
    MyString& assign(const MyString& str);
    size_t capacity() const;
    void reserve(int size);
    char at(int i) const;
    
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
    
    MyString& erase(int loc, int num);
    
    bool contain(const char* c);
    int equal(MyString& s);
    int less_than(MyString& s);
};

MyString::MyString(char c) {
    content = new char[1];
    string_length = 1;
    memory_capacity = 1;
    content[0] = c;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    content = new char[string_length];
    memory_capacity = string_length;
    for (int i = 0; i < string_length; ++i)
        content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    content = new char[string_length];
    memory_capacity = string_length;
    for (int i = 0; i < string_length; ++i)
        content[i] = str.content[i];
}

MyString::~MyString() {
    delete[] content;
}

size_t MyString::length() const {
    return string_length;
}

void MyString::print() const {
    for (int i = 0; i < string_length; ++i)
        std::cout << content[i];
}

void MyString::println() const {
    for (int i = 0; i < string_length; ++i)
        std::cout << content[i];
    std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        delete[] content;
        content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    string_length = str.string_length;
    for (int i = 0; i < string_length; ++i)
        content[i] = str.content[i];
    
    return *this;
}
MyString& MyString::assign(const char* str) {
    size_t str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] content;
        content = new char[str_length];
        memory_capacity = str_length;
    }
    string_length = str_length;
    
    for (int i = 0; i < string_length; ++i)
        content[i] = str[i];
    return *this;
}

size_t MyString::capacity() const{
    return memory_capacity;
}

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_content = content;
        
        content = new char[size];
        memory_capacity = size;
        
        for (int i = 0; i < string_length; ++i)
            content[i] = prev_content[i];
        
        delete[] prev_content;
    }
}

char MyString::at(int i) const{
    if (i >= string_length || i < 0)
        return NULL;
    return content[i];
}

/*
 012345
 abcdef
   ^
   ghi
 abghicdef
 
 new_length = string_length + strlen(str)
 for i  string_length-1:loc
 content[i+
 */
MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > string_length)
        return *this;
    
    size_t new_length = string_length + str.string_length;
    if (new_length > memory_capacity) {
        if (new_length < memory_capacity * 2)
            memory_capacity *= 2;
        else
            memory_capacity = new_length;
        
        char* prev_content = content;
        content = new char[memory_capacity];
        
        int i = 0;
        for (i = 0; i < loc; ++i)
            content[i] = prev_content[i];
        for (int j = 0; j < str.string_length; ++j) {
            content[i+j] = str.content[j];
        }
        for (; i < string_length; ++i) {
            content[i+str.string_length] = prev_content[i];
        }
        
        delete[] prev_content;
        string_length = new_length;
        return *this;
    }
    for (size_t i = string_length-1; i >= loc; --i) {
        content[i+str.string_length] = content[i];
    }
    for (size_t j = 0; j < str.string_length; ++j) {
        content[loc + j] = str.content[j];
    }
    string_length = new_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    if (num < 0 || loc < 0 || loc > string_length || loc+num >= string_length)
        return *this;
    for (int i = loc+num; i < string_length; ++i) {
        content[i-num] = content[i];
    }
    string_length -= num;
    return *this;
}

#endif /* MyString_h */
