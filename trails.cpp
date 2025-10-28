#include <iostream>

class Number {
private:
    int* value;

public:
    // Default constructor
    Number() : value(nullptr) {}

    // Constructor with parameter
    Number(int num) : value(new int(num)) {}

    // Destructor
    ~Number() {
        delete value;
    }

    // Copy constructor
    Number(const Number& other) : value(nullptr) {
        if (other.value) {
            value = new int(*other.value);
        }
    }

    // Copy assignment operator || value==0
    Number& operator=(const Number& other) {
        if (this != &other) {
            delete value;
            if (other.value!=nullptr ) {
                value = new int(*other.value);
            } else {
                value = nullptr;
            }
        }
        return *this;
    }

    // Method to get value
    int getValue() const {
        return (value ? *value : 0);
    }

    // Method to display value
    void display() const {
        std::cout << "Value: " << getValue() << std::endl;
    }
};

int main() {
    // Create objects
    Number num1(5);
    Number num2(num1); // Copy constructor
    Number num3; // Default constructor

    // Display values
    num1.display();
    num2.display();
    num3.display();

    // Assignment
    num3 = num2; // Copy assignment operator

    // Display values after assignment
    num3.display();

    return 0;
}
