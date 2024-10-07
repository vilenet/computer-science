// Factory Method design pattern
#include <iostream>
#include <memory>

class IProduct {
public:
    virtual void display() const = 0;
    virtual ~IProduct() = default;
};

class ConcreteProductA : public IProduct {
public:
    void display() const override {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

class ConcreteProductB : public IProduct {
public:
    void display() const override {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class ICreator {
public:
    virtual std::unique_ptr<IProduct> createProduct() const = 0;
    virtual ~ICreator() = default;
};

class ConcreteCreatorA : public ICreator {
public:
    std::unique_ptr<IProduct> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public ICreator {
public:
    std::unique_ptr<IProduct> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
};


void clientCode(const ICreator& creator) {
    // Create a product through a factory method
    auto product = creator.createProduct();

    product->display();
}

int main() 
{
    std::cout << "Using ConcreteCreatorA:\n";
    ConcreteCreatorA creatorA;
    clientCode(creatorA);

    std::cout << "Using ConcreteCreatorB:\n";
    ConcreteCreatorB creatorB;
    clientCode(creatorB);

    return 0;
}
