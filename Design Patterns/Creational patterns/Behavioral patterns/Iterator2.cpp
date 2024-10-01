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
    ConcreteIterator(std::vector<T>& vec) : m_array(vec), m_index(0) {}

    T& next() override {
        if (!hasNext()) throw std::out_of_range("No more elements.");
        return m_array[m_index++];
    }

    bool hasNext() const override {
        return m_index < m_array.size();
    }

private:
    std::vector<T>& m_array;
    size_t m_index;
};

template<typename T>
class ConcreteAggregate : public Aggregate<T> {
public:
    ConcreteAggregate(std::initializer_list<T> list) : m_array(list) {}

    std::unique_ptr<Iterator<T>> createIterator() const override {
        return std::make_unique<ConcreteIterator<T>>(const_cast<std::vector<T>&>(m_array));
    }

    int size() const { return m_array.size(); }

private:
    std::vector<T> m_array;
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
