#include "overload.hpp"

int main(){
    int refA{7};
    Counter A{5, refA};
    A++;
    std::cout<<A.value <<" "<<A.ref<<"\n";
    ++A;
    std::cout<<A.value <<" "<<A.ref<<"\n";

    

    return 0;



}