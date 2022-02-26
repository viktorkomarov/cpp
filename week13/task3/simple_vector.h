#pragma once

#include <cstdlib>
#include <cstring>
#include <iostream>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector(){};
  explicit SimpleVector(size_t size):data(new T[size]()), size_(size), cap_(size){}

  ~SimpleVector(){delete[] data;}

  T& operator[](size_t index) {return data[index];}

  T* begin(){return data;}
  T* end(){return data+size_;};

  const T* begin()const {return data;}
  const T* end()const {return data+size_;};

  size_t Size() const {return size_;}
  size_t Capacity() const {return cap_;}
  void PushBack(const T& value){
    if(size_ == cap_){
      cap_ = (size_ == 0) ? 1 : cap_ * 2;
      T* n_mem = new T[cap_]();
      for(size_t i = 0; i < size_; ++i) n_mem[i] = data[i];
      delete[] data;
      data  = n_mem;
    }
    data[size_++] = value;
  };

private:
  T* data = nullptr;
  size_t size_ = 0;
  size_t cap_ = 0;
};
