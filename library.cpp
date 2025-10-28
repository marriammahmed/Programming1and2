#include <iostream> 
#include<string>
using namespace std;


class book {
private:
    string title;
    string author;
public:
    book() {}
    book(const string& title, const string& author) : title(title), author(author) {}
    
   friend ostream& operator<<(ostream& os, const book& bookaya)
    {
        os << "Title: " << bookaya.title << ", Author: " << bookaya.author;
        return os;
    }
   
};

class library {
private:
    string name;
    int cap;
    int num=0;
    book* books;
public:
    library():name("none"),cap(5),num(0),books(new book[cap]){}
    library(const library& obj):name(obj.name),cap(obj.cap),num(obj.num),books(new book[cap])
    {
        for(int i=0;i<obj.num; i++)
        {
            books[i]= obj.books[i];
        }
    }
    library& operator=(const library& other)
    {
        if(this!= &other)
        {
            delete [] books;
            name= other.name;
            cap= other.cap;
            num= other.num;
            books = new book[cap];
            for(int i=0; i<other.num;i++)
            {
                books[i]=other.books[i];
            }
        }
        return *this;
    }
    
    void addBook( book& bookaya)
    {
        if(num<cap)
        {
            books[num++]= bookaya;
        }
    }
 
    friend ostream& operator<<(ostream& out, const library& library)
    {
        out << "Library Name: " << library.name << endl;
        out << "Books in Library:" << endl;
        
        for (int i = 0; i < library.num; ++i)
        {
            out << library.books[i] << endl;
        }
    return out;
    }
    
    ~library(){delete[]books;}
};

int main()
{
 
    string title, author;
    cout<<"Pleae enter the title and author of the book (each one full line): ";
    getline(cin, title);
    getline(cin, author);
    book book1(title, author);
    
    library library1;
    library1.addBook(book1);
    
   // library1= {"my library", 7};
    
    library library2=library1;
 
    library library3;
    library3=library2;
    
    cout << "Library 1: " << endl; 
    cout << library1 << endl;
    cout << "Library 2: " << endl;
    cout << library2 << endl;
    cout << "Library 3: " << endl;
    cout << library3 << endl;
    
    
    
    return 0;
}
