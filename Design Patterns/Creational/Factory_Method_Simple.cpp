// Simple Factory Method
#include <iostream>
#include <memory>
using namespace std;

enum ProductId {ID_A, ID_B};

class IProduct {
public:
   virtual void display() const = 0;
   virtual ~IProduct() = default;
};

class ConcreteProductA: public IProduct {
public:
    void display() const override { cout << "ConcreteProductA\n"; }
};

class ConcreteProductB: public IProduct {
public:
    void display() const override { cout << "ConcreteProductB\n"; }
};

// declares the factory method
class Creator {
public:
    virtual unique_ptr<IProduct> create(ProductId id) {
        if (ProductId::ID_A == id) return make_unique<ConcreteProductA>();
        if (ProductId::ID_B == id) return make_unique<ConcreteProductB>();
        // repeat for remaining products...

        return nullptr;
    }
    virtual ~Creator() = default;
};

int main() 
{
    unique_ptr<Creator> creator = make_unique<Creator>();

    unique_ptr<IProduct> product = creator->create(ProductId::ID_A);
    product->display();

    product = creator->create(ProductId::ID_B);
    product->display();

    return 0;
}