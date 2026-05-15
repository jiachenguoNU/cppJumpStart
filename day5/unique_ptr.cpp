#include <iostream>
using namespace std;
template<typename T>
class UniquePtr{
    private:
    T* ptr_;

    public:
    //constructor
    explicit UniquePtr(T* ptr = nullptr) noexcept : ptr_{ptr}{cout<<"constructor \n";}
    //destructor
    ~UniquePtr(){delete [] ptr_;} //错了要手动清理;而且因为传入数组，所以必须加【】
    //forbid copy constructor and assignment
    UniquePtr(const UniquePtr& A) = delete;
    UniquePtr& operator=(const UniquePtr& A) = delete;

    //move constructor
    UniquePtr(UniquePtr&& other) noexcept {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    //move assignment. //assignment must return ref;
    UniquePtr& operator=(UniquePtr&& other) noexcept{
        if(this == &other){
            return *this;
        }


        delete ptr_; ///必须手动清理
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;

        return *this;
    }

    //dereference
    T& operator*() const{
        return *ptr_;
    }

    //pointer
    T* operator->() const{
        return ptr_;
    }

    //get
    T* get() const noexcept{
        return ptr_;
    }

    //release
    T* release() noexcept{
        T* old = ptr_;
        ptr_ = nullptr;
        return old;
    }

    //reset
    void reset(T* ptr = nullptr) noexcept{
        delete [] ptr_;   //这里也是的，因为删除list，所以得加括号
        ptr_ = ptr;
        // ptr = nullptr; //没有必要因为是引用传递
    }
};


int main(){ 
    UniquePtr<int> p1 {new int[8]};
    UniquePtr<int>p2 = move(p1);
    UniquePtr<int>p3(move(p1));
    UniquePtr p4 = move(p1);
    UniquePtr<int>p5 = move(p1);
    auto* ptr = p1.get();
    auto* pt2 = p4.release();
    cout<<&ptr << &pt2 << "\n"<<"\n";;
    p2.reset(new int[100]);
    return 0;
}