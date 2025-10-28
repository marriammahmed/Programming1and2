#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class x
{
public:
    x(){}
    ~x(){}
    x(const x& obj)
    {
        cout<<"deep copy"<<endl;
    }
    
    x& operator=(const x& obj)
    {
        cout<<"deep copy_1"<<endl;
        return *this;
    }
};

template<typename T>
void swapFunc(T&& obj1, T&& obj2)
{
    T tmp= obj1;
    obj1= obj2;
    obj2 = tmp;
}

x func()
{
    x obj;
    return obj;// TEMPORARY VALUE HAS NO PLACE IN MEMORY, returns an r value
}

int main()
{
    //vector<x> vect;
    // vect.pushback(x());
    
    //x obj1, obj2;
    
    x a1, a2;
    a1= func();
    a2= func();
    //swapFunc(func(),func());
    swapFunc(a1,a2);
    return 0;
}
