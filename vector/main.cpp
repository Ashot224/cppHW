#include <iostream>

template <typename T>
class Vector {
public:
    Vector() : arr_size(0), arr_capacity(1), arr(new T[arr_capacity]) {}

    explicit Vector(size_t arr_size) : arr_size(arr_size), arr_capacity(arr_size), arr(new T[arr_capacity]) {}

    Vector(size_t arr_size, T elem) : arr_size(arr_size), arr_capacity(arr_size), arr(new T[arr_capacity]) {
        for (int i = 0; i < arr_size; ++i) {
            arr[i] = elem;
        }
    }

    Vector(const Vector<T> &other) {
        arr_size = other.arr_size;
        arr_capacity = other.arr_capacity;
        arr = new T[arr_capacity];
        for (int i = 0; i < arr_size; ++i) {
            arr[i] = other.arr[i];
        }
}
  Vector(Vector<T> &&other){
        arr_size = other.arr_size;
        arr_capacity = other.arr_capacity;
        arr = other.arr;
        other.arr = nullptr;
    }


  ~Vector(){
        delete[] arr;
    }


  Vector<T> &operator=(const Vector<T> &other){
      arr_size = other.arr_size;
      arr_capacity = other.arr_capacity;
      arr = new T[arr_capacity];
      for (int i = 0; i < arr_size; ++i) {
          arr[i] = other.arr[i];
      }
      return *this;
    }
  Vector<T> &operator=(Vector<T> &&other){
      arr_size = other.arr_size;
      arr_capacity = other.arr_capacity;
      arr = other.arr;
      other.arr = nullptr;
      return *this;
    }

  size_t size() const{
      return arr_size;
    }
  size_t capacity() const{
      return arr_capacity;
    }

  bool empty() const{
      if (arr_size != 0){
          return false;
      }
      return true;
    }

  const T &operator[](size_t index) const{
      return arr[index];
    }
  T &operator[](size_t index){
      return arr[index];
    }

  const T &at(size_t index) const{
        if (index < arr_size){
            return arr[index];
        }
      return 0;
    }
  T &at(size_t index){
      if (index < arr_size){
          return arr[index];
      }
      return 0;
    }

  void push_back(const T &x){
      if (arr_capacity == arr_size){
          arr_capacity *= 2;
         T* newArr = new  T[arr_capacity];
         size_t i = 0;
         while (i < arr_size){
             newArr[i] = arr[i];
             ++i;
         }
         delete[] arr;
         arr = newArr;
      }
      arr[arr_size ++] = x;
    }
  void push_back(T &&x){
      if (arr_capacity == arr_size){
          arr_capacity *= 2;
          T* newArr = new  T[arr_capacity];
          size_t i = 0;
          while (i < arr_size){
              newArr[i] = arr[i];
              ++i;
          }
          delete[] arr;
          arr = newArr;
      }
      arr[arr_size ++] = std::move(x);
  }

  void pop_back(){
        arr_size --;
    }


  void clear(){
        arr_size = 0;
    }
private:
    size_t arr_size;
    size_t arr_capacity;
    T * arr;
};

template <typename T>
Vector<T> kartofil(const Vector<T> &nums){
    Vector<T> v1(nums.size(), 1);
    T temp = 1;
    T i = 0;
    while (i < nums.size()){
        v1[i] = temp;
        temp *= nums[i];
        ++i;
    }
    temp = 1;
    i = nums.size() - 1;
    while (i >= 0){
        v1[i] *= temp;
        temp *= nums[i];
        --i;
    }
    return v1;
}

int main() {

    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
    Vector<int> v3;
    v3 = kartofil(v2);
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v3[i] << std::endl;
    }
    return 0;
}
