// Simple Hash-table
// * one value "key" like unordered_set
// * chaining for collision resolution
// * C++98
#include <iostream>
#include <list>
#include <vector>
#include <cassert>

//
// CHashTable
//
class CHashTable
{
private:
    static const int INIT_TABLE_SIZE = 101;
    std::vector<std::list<int> > table;
    double load_factor;
    size_t count;

protected:
    unsigned int hashFunction(int key) const;
    void rehash();

public:
    // Constructors
    CHashTable() : table(INIT_TABLE_SIZE), count(0), load_factor(0.75) {}

    // Capacity
    size_t size() const;
    bool empty() const;

    // Modifiers
    void insert(int key);
    void erase(int key);
    void clear();

    // Element lookup
    bool find(int key) const;

    // Element access
    std::vector<int> get() const;
};

//
// CHashTable Implementation
//

// Multiplicative Hashing
unsigned int CHashTable::hashFunction(int key) const {
    const unsigned int A = 2654435769U;
    return (key * A) % table.size();
}

void CHashTable::rehash() {
    std::vector<std::list<int> > new_table(table.size() * 2);

    for (size_t i = 0; i < table.size(); ++i) {
        for (std::list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it) {
            int new_index = *it % new_table.size();
            new_table[new_index].push_back(*it);
        }
    }

    table = new_table;
}

// Capacity
size_t CHashTable::size() const { return count; }

bool CHashTable::empty() const { return count == 0; }

// Modifiers
void CHashTable::insert(int key) {
    int index = hashFunction(key);
    std::list<int>& bucket = table[index];

    if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
        table[index].push_back(key);
        ++count;

        if (static_cast<double>(count) / table.size() > load_factor) {
            rehash();
        }
    }
}

void CHashTable::erase(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
    --count;
}

void CHashTable::clear() {
    for (size_t i = 0; i < table.size(); ++i) { 
        table[i].clear();
    }
    count = 0;
}

// Element lookup
bool CHashTable::find(int key) const {
    int index = hashFunction(key);
    const std::list<int>& bucket = table[index];
    return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
}

// Element access
std::vector<int> CHashTable::get() const {
    std::vector<int> elements;

    for (size_t i = 0; i < table.size(); ++i) {
        for (std::list<int>::const_iterator it = table[i].begin(); it != table[i].end(); ++it) {
            elements.push_back(*it);
        }
    }

    return elements;
}

//------------------------------------------------------------------------------
void testInsert();
void testErase();
void testFind();
void testClear();
void testGetAllElements();
void run_all_tests();

//------------------------------------------------------------------------------
int main()
{
    run_all_tests();
    return 0;    
}

//------------------------------------------------------------------------------
void run_all_tests() {
    testInsert();
    testErase();
    testFind();
    testClear();
    testGetAllElements();
    std::cout << "All tests passed!\n";
}

void testInsert() {
    CHashTable ht;
    
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    assert(ht.size() == 3);
    
    ht.insert(10);
    assert(ht.size() == 3);

    std::vector<int> elements = ht.get();
    assert(std::find(elements.begin(), elements.end(), 10) != elements.end());
    assert(std::find(elements.begin(), elements.end(), 20) != elements.end());
    assert(std::find(elements.begin(), elements.end(), 30) != elements.end());
}

void testErase() {
    CHashTable ht;
    
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    assert(ht.size() == 3);

    ht.erase(20);
    assert(ht.size() == 2);

    std::vector<int> elements = ht.get();
    assert(std::find(elements.begin(), elements.end(), 20) == elements.end());
    assert(std::find(elements.begin(), elements.end(), 10) != elements.end());
    assert(std::find(elements.begin(), elements.end(), 30) != elements.end());
}

void testFind() {
    CHashTable ht;
    
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);

    assert(ht.find(10) == true);
    assert(ht.find(20) == true);
    assert(ht.find(50) == false);
}

void testClear() {
    CHashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    assert(ht.size() == 3);

    ht.clear();
    assert(ht.size() == 0);
    assert(ht.empty() == true);

    std::vector<int> elements = ht.get();
    assert(elements.empty());
}

void testGetAllElements() {
    CHashTable ht;

    ht.insert(10);
    ht.insert(20);
    ht.insert(30);

    std::vector<int> elements = ht.get();
    assert(elements.size() == 3); 
    assert(std::find(elements.begin(), elements.end(), 10) != elements.end());
    assert(std::find(elements.begin(), elements.end(), 20) != elements.end());
    assert(std::find(elements.begin(), elements.end(), 30) != elements.end());

    ht.erase(10);
    elements = ht.get();
    assert(elements.size() == 2);
    assert(std::find(elements.begin(), elements.end(), 10) == elements.end());
}