#include<iostream>
using namespace std;

class IntArray{
    public:
    
    IntArray(size_t size); //{};//cannot add these brackets here;
    ~IntArray(); //cannot define twice if using inline

    IntArray(IntArray& A);//{}; cannot add these brackets here  //copy constructor

    IntArray(IntArray&& A);  //moving constructor


    int& operator[](size_t index); //cannot define twice if using inline
    size_t size();
    
    private:
    
    int* data_;
    size_t size_;
};


inline IntArray::IntArray(size_t size){
    data_ = new int[size];
    cout <<"constructor called" << "\n";
    size_ = size;
    for (size_t i{0}; i<size; i++){
        data_[i] = static_cast<float>(i);
    }
}

inline IntArray::~IntArray(){delete [] data_; cout << "destructor called"<<"\n";}



inline int& IntArray::operator[](size_t index){return data_[index];}

