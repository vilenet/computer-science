#include <iostream>
#include <list>
#include <vector>

class CHashTable
{
private:
    int numBuckets;
    std::vector<std::list<int>> table;
    int hashFunction(int key) { return key % numBuckets; }

public:
    CHashTable(int size) : numBuckets(size), table(size) {}

    void insertItem(int key){
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key){
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Get the contents of a bucket by index
    const std::list<int>& getBucket(int index) const {
        return table[index];
    }

    int getNumBuckets() const {
        return numBuckets;
    }
};

void displayHash(const CHashTable& ht){
    for (int i = 0; i < ht.getNumBuckets(); ++i){
        const std::list<int>& bucket = ht.getBucket(i);
        if (!bucket.empty()){
            std::cout << "Bucket " << i << ":";
            for (int x : ht.getBucket(i)){
                std::cout << " -> " << x;
            }
            std::cout << std::endl; 
        }
    }
    std::cout << std::endl;
}

int main()
{
    CHashTable ht(7);
    
    ht.insertItem(15);
    ht.insertItem(11);
    ht.insertItem(27);
    ht.insertItem(8);
    ht.insertItem(12);

    displayHash(ht);

    ht.deleteItem(12);

    displayHash(ht);

    return 0;    
}