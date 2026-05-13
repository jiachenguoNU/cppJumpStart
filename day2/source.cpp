#include "ruleOfThree.hpp"

size_t IntArray::size(){return size_;}

IntArray::IntArray(IntArray&A){   //deep copy
    
    cout<<"copy constructor called"<<"\n";
    size_t size_new = A.size();
    data_ = new int[size_new];

    for (size_t i = 0; i < size_new; i++){

        data_[i]= A[i];
    }

}

IntArray::IntArray(IntArray&& A){
    cout<<"move constructor called \n";
    data_ = A.data_;
    size_ = A.size();
    A.data_ = nullptr;
    A.size_ = 0;
}