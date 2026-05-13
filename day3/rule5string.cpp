#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

class String{
private:
    char* str;
    size_t size;

public:
    //constructor
    explicit String(size_t size0){
        cout<<"constructor called \n";
        str = new char[size0] ; size = size0;
    }
    //destructor
    ~String(){
        cout<<"destructor called \n";
        delete [] str; str = nullptr; size = 0;  //delete syntax, only mention the first pointer
    }
    //copy const
    String(const String& string0){
        cout<<"copy constructor \n";
        size_t size0 = string0.size;
        char* str0 = string0.str;
        str = new char[size0];
        size = size0;
        for (size_t i{0}; i<size; ++i){
            str[i] = str0[i];
        }
    }

    //copy assign
    String& operator=(const String& string0){ //assignment operator
        cout<< "copy assign \n";
        char* str0 = string0.str;
        size_t size0 = string0.size;
        if (this == &string0){
            return *this;
        }

        //delete old str
        delete [] str;
        //create new string with the correct size
        size = size0;
        str = new char[size];
        copy(str0, size0 + str0, str);
        return *this;
    }                                   

    //move const
    String(String&& string0) noexcept {                 //加noexcept
        //move the new pointer to point
        cout<<"move construc \n";
        str = string0.str;
        size = string0.size;
        
        //default to 0
        string0.str = nullptr;
        string0.size = 0;

    }

    //move assign
    String& operator=(String&& string0) noexcept {      //加noexcept
        cout<<"move assign \n";
        
        if (this == &string0){
            return *this;
        }

        delete [] str;

        str = string0.str;
        size = string0.size;
        
        string0.str = nullptr;
        string0.size = 0;



        return *this;
    }


};



int main(){
    //constructor
    String A = String(8);

    
    //copy constructor
    String B(A);

    //move constructor
    String C(move(A));


    //copy assig
    String D = C;

    //move assig
    String E = move(D);




    return 0;
}