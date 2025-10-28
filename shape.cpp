#include <iostream>
#include <vector>
using namespace std;

int pi= 3.142;

class figure{
public:
    virtual void display()const{
        cout<<"I am a figure "<<endl;
    }
    virtual int perimeter()const=0;
    virtual int aire()const=0;
    virtual~figure(){}
};


class rectangle: public figure{
private:
    int length, width;
public:
    rectangle(int l, int w):length(l),width(w){}
    virtual void display()const override{
        cout<<"I am a ractangle "<<endl;
    }
    virtual int perimeter()const override{
        cout<<"perimeter of rectangle is: ";
        return( (2*length)+(2*width));
    }
    virtual int aire()const override{
        cout<<"area of rectangle is: ";
        return(length*width);

    }
    
    
};

class square: public figure{
private:
    int length;
public:
    square(int sl):length(sl){}
    virtual void display()const override{
        cout<<"I am a square "<<endl;
    }
    virtual int perimeter()const override{
    cout<<"perimeter of square is:";
     return(4*length);
     }
    virtual int aire()const override{
        cout<<"area of square is: ";
        return(length*length);
    }
    
    
};

class circle: public figure{
private:
    int radius;
public:
    circle(int r):radius(r){}
    virtual void display()const override{
        cout<<"I am a circle "<<endl;
    }
    virtual int perimeter()const override{
        cout<<"perimeter of circle is: ";
        return(2*pi*radius);
       
    }
    virtual int aire()const override{
        cout<<"area of circle is: ";
        return(pi*radius*radius);

    }
    
    
};

class triangle: public figure{
private:
    int base, height;
public:
    triangle(int b, int h):base(b),height(h){}
    virtual void display()const override{
        cout<<"I am a triangle "<<endl;
    }
    virtual int perimeter()const override{
       // int result= 4*l;
        cout<<"cannot calculate perimeter of triangle with the given info only";
        return 0;
    }
    virtual int aire()const override{
        cout<<"area of triangle is: ";
        return(base*height*0.5);
    }
    
    
};




int main(){
    vector<figure*> list;
    list.push_back(new rectangle(3,5));
    list.push_back(new square(7));
    list.push_back(new circle(6));
    list.push_back(new triangle(4,3));

    for(int i=0; i<list.size(); i++){
        list[i]->display();
       
    }
    cout<<endl;
    for(int i=0; i<list.size(); i++){
        cout<< list[i]->perimeter()<<endl;

    }
    cout<<endl;
    for(int i=0; i<list.size(); i++){
        cout<< list[i]->aire()<<endl;


    }
    
    cout<<endl;
    
    return 0;
}
