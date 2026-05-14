#include<iostream>

template<typename T>
T min(T x, T y){
    std::cout<<"called template \n";
    return (x < y) ? x : y;
}


//template specialize
template<>
float min<float>(float A, float B){
    std::cout<<"called special \n";
    return A;
}

int main(){
    auto p{min(0.5, 6.0)};
    auto q{min(static_cast<float>(0.5), static_cast<float>(6.0))};
    std::cout<<p<<"\n"<<q<<"\n";
    return p;
}