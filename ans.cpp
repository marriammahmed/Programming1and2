#include <iostream>
#include <vector>
#include <string>

class Box {
protected:
    std::string type;
    std::string color;

public:
    Box() : type("Unknown"), color("Unknown") {}

    Box(const std::string& type, const std::string& color) : type(type), color(color) {}

    virtual ~Box() {}

    virtual void displayBoxInformation() {
        std::cout << "Box Type: " << type << ", Color: " << color << std::endl;
    }
};

template <typename NameType, typename PriceType>
class PieceOfJewelry {
private:
    NameType designer;
    PriceType price;
    std::string material;
    double weight;
    Box* jewelryBox;

public:
    // Constructors
    PieceOfJewelry() : designer(), price(), material("Unknown"), weight(0), jewelryBox(nullptr) {}

    PieceOfJewelry(NameType designer, PriceType price, const std::string& material, double weight, Box* box)
        : designer(designer), price(price), material(material), weight(weight), jewelryBox(box) {}

    // Virtual Destructor
    virtual ~PieceOfJewelry() {
        delete jewelryBox;
    }

    // Rule of 3: Copy Constructor
    PieceOfJewelry(const PieceOfJewelry& other)
        : designer(other.designer), price(other.price), material(other.material), weight(other.weight) {
        if (other.jewelryBox)
            jewelryBox = new Box(*other.jewelryBox);
        else
            jewelryBox = nullptr;
    }

    // Rule of 3: Copy Assignment Operator
    PieceOfJewelry& operator=(const PieceOfJewelry& other) {
        if (this != &other) {
            designer = other.designer;
            price = other.price;
            material = other.material;
            weight = other.weight;

            delete jewelryBox;
            if (other.jewelryBox)
                jewelryBox = new Box(*other.jewelryBox);
            else
                jewelryBox = nullptr;
        }
        return *this;
    }

    // Virtual Display Method
    virtual void display() const {
        std::cout << "Designer: " << designer << ", Price: " << price << ", Material: " << material
                  << ", Weight: " << weight << std::endl;
        if (jewelryBox)
            jewelryBox->displayBoxInformation();
        std::cout << std::endl;
    }

    // Overloaded Operator+
    PieceOfJewelry operator+(const PieceOfJewelry& other) const {
        PieceOfJewelry result = *this;
        result.price = this->price + other.price - (this->weight - other.weight);
        return result;
    }

    // Friend Function
    friend PieceOfJewelry comparePrices(const PieceOfJewelry& piece1, const PieceOfJewelry& piece2) {
        return piece1.price < piece2.price ? piece1 : piece2;
    }
};

// Friend Function Implementation
PieceOfJewelry<int, double> comparePrices(const PieceOfJewelry<int, double>& piece1, const PieceOfJewelry<int, double>& piece2) {
    return piece1.price < piece2.price ? piece1 : piece2;
}

class NecklaceBox : public Box {
public:
    NecklaceBox(const std::string& color) : Box("Necklace Box", color) {}
};

class RingBox : public Box {
public:
    RingBox(const std::string& color) : Box("Ring Box", color) {}
};

class EarringBox : public Box {
public:
    EarringBox(const std::string& color) : Box("Earring Box", color) {}
};

class Necklace : public PieceOfJewelry<std::string, double> {
private:
    int yearOfProduction;

public:
    // Default Constructor
    Necklace()
        : PieceOfJewelry<std::string, double>("NNN", 120, "Gold", 10, new NecklaceBox("Gold")), yearOfProduction(2007) {}

    // Overloaded Constructor
    Necklace(const std::string& designer, double price, const std::string& material, double weight, Box* box, int year)
        : PieceOfJewelry<std::string, double>(designer, price, material, weight, box), yearOfProduction(year) {}

    // Virtual Display Method Override
    void display() const override {
        PieceOfJewelry::display();
        std::cout << "Year of Production: " << yearOfProduction << std::endl;
        std::cout << "Attention: This product is a Necklace." << std::endl << std::endl;
    }
};

class Ring : public PieceOfJewelry<std::string, double> {
private:
    std::string sizeOfRing;

public:
    // Overloaded Constructor
    Ring(const std::string& designer, const std::string& size, double price, const std::string& material, double weight, Box* box)
        : PieceOfJewelry<std::string, double>(designer, price, material, weight, box), sizeOfRing(size) {}

    // Virtual Display Method Override
    void display() const override {
        PieceOfJewelry::display();
        std::cout << "Size of Ring: " << sizeOfRing << std::endl;
        std::cout << "Attention: This product is a Ring." << std::endl << std::endl;
    }
};

int main() {
    // Create a vector of 5 products
    std::vector<PieceOfJewelry<std::string, double>*> jewelryVector;

    // Populate the vector with instances of different jewelry types
    jewelryVector.push_back(new Necklace());
    jewelryVector.push_back(new Ring("XYZ", "Medium", 250, "Silver", 5, new RingBox("Blue")));
    jewelryVector.push_back(new Necklace("ABC", 180, "Platinum", 15, new NecklaceBox("Silver"), 2021));
    jewelryVector.push_back(new Ring("LMN", "Large", 300, "Gold", 7, new RingBox("Gold")));
    jewelryVector.push_back(new Necklace("PQR", 150, "Rose Gold", 12, new NecklaceBox("Gold"), 2019));

    // Display the characteristics of each product
    for (const auto& jewelry : jewelryVector) {
        jewelry->display();
    }

    // Clean up allocated memory
    for (const auto& jewelry : jewelryVector) {
        delete jewelry;
    }

    return 0;
}
