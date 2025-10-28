#include <iostream>
#include <string>
using namespace std;

class visa{
private:
    int num;
    string bank;
public:
    visa(): num(0), bank("unknown"){}
    visa(int n=0, string b="unkown"): num(n), bank(b){}
    void display()const{
        cout<<"number: "<<num<<endl;
        cout<<"Bank: "<<bank<<endl;
    }
    bool inequal(const visa& obj)const{
        return!(num==obj.num);
    }
    ~visa(){}
    
};

class customer{
private:
    string first, last;
    visa card;
public:
    customer(): first("unknown"),last("unknown"),card(1234,"best bank"){}
    customer(string f="unknown", string l="unkown",int n=0, string b="best bank"): first(f),last(l),card(n,b){}
    void display()const{
        cout<<"First: "<<first<<endl<<"Last: "<<last<<endl;
        cout<<"VISA ID: ";
        card.display();
    }
    bool compare(const customer& obj)const{
        return(first== obj.first&& last== obj.last);
    }
    bool check(const customer& obj) const{
        return( card.inequal(obj.card));
    }
   
};

bool operator==(const customer& a, const customer& b){
    if(a.compare(b)){
        cout<<"Warning! same first and last name"<<endl;
        return true;
    }
    return false;
}
bool operator!=(const customer& a, const customer& b){
    if(a.check(b)){
        cout<<"different ID of customers"<<endl;
        return true;
    }
    return false;
}



int main(){
    
    customer customer1("John","Doe",123456789,"A");
    customer customer2("John","Doe",987654321,"B");
    
    cout<<"customer 1 info: "<<endl;
    customer1.display();
    cout<<endl;
    
    cout<<"customer 2 info: "<<endl;
    customer2.display();
    cout<<endl;

    
    if(customer1== customer2){
        cout<<"WARNING CUSTOMERS HAVE SAME NAME"<<endl;
    }
    cout<<endl;

    
    if(customer1 != customer2){
        cout<<"WARNING CUSTOMERS HAVE DIFFERENT ID NUMBERS"<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    
    
    
    
    return 0;
}
