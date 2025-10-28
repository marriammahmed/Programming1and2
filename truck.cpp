#include <iostream>
#include <vector>
using namespace std;

class vehicle
{
protected:
    int price, doors, year;
public:
    vehicle(int p=0, int d=0, int y=0):price(p), doors(d), year(y){}
    ~vehicle(){}
};

class car: public vehicle
{
public:
    car(int p, int d, int y):vehicle(p,d,y){}
    void display()const{
        cout<<"car price: "<<price<<endl<<"car doors: "<<doors;
    }
    
};


class moto: public vehicle
{
public:
    moto(int p, int d, int y):vehicle(p,d){}
    void display()const{
        cout<<"moto price: "<<price<<endl<<"moto doors: "<<doors;
    }
    
};

class truck: public vehicle
{
private:
    int weight;
public:
    truck(int p, int d, int w, int y):vehicle(p,d,y), weight(w){}
    void display()const{
        cout<<"truck price: "<<price<<endl<<"truck doors: "<<doors;
    }
    
};

class garage{
private:
    vector<vehicle*> listvehicles;
public:
    garage(){}
    void add(vehicle& obj){
        listvehicles.pushback(obj.price, obj.doors, obj.year);
    }
    
    
};

int main()
{
    
    
    
    
    
    
    return 0;
}
