#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class Iterator {
public:
    virtual ~Iterator() = default;
    virtual T next() = 0;
    virtual bool hasNext() const = 0;
};

template <typename T>
class Aggregate {
public:
    virtual ~Aggregate() = default;
    virtual std::shared_ptr<Iterator<T>> iterator() = 0;
};

template <typename T>
class ConcreteIterator : public Iterator<T> {
private:
    std::vector<T>& collection;
    size_t currentIndex;

public:
    ConcreteIterator(std::vector<T>& col) : collection(col), currentIndex(0) {}

    T next() override {
        return collection[currentIndex++];
    }

    bool hasNext() const override {
        return currentIndex < collection.size();
    }
};

template <typename T>
class ConcreteAggregate : public Aggregate<T> {
private:
    std::vector<T> collection;

public:
    ConcreteAggregate(const std::initializer_list<T>& elements) : collection(elements) {}

    std::shared_ptr<Iterator<T>> iterator() override {
        return std::make_shared<ConcreteIterator<T>>(collection);
    }
};


int main() 
{
    ConcreteAggregate<int> numbers{1, 2, 3, 4, 5};
    auto it = numbers.iterator();

    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }

    return 0;
}
