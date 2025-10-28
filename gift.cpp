#include <iostream>
#include <string>
#include <vector>
using namespace std;

class gift{
private:
    string size;
public:
    gift(): size("small"){}
    void display() const{
        cout<<"Gift category: "<< size<<endl;
    }
    ~gift(){}
};

class watch{
protected:
    int num;
    float price;
    gift* gptr;
public:
    //watch():gptr(nullptr){}
    watch(int n, float p, gift* myptr): num(n), price(p), gptr(myptr){    }
    watch(const watch& obj){
        if(this!=&obj)
        {
            delete[]gptr;
        }
        if(obj.gptr)
        {
            num= obj.num;
            price= obj.price;
            gptr= new gift(*obj.gptr);
        }
    }
    
    virtual void display() const{
        cout<<"reference: "<<num<<" price: "<<price<<endl;
        gptr->display();
        
    }
    virtual float calc()const {
        float vat;
        vat= price*1.02;
        return vat;
    }
    ~watch(){delete gptr;}
};


class kids: public watch{
private:
    int size;
public:
    kids(int num, float price, gift* myptr):watch(num, price, myptr){}
    virtual void display() const override{
      watch::display();

    }
    virtual float calc() const override{
        float vat;
        vat= price*1.1;
        cout<<"price after VAT: "<<vat<<endl;
        return vat;
    }
    ~ kids(){}
};


class luxury: public watch{
private:
    string material, brand;
public:
    luxury(int num, float price, gift* myptr, string m, string b):watch(num, price, myptr), material(m), brand(b){}
    virtual void display() const override{
      watch::display();
        cout<<"Material: "<< material<<"Brand: "<<brand<<endl;
  
    }
    virtual float calc() const override{
        float vat;
        vat= price*1.2;
        cout<<"price after VAT: "<<vat<<endl;
        return vat;
    }
    ~ luxury(){}
};

int main(){

    vector<watch*> list;
    gift* gift1=new gift();
    gift* gift2=new gift();
    gift* gift3=new gift();

    
   list.push_back(new kids(101,50.0, gift1));
   list.push_back(new luxury(201,500.0, gift2,"gold ","rolex"));
   list.push_back(new kids(102,60.0, gift3));

    for(int i=0; i<list.size();i++){
        list[i]->display();
        list[i]-> calc();
        cout<<endl;

    }
    cout<<endl;
    cout<<endl;

    
    for(int i=0; i<list.size();i++){
        delete list[i];
    }
    
    
    return 0;
}
