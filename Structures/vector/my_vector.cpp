// Basic vector implementation
#include <iostream>
#include <cstdlib>

namespace mystd
{

template<typename T>
class vector {
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
    
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }

        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

public:

    class Iterator {
    private:
        T* m_ptr;

    public:
        Iterator(int* ptr) : m_ptr(ptr) {}

        T& operator*() const { return *m_ptr; }

        Iterator& operator++() {
            m_ptr++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }
    };

public:
    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}
    //TODO: Ct with args
    ~vector() { delete[] m_data; }
    //TODO: operator=

    // Iterators methods:
    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data + m_size); }

    // Capacity methods:
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0;}

    // Element access methods:
    T& operator[](size_t index) {
        if (index >= m_size) { throw std::out_of_range("Index out of range"); }
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= m_size) { throw std::out_of_range("Index out of range"); }
        return m_data[index];
    }

    // Modifiers methods:
    void push_back(const T& value) {
        if (m_size == m_capacity) {
            size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
            resize(newCapacity);
        }
        m_data[m_size++] = value;
    }

    //TODO: erase()

};

} // End of mystd namespace


int main()
{
    mystd::vector<int> vec1;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    // C++11
    // for (auto n : vec1) {
    //     std::cout << n << " ";
    // } 

    // C++98
    for (mystd::vector<int>::Iterator it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    return 0;
}

