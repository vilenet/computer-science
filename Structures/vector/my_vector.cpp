// Basic vector implementation
#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <algorithm>
#include <initializer_list>

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
        // Necessary typedefs for iterator properties
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

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

        Iterator operator+(size_t n) const { return Iterator(m_ptr + n); }
        Iterator operator-(size_t n) const { return Iterator(m_ptr - n); }

        ptrdiff_t operator-(const Iterator& other) const { return m_ptr - other.m_ptr; }

        T* getPtr() const { return m_ptr; }
    };

public:
    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

    vector(const T& value) : m_data(new T[1]), m_size(1), m_capacity(1) {
        m_data[0] = value;
    }

    vector(std::initializer_list<T> initList)
        : m_data(new T[initList.size()])
        , m_size(initList.size())
        , m_capacity(initList.size()) 
    {
        std::copy(initList.begin(), initList.end(), m_data);
    }

    ~vector() { delete[] m_data; }


    vector& operator=(const vector& other) {
        if (this != & other) {
            delete[] m_data;
        }

        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

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

    Iterator erase(Iterator first, Iterator last) {
        if (first.getPtr() < m_data || 
            first.getPtr() > m_data + m_size || 
            last.getPtr() < m_data || 
            last.getPtr() > m_data + m_size) 
        {
            throw std::out_of_range("Iterator out of range");
        }

        T* start = first.getPtr();
        T* end = last.getPtr();

        size_t num_elements_to_remove = end - start;

        for (T* it = start; it != m_data + m_size - num_elements_to_remove; ++it) {
            *it = *(it + num_elements_to_remove);
        }

        m_size -= num_elements_to_remove;
        return Iterator(start);
    }

    Iterator erase(Iterator pos) {
        return erase(pos, Iterator(pos.getPtr() + 1));
    }
};

} // End of mystd namespace


int main()
{
    mystd::vector<int> vec1;
    mystd::vector<int> vec2(15);
    mystd::vector<int> vec3;
    mystd::vector<int> vec4 = {1, 2, 3, 4, 5, 3, 6, 3, 7};

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);

    
    for (int i=1; i<=10; i++) vec3.push_back(i);

    // erase the 6th element
    vec3.erase(vec3.begin() + 5);

    // erase the first 3 elements:
    vec3.erase(vec3.begin(), vec3.begin() + 3);

    vec1.erase(std::remove(vec1.begin(), vec1.end(), 20), vec1.end());

    // C++98
    for (mystd::vector<int>::Iterator it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // C++11
    for (auto n : vec3) {
        std::cout << n << " ";
    } 

    return 0;
}

