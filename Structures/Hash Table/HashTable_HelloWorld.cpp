// Simple Hash-table example (unordered_set)
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
    std::vector<std::list<int>> table;
    unsigned int hashFunction(int key) const;

public:
    // Constructors
    CHashTable() : table(INIT_TABLE_SIZE) {}

    // Capacity
    size_t size() const;
    bool empty() const;

    // Modifiers
    void insert(int key);
    void erase(int key);
    void clear();

    // Element lookup
    bool find(int key) const;
};

//
// CHashTable Implementation
//

// DJB2
unsigned int CHashTable::hashFunction(int key) const {
    unsigned int hash = 5381;
    hash = ((hash << 5) + hash) + key; // hash * 33 + key
    return hash % table.size();
}

// Capacity
size_t CHashTable::size() const {
    size_t count = 0;
    for (const auto& bucket : table) { count += bucket.size(); }
    return count;
}

bool CHashTable::empty() const { return size() == 0; }

// Modifiers
void CHashTable::insert(int key) {
    int index = hashFunction(key);
    if (std::find(table[index].begin(), table[index].end(), key) == table[index].end()) {
        table[index].push_back(key);
    }
}

void CHashTable::erase(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
}

void CHashTable::clear() {
    for (auto& bucket : table) { 
        bucket.clear(); 
    }
}

// Element lookup
bool CHashTable::find(int key) const {
    int index = hashFunction(key);
    auto it = std::find(table[index].begin(), table[index].end(), key);
    return it != table[index].end();
}

//------------------------------------------------------------------------------
void testInsert();
void testErase();
void testFind();
void testClear();
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
    std::cout << "All tests passed!\n";
}

void testInsert() {
    CHashTable ht;
    
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    assert(ht.size() == 3);
    
    ht.insert(10);
    assert(ht.size() == 3); // No duplicate insert
}

void testErase() {
    CHashTable ht;
    
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    assert(ht.size() == 3);

    ht.erase(20);
    assert(ht.size() == 2);
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
}