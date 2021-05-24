#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

namespace mystd {

template<typename T>
class vector {
  private:
    T* arr;
    int capacity_;
    int size_;
  public:
    vector(void) {
      arr = new T[1];
      capacity_ = 1;
      size_ = 0;
    }

    vector(int n) {
      arr = new T[n];
      capacity_ = n;
      size_ = 0;
    }

    vector(const vector& v) {
      capacity_ = v.capacity_;
      size_ = v.size_;
      arr = new T[capacity_];
      for (int i = 0; i < size_; ++i) {
        arr[i] = v.arr[i];
      }
    }

    ~vector() {
      delete[] arr;
    }

    vector& operator=(const vector& v) {
      delete[] arr;
      arr = new T[v.capacity_];
      size_ = v.size_;
      capacity_ = v.capacity_;
      for (int i = 0; i < v.size_; ++i) {
        arr[i] = v.arr[i];
      }
      return *this;
    }

    int length() {
      return size_;
    }

    int capacity() {
      return capacity_;
    }

    void reserve(int n) {
      T* temp = arr;
      arr = new T[n];
      capacity_ = n;
      for (int i = 0; i < size_; ++i) {
        arr[i] = temp[i];
      }
      delete[] temp;
    }

    void push_back(T elem) {
      if (size_ + 1 > capacity_) {
        this->reserve(2*capacity_);
      }

      arr[size_] = elem;
      size_++;
    }

    void pop_back() {
      if (size_ == 0)
        return;
      size_--;
    }

    bool empty() {
      return size_ == 0;
    }

    T at(int idx) {
      if (idx < 0 || idx >= size_) {
        throw std::out_of_range("index out of range");
      }
      return arr[idx];
    }

    T operator[](int idx) {
      return arr[idx];
    }
};

}

#endif
