#include <iostream>
#include <vector>


class IntArray {
public:
    IntArray(size_t size);  //constructor
    ~IntArray();            //destructor
    int& operator[](size_t index);       //operator overloading 注意这里的声明方式 int&
    size_t size() const;                 //return size
private:
    int* data_;
    size_t size_;
};

inline IntArray::IntArray(size_t size){
    data_ = new int[size];               //这里错了, 去掉声明 有声明的话等于新生成了一个
    int i;
    for (i = 0; i < static_cast<int>(size); i++){
        *(data_ + i ) = 0;
    
    }
    size_ = size;                        //之前写在循环里了

}

IntArray::~IntArray(){delete [] data_;}  //注意destructor这里是有括号的

int& IntArray::operator[](size_t index){
    return data_[index];                 //之前写成C style了
}


size_t IntArray::size() const{           //注意因为这里声明加了const，所以这里也得加
    return size_;


}


int main(){

    IntArray array(7);

    size_t array_size = array.size();

    int ele2 = array[2];

    std::cout << ele2 << " "<< array_size << "\n";

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


