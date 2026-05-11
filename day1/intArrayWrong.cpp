#include <iostream>
#include <vector>


class IntArray {
public:
    IntArray(size_t size);  //constructor
        ~IntArray();            //destructor
            int& operator[](size_t index);       //operator overloading
                size_t size() const;                 //return size
                private:
                    int* data_;
                        size_t size_;
                        };

inline IntArray::IntArray(size_t size){
    int* data_ = new int[size];               //这里错了
    int i;
    for (i = 0; i < (int)size; i++){
        *(data_ + i ) = 0;
    size_ = size;                             //这里错了，要放在循环外边
    }
    
}

IntArray::~IntArray(){delete [] data_;}   //这里没有必要用inline，又不是头文件

inline int& IntArray::operator[](size_t index){
    return *(data_ + (int)index);         //这里应该用cpp地道的data_[index]
}


inline size_t IntArray::size() const{
    return size_;


}


int main(){

    IntArray array = IntArray(7);      //这里应该用cpp地道的IntArray array(8);

    size_t array_size = array.size();

    int ele2 = array[2];

    std::cout << ele2 << " " << array_size << "\n";

    return 0;


}
//错了，要用inline实现
// class IntArrayImplement{
// public:
//     IntArray(size_t size){
//         for (i = 0; i< (int)size, i++){

//         *(data_ + i) = 0;}
        
//         return data_;

//     };




// private: 
//     int* data_;
//     size_t size;
// };


