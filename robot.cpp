#include <iostream>
#include<string>
using namespace std;

class arm{
private:
    string side;
    int length;
public:
    arm():side("r"), length(60){}
    arm(string side, int l=60):side(side), length(l){}
    void display()const{
        cout<<"side is: "<<side<<endl;
        cout<<"length is: "<<length<<endl;
    }
    bool equal(const arm& obj)const{
        return(length==obj.length);
    }
    int add(arm& obj){
        return(length+=obj.length);
    }
    ~ arm(){}
};

class robot{
private:
    string name, design;
    arm arm1, arm2;
public:
    robot():name("robot_NAO"), design("basic"),arm1("r", 60), arm2("l",60) {}
    robot(string n, string d, arm first, arm second):name(n), design(d),arm1(first), arm2(second) {}
    void display()const{
        cout<<"name is: "<<name<<endl;
        cout<<"design is: "<<design<<endl;
        cout<<"arm1 side and length";
        arm1.display();
        cout<<"arm2 side and length";
        arm2.display();
        
    }
    
    bool check(const robot& obj) const{
        return(arm1.equal(obj.arm1)&&arm2.equal(obj.arm2));
    }
    
    
};

bool operator==(const robot& a, const robot& b){
    return(a.check(b));
}

arm operator+=(arm& a, arm& b){
    a.add(b);
    return a;
}

int main(){
    arm right1("r",60);
    arm left1("L",60);
    robot robot1("robot1", "advanced", right1, left1);
    
    arm right2("r",60);
    arm left2("L",60);
    robot robot2("robot2", "advanced", right2, left2);
    
    
    cout<<"robot 1 info"<<endl;
    robot1.display();
    cout<<endl;
    
    cout<<"robot 2 info"<<endl;
    robot2.display();
    cout<<endl;
    
    if(robot1==robot2){
        cout<<"warning! robots have equal arm lengths "<<endl;
    }
    
    right1.display();
    right1+=left1;
    right1.display();
    
    
    return 0;
}
