#include <iostream>

class LeetCode{

private:
    int totalNum;

public:

    LeetCode(const int Num): totalNum(Num){
        std::cout<<"constructor \n";
    }

    virtual ~LeetCode(){std::cout<<"destructor \n";}

    virtual double progress(const int finished) const {
        return (double)finished/(double)totalNum;
    }

    int getter(){return totalNum;}

};

class NeetCode: public LeetCode{

    
    public:

    NeetCode(int total):LeetCode(total){
        std::cout<<"must initalize base since this is inheritance \n";
    } //can only set default if base is default value

    int totalNum0 = getter();
    double progress (const int finished) const override{
        std::cout<<"overrided \n";
        return 2* (double)finished/(double)totalNum0;
    } 

};


int main(){


    //用指针实现多态
    LeetCode* LC = new NeetCode(500); 


    auto currentProgress = LC->progress(20);
    std::cout<<"current progress via ptr "<<currentProgress <<"\n";
    

    //用引用实现多态
    LeetCode& ref = *LC;
    auto currentProgress2 = ref.progress(40);
    std::cout<<"current progress via ref "<<currentProgress2 <<"\n";

    //必须释放内存
    delete LC;

}