#include"ruleOfThree.hpp" //double quotes mean local header file

int main(){

    cout<<"rule of three" <<"\n";
    IntArray A(size_t(10));
    auto B{A};
    cout<<B[2]<<"\n";
    IntArray C(move(A));
    // if (not A.data_){
    //     cout<<"nullptr \n";
    }
