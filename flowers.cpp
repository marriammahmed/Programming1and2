#include <iostream>
#include <string>
#include <vector>
using namespace std;


class flowers{
protected:
    int num;
    int color;
    float price;
public:
    flowers(int c, int n): color(c),num(n){
        if(num==0){
            cout<<"ERROR! reference number cannot be 0."<<endl;
        }
    }
    virtual void display()const{
        if(color==5){
            cout<<"Color: Red, Reference: "<<num<<endl;
        }
        else if(color==1){
            cout<<"Color: White, Reference: "<<num<<endl;

        }
        else if(color==2){
            cout<<"Color: yellow, Reference: "<<num<<endl;

        }
    

    }
    virtual int calc() {
        price= 2.167*color;
        cout<<"Price: $"<<price<<endl;
        return price;
      
    }
    virtual ~flowers(){};
};


class roses: public flowers{
private:
    int origin;
public:
    roses( int c,int n, int o): flowers(c,n), origin(o){}
    
    
    virtual void display()const{
        if(color==5){
            cout<<"Color: Red, Reference: "<<num<<endl;
        }
        else if(color==1){
            cout<<"Color: White, Reference: "<<num<<endl;

        }
        else if(color==2){
            cout<<"Color: yellow, Reference: "<<num<<endl;

        }

    }
    virtual int calc(){
        price= 2.167*origin;
        cout<<"Price: $"<<price<<endl;
        return price;
      
    }
    virtual ~roses(){};
};

class tulips: public flowers{
private:
    int duration;
public:
    tulips(int c, int n, int d): flowers(c,n), duration(d){}
    
    
    virtual void display()const{
        if(color==5){
            cout<<"Color: Red, Reference: "<<num<<endl;
        }
        else if(color==1){
            cout<<"Color: White, Reference: "<<num<<endl;

        }
        else if(color==2){
            cout<<"Color: yellow, Reference: "<<num<<endl;

        }
    }
    virtual int calc(){
        if(duration<5){
            price= color*1.5*5;
            cout<<"Price: "<<price<<endl;
        }
        else if(duration>=5){
            price= color*1.5*0.5;
            cout<<"Price: $"<<price<<endl;
        }
        return price;
    }
    virtual ~tulips(){};
};

int main(){
    vector<flowers*> bouqets;
    bouqets.push_back(new flowers(5,1));
    bouqets.push_back(new roses(1,2,5));
    bouqets.push_back(new tulips(2,3,6));

    
    for(int i=0; i<bouqets.size();i++){
        bouqets[i]-> display();
        bouqets[i]->calc();
    }
    cout<<endl;
    
    return 0;
}
