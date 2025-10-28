#include <iostream>
#include <string>
using namespace std;

class flower{
private:
    string type, color;
public:
    flower():type("rose"),color("white"){}
    flower(string t, string c):type(t),color(c){}
    void display()const{
        cout<<"Flower Type: "<<type<<", "<<"Color: "<<color<<endl;
    }
    bool compare(const flower& obj)const{
        return(type== obj.type && color==obj.color);
    }
};

bool operator!=(const flower& f1, const flower& f2)
    {
        return!(f1.compare(f2));
    }
    
bool operator==(const flower& f1, const flower& f2)
        {
            return(f1.compare(f2));
        }
 

class vase{
private:
    string name, color;
    int size;
    flower* flowersarray;
public:
    vase():name("Classic"), color("white"), size(20), flowersarray( new flower[15]){
        for(int i=0; i<15; i++)
        {
            flowersarray[i]=flower("rose","white");
        }
    }
        
    vase( string n, string c, int s, flower* ar):name(n), color(c), size(s), flowersarray( new flower [s]){
        for(int i=0; i<s; i++)
        {
            flowersarray[i]=ar[i];
        }
    }
    
    vase(const vase& obj):name(obj.name), color(obj.color), size(obj.size), flowersarray( new flower[obj.size]){
        for(int i=0; i<15; i++)
        {
            flowersarray[i]= obj.flowersarray[i];
        }
    }
    vase& operator==(const vase& obj){
        if(this!= &obj){
            delete[] flowersarray;
            name=obj.name;
            color=obj.color;
            size= obj.size;
            for(int i=0; i<size;i++)
            {
                flowersarray[i]= obj.flowersarray[i];
            }
        }
        return* this;
    }
    
    void display() const{
        cout<<"Vase Design: "<< name<<" , "<<"Color: "<< color<< " , "<<"Size: "<<size<<endl;
        cout<<"Flowers in the vase: "<<endl;
        for(int i=0; i<15; i++)
        {
            flowersarray[i].display();
        }
        
    }
    ~vase() {
        delete[] flowersarray;
    }
    };

int main() {
    flower whiteRoses[15];
    vase classicVase;
    flower specialFlowers[15];
    vase specialVase("Special Design", "Red", 25, specialFlowers);
    vase copiedVase = specialVase;
    vase assignedVase;
    assignedVase = classicVase;
    classicVase.display();
    specialVase.display();
    copiedVase.display();
    assignedVase.display();
return 0; }
