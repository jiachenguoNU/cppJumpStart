#include<iostream>
using namespace std;


template<typename T>
class IntArray{
    public:
    
    IntArray(size_t size); //{};//cannot add these brackets here;
    ~IntArray(); //cannot define twice if using inline

    IntArray(IntArray& A);//{}; cannot add these brackets here  //copy constructor

    T& operator[](size_t index); //cannot define twice if using inline
    size_t size();
    
    private:
    
    T* data_;
    size_t size_;
};

template<typename T>
inline IntArray<T>::IntArray(size_t size){
    data_ = new T[size];
    cout <<"constructor called" << "\n";
    size_ = size;
    for (size_t i{0}; i<size; i++){
        data_[i] = static_cast<T>(i);
    }
}

template<typename T>
inline IntArray<T>::~IntArray(){delete [] data_; cout << "destructor called"<<"\n";}


template<typename T>
inline T& IntArray<T>::operator[](size_t index){return data_[index];}


template<typename T>
size_t IntArray<T>::size(){return size_;}


int main(){

    IntArray<double> A(100);

    double A50{A[49]};

    size_t size0{A.size()};

    cout<< "A 50: "<< A50 <<" size: "<< size0<<"\n";


    return 0;
}
