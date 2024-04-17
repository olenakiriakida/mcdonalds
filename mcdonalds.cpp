#include <iostream>
#include <string>
using namespace std;

enum class Size { S = 200, M = 300, XXL = 500 };

class Food abstract 
{
protected:
    Size size;
    double price;
    string description;

public:
    Size getSize() const
    {
        return size;
    }

    double getPrice() const
    {
        return price;
    }

    string getDescription() const
    {
        return description;
    }

    void print() const
    {
        cout << description << " = " << price << " UAH\n";
    }
};

class BigMac : public Food
{
public:
    BigMac(Size size)
    {
        description = "the best burger ever!";
        price = 90;
        
    }
};

class Fries : public Food
{
public:
    Fries()
    {
        this->size = size;
        description = "the crunchiest fries!";

        if (size == Size::S) price = 30;
        else if (size == Size::M) price = 45;
        else if (size == Size::XXL) price = 60;
        else throw "invalid fries size";
    }
};

class CocaCola : public Food
{
public:
    CocaCola()
    {
        this->size = size;
        description = "delicious drink";

        if (size == Size::S) price = 30;
        else if (size == Size::M) price = 45;
        else if (size == Size::XXL) price = 60;
        else throw "invalid drink size";
    }
};

////////////////////////////////////////////////////////////////

class Condiment abstract : public Food 
{
protected:
    Food* food;
};


class GarlicSauceCondiment : public Condiment
{
public:
    GarlicSauceCondiment(Food* food)
    {
        this->food = food; 
        description = this->food->getDescription() + " + Garlic Sauce (15 UAH)";
        price = this->food->getPrice() + 15;
    }

    GarlicSauceCondiment()
    {
        this->food = this;
        description = "large pack of sauce to go";
        price = 25;
    }
};

class BaconCondiment : public Condiment
{
public:
    BaconCondiment(Food* food)
    {
        this->food = food;
        description = this->food->getDescription() + " + Bacon (25 UAH)";
        price = this->food->getPrice() + 25;
    }
};

class CheeseSauceCondiment : public Condiment
{
public:
    CheeseSauceCondiment(Food* food)
    {
        this->food = food;
        description = this->food->getDescription() + " + Cheese Sauce (15 UAH)";
        price = this->food->getPrice() + 15;
    }
};

int main()
{
    Food* bigMac = new BigMac();
    Food* fries = new Fries(Size::XXL);
    Food* cocaCola = new CocaCola(Size::XXL);

    bigMac->print();
    fries->print();
    cocaCola->print();

    cout << "================================================\n";

    Food* upgradedNewBigMac = new GarlicSauceCondiment(new BaconCondiment(new BigMac()));
    upgradedNewBigMac ->print();

    Food* doubleBacon = new BaconCondiment(upgradedNewBigMac);
    doubleBacon ->print();

}