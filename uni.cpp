#include <iostream>
#include <string>
using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Card_ID
{
private:
    int num;
    string affiliation;
public:
    Card_ID():num(0), affiliation("unknown"){};
    Card_ID(int numn, string aff):num(numn), affiliation(aff){};
    
    void displayInfo() const
    {
        cout<<" Card Number: "<< num<<endl;
        cout<<"Affiliation: "<<affiliation<<endl;
    };
    
    bool comparecard(const Card_ID& other) const {
        return (num== other.num);
    };
    
    ~Card_ID(){};
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class uni
{
private:
    string fname, lname;
    Card_ID id;
public:
    uni(): fname("unknown"), lname("unknown"), id(5, "AUS"){};
    uni(string first, string last, int cardnum, string affi): fname(first), lname(last), id(cardnum, affi){};
    void display()const{
        cout<<"the first name is: "<<fname<<endl;
        cout<<"the last name is: "<<lname<<endl;
        cout<<"the id is: "<<endl;
        id.displayInfo();
    }
    
     bool comparenames(const uni& other) const
     {
         return(fname== other.fname && lname== other.lname);
     }
     
    bool comparecard(const uni& other) const
    {
        return(id.comparecard(other.id));
    }
    
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool operator==(const uni& name1, const uni& name2)
{
    return name1.comparenames(name2);
 }

bool operator!=(const uni& name1, const uni& name2)
{
    return !(name1.comparecard(name2));
 }

bool operator!=(const Card_ID& name1, const Card_ID& name2)
{
    return !(name1.comparecard(name2));
 }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    // Create two staff objects
    uni staff1("John", "Doe", 123, "TEACHER");
    uni staff2("John", "Doe", 456, "TEACHER");
    
    // Display staff information
    cout << "Staff 1 Information:" << endl;
    staff1.display();
    
    cout << "\nStaff 2 Information:" << endl;
    staff2.display();
    
    // Check if staff members have the same name
    if (staff1 == staff2) {
        cout << "\nWarning: Staff members have the same name!" << endl;
    }
    
    // Check if staff members have different ID numbers
    if (staff1 != staff2) {
        cout << "\nWarning: Staff members have different ID numbers!" << endl;
        
        return 0;
    }
}
