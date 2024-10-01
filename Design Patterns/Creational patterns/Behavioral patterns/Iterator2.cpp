// Iterator Design Pattern example
#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T& next() = 0;
    virtual bool hasNext() const = 0;
};

template <typename T>
class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator<T>> createIterator() const = 0;
};

template<typename T>
class ConcreteIterator : public Iterator<T> {
public:
    ConcreteIterator(std::vector<T>& vec) : collection(vec), index(0) {}

    T& next() override {
        if (!hasNext()) throw std::out_of_range("No more elements.");
        return collection[index++];
    }

    bool hasNext() const override {
        return index < collection.size();
    }

private:
    std::vector<T>& collection;
    size_t index;
};

template<typename T>
class ConcreteAggregate : public Aggregate<T> {
public:
    ConcreteAggregate(std::initializer_list<T> list) : collection(list) {}

    std::unique_ptr<Iterator<T>> createIterator() const override {
        return std::make_unique<ConcreteIterator<T>>(const_cast<std::vector<T>&>(collection));
    }

    int size() const { return collection.size(); }

private:
    std::vector<T> collection;
};

int main() 
{
    ConcreteAggregate<int> collection = {1, 2, 3, 4, 5};
    std::unique_ptr<Iterator<int>> iterator = collection.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
