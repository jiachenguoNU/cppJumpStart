#include <iostream>

template<typename T, typename V>
class LeetCode{
    private: T num_target; T current_finished; V progress;

    public:

    LeetCode(T finished, T total): current_finished(finished), num_target(total), progress(0.7){
        std::cout<<"constructed \n";
    }

    V reportProgress();

    V reportProgress0(V progress_ideal){
        return current_finished/num_target + progress_ideal;
    }


};

// template<typename T, typename V>//wrong syntax
template<typename T, typename V>
V LeetCode<T, V>::reportProgress(){
    return current_finished/num_target;
}


int main(){
    LeetCode<double, double> may13{10, 450};

    auto progress = may13.reportProgress();
    std::cout<<"current progress "<<progress<<" \n";

    auto progress_new = may13.reportProgress0(0.7);

    std::cout<<"progress ideal "<<progress_new<<"\n";

    return 0;
}