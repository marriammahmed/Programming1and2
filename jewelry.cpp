#include <iostream>
#include <string>
#include <vector>
using namespace std;

class box{
    private:
    string type, color;
    public:
        box():type("unkown"),color("unknown"){}
        box(string t, string c):type(t),color(c){}
       virtual void displayBoxInformation()const{
            cout<<"Box type: "<<type<<", Color: "<<color<<endl;
        }
    ~box(){};
};

template<typename nametype, typename pricetype>
class Piece_of_jewelry{
  protected:
    nametype designer;
    pricetype price;
    string material;
    double weight;
    box* jewbox;
  public:
    Piece_of_jewelry():designer(),price(),material("unkown"),weight(0),jewbox(nullptr){}
    Piece_of_jewelry(nametype d, pricetype p, string m, float w, box* x):designer(d),price(p),material(m),weight(w),jewbox(x){}
    Piece_of_jewelry(const Piece_of_jewelry& obj):designer(obj.designer),price(obj.price),material(obj.material),weight(obj.weight),jewbox(new box(*obj.jewbox)) {}
    
    Piece_of_jewelry& operator=(const  Piece_of_jewelry& obj){
        if(this!=&obj){
            delete jewbox;
        }
        if(obj.jewbox){
            designer= obj.designer;
            price= obj.price;
            material= obj.material;
            weight= obj.weight;
            jewbox= new box(*obj.jewbox);
        }
    }
    
    Piece_of_jewelry& operator+(const  Piece_of_jewelry& obj){
        Piece_of_jewelry total=* this;
        total.price= this->price+ obj.price-((this->weight- obj.weight)*2);
        return total;
    }
    friend Piece_of_jewelry& compare(const Piece_of_jewelry& obj1, const Piece_of_jewelry& obj2);
    
    virtual void display() const{
        cout<<"Designer: "<<designer<<", Price: "<<price<<", Material: "<<material<<", Weight: "<<weight<<endl;
        if(jewbox){
            jewbox->displayBoxInformation();
        }
    }
   virtual ~ Piece_of_jewelry(){
        delete jewbox;
    };
    
};


template<typename nametype, typename pricetype>
Piece_of_jewelry<nametype, pricetype>& compare(const Piece_of_jewelry<nametype, pricetype>& obj1, const Piece_of_jewelry<nametype, pricetype>& obj2){
    if(obj1.price<obj2.price)
        return obj1;
    else
        return obj2;
}

class Necklace: public Piece_of_jewelry<string, double>{
private:
    int year;
public:
    Necklace():Piece_of_jewelry("NNN", 120, "Gold", 10, new box ("Necklace box","Gold")), year(2007){}
    Necklace(string d, double p, string m, float w, box* x, int y):Piece_of_jewelry(d, p, m, w, new box (*x)), year(y){}
    virtual void display() const{
        Piece_of_jewelry::display();
        cout<<"\nYear of production: "<<year<<endl;
        cout<<"Attention: this product is a Necklace"<<endl;
    }
    virtual ~Necklace(){};
};


class ring:public Piece_of_jewelry<string, double>{
private:
    string size;
public:
    ring(string d, double p, string m, float w, box* x, string s):Piece_of_jewelry(d, p, m, w, new box (*x)), size(s){}
    virtual void display() const{
        Piece_of_jewelry::display();
        cout<<"\nSize of the ring: "<< size<<endl;
        cout<<"Attention: this product is a ring"<<endl;
    }
    virtual ~ring(){};
};


int main(){
    

    vector<Piece_of_jewelry<string, double>*> jewelryVector;
    jewelryVector.push_back(new Necklace());
    jewelryVector.push_back(new ring("XYZ",250,"Silver",5,new box("ring box ","blue"),"medium"));
    jewelryVector.push_back(new Necklace("ABC",180,"Platinum",15, new box("Necklace box","silver"),2021));
    jewelryVector.push_back(new ring("LMN",300,"Gold",7,new box("ring box ","gold"),"large"));
    jewelryVector.push_back(new Necklace("PQR",150,"Rose gold",12, new box("Necklace box","gold"),2019));

    for(int i=0;i< jewelryVector.size();i++){
        jewelryVector[i]->display();
        cout<<endl;
        
    }
    for(int i=0;i< jewelryVector.size();i++){
        delete jewelryVector[i];
        
    }

    return 0;
}
