// Simple Hash-table
// * one value like unordered_set
// * std:hash
// * tampletes
#include <unordered_set>
#include <functional>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <memory>
#include <cmath>

//
// CHashTable
//
template <class T>
class CHashTable {
private:
    static const int INIT_TABLE_SIZE = 8; // Initial table size
    constexpr static double LOAD_FACTOR = 0.75; 

    struct Node {
        T value;
        bool bActive;
        Node(const T& v) : value(v), bActive(true) {}
    };

    Node** table;  // Array of pointers to nodes
    int iTbSize;   
    int iActElQty; // Number of active elements

private:
    std::size_t hash_func1(const T& val) const;
    std::size_t hash_func2(const T& val) const;

    void Resize();

public:
    CHashTable();
    ~CHashTable();

    bool Add(const T& val);
    bool Find(const T& val);
    bool Remove(const T& val);

    std::vector<T> get() const;
};

//
// CHashTable Implementation
//
template <class T>
std::size_t CHashTable<T>::hash_func1(const T& val) const {
    std::hash<T> h;
    return h(val) % iTbSize;
}

template <class T>
std::size_t CHashTable<T>::hash_func2(const T& val) const {
    std::hash<T> h;
    return (h(val) % (iTbSize - 1)) + 1;
}

template <class T>
CHashTable<T>::CHashTable() {
    iTbSize = INIT_TABLE_SIZE;
    iActElQty = 0;
    table = new Node*[iTbSize];
    for (int i = 0; i < iTbSize; ++i) {
        table[i] = nullptr;
    }
}

template <class T>
CHashTable<T>::~CHashTable() {
    for (int i = 0; i < iTbSize; ++i) {
        delete table[i];
    }
    delete[] table;
}

template <class T>
void CHashTable<T>::Resize() {
    int oldCapacity = iTbSize;
    Node** oldTable = table;

    iTbSize *= 2;
    table = new Node*[iTbSize];
    for (int i = 0; i < iTbSize; ++i) {
        table[i] = nullptr;
    }

    for (int i = 0; i < oldCapacity; ++i) {
        if (oldTable[i] && oldTable[i]->bActive) {
            // Rehash old elements
            Add(oldTable[i]->value);
            delete oldTable[i];
        }
    }
    delete[] oldTable;
}

template <class T>
bool CHashTable<T>::Add(const T& val) {
    if (iActElQty >= static_cast<int>(LOAD_FACTOR * iTbSize)) {
        Resize();
    }

    std::size_t hash1 = hash_func1(val);
    std::size_t hash2 = hash_func2(val);
    int i = 0;
    while (table[hash1] != nullptr && i < iTbSize) {
        if (table[hash1]->value == val && table[hash1]->bActive) {
            return false;  // Element already exists
        }
        hash1 = (hash1 + hash2) % iTbSize;
        ++i;
    }

    if (table[hash1] == nullptr || !table[hash1]->bActive) {
        delete table[hash1]; // Clean up old deleted node
        table[hash1] = new Node(val);
        ++iActElQty;
    } else {
        table[hash1]->value = val;
        table[hash1]->bActive = true;
    }
    return true;
}

template <class T>
bool CHashTable<T>::Remove(const T& val) {
    int hash1 = hash_func1(val);
    int hash2 = hash_func2(val);
    int i = 0;
    while (table[hash1] != nullptr && i < iTbSize) {
        if (table[hash1]->value == val && table[hash1]->bActive) {
            table[hash1]->bActive = false;
            --iActElQty;
            return true;
        }
        hash1 = (hash1 + hash2) % iTbSize;
        ++i;
    }
    return false;
}

template <class T>
bool CHashTable<T>::Find(const T& val) {
    int hash1 = hash_func1(val);
    int hash2 = hash_func2(val);
    int i = 0;
    while (table[hash1] != nullptr && i < iTbSize) {
        if (table[hash1]->value == val && table[hash1]->bActive) {
            return true;
        }
        hash1 = (hash1 + hash2) % iTbSize;
        ++i;
    }
    return false;
}

// Element access
template <class T>
std::vector<T> CHashTable<T>::get() const {
    std::vector<T> elements;

    for (int i = 0; i < iTbSize; ++i) {
        if (table[i] && table[i]->bActive) {
            elements.push_back(table[i]->value);
        }
    }

    return elements;
}

//------------------------------------------------------------------------------
void testAdd();
void testFind();
void testRemove();
void run_all_tests();

//------------------------------------------------------------------------------

int main() 
{
    run_all_tests();
    return 0;
}

//------------------------------------------------------------------------------
void run_all_tests() {
    testAdd();
    testFind();
    testRemove();
    std::cout << "All tests passed!\n";
}

void testAdd() {
    CHashTable<std::string> ht;
    assert(ht.Add("s1") == true);
    assert(ht.Add("s2") == true);
    assert(ht.Add("s1") == false);
    assert(ht.Add("s3") == true);

    std::vector<std::string> elements = ht.get();
    std::unordered_set<std::string> elementSet(elements.begin(), elements.end());
    std::unordered_set<std::string> expected = { "s1", "s2", "s3" };

    assert(elementSet == expected);
}

void testFind() {
    CHashTable<std::string> ht;
    ht.Add("s1");
    ht.Add("s2");

    assert(ht.Find("s1") == true);
    assert(ht.Find("s2") == true);
    assert(ht.Find("s3") == false);
}

void testRemove() {
    CHashTable<std::string> ht;
    ht.Add("s1");
    ht.Add("s2");

    assert(ht.Remove("s2") == true);
    assert(ht.Remove("s2") == false);
    assert(ht.Remove("s3") == false);

    std::vector<std::string> elements = ht.get();
    std::vector<std::string> expected = { "s1" };
    
    assert(elements == expected);
}
