// Factory Method
#include <iostream>
#include <memory>
using namespace std;

class IProduct {
public:
    virtual void display() const = 0;
    virtual ~IProduct() = default;
};

class ConcreteProductA : public IProduct {
public:
    void display() const override { cout << "ConcreteProductA" << endl; }
};

class ConcreteProductB : public IProduct {
public:
    void display() const override { cout << "ConcreteProductB" << endl; }
};

class ICreator {
public:
    virtual unique_ptr<IProduct> createProduct() const = 0;
    virtual ~ICreator() = default;
};

class ConcreteCreatorA : public ICreator {
public:
    unique_ptr<IProduct> createProduct() const override {
        return make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public ICreator {
public:
    unique_ptr<IProduct> createProduct() const override {
        return make_unique<ConcreteProductB>();
    }
};


void clientCode(const ICreator& creator) {
    // Create a product through a factory method
    auto product = creator.createProduct();

    product->display();
}

int main() 
{
    ConcreteCreatorA creatorA;
    clientCode(creatorA);

    ConcreteCreatorB creatorB;
    clientCode(creatorB);

    return 0;
}
