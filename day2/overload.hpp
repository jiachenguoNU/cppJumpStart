#include<iostream>


struct Counter{
    int value; int& ref;
    // Counter(int a, int b): value(a), ref(b){std::cout << "initialized \n";} //member init list //这里也错了，这里初始化参数是int b的话出栈就被销毁，变成dangling ref
    Counter(int a, int& b): value(a), ref{b}{};
    // int& operator++(){  //wrong, the output should be struct
    //     return value++;
    // }


    Counter& operator++(){
        value++;
        ref++;
        return *this;

    }

    // Counter& operator++(int){   //错误，必须按照值返回，不能是引用
    //     Counter old_ref = *this;
    //     value++;
    //     ref++;
    //     return old_ref;
    // }

    Counter operator++(int){   //所以++i 比i++ 快
        Counter old_ref = *this;
        value++;
        ref++;
        return old_ref;
    }

};