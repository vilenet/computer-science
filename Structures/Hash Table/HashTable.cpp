#include <string>
#include <iostream>
#include <optional>

// Хэш-функция с использованием метода Горнера
int HornerHash(const std::string& str, int size, int key) {
    int hash = 0;
    for (int i = 0; i < str.size(); ++i) {
        hash = (key * hash + str[i]) % size;
    }
    return (hash * 2 + 1) % size;
}

struct Hash1 {
    int operator()(const std::string& str, int size) const {
        return HornerHash(str, size, size - 1);
    }
};

struct Hash2 {
    int operator()(const std::string& str, int size) const {
        return HornerHash(str, size, size + 1);
    }
};

template <class T, class H1 = Hash1, class H2 = Hash2>
class CHashTable {
    static const int iTbSizeDef = 8;  // Начальный размер таблицы
    constexpr static double dLoadFactor = 0.75; // Коэффициент загрузки

    struct Node {
        T value;
        bool bActive;
        Node(const T& v) : value(v), bActive(true) {}
    };

    Node** table;  // Массив указателей на узлы
    int iTbSize;   // Размер таблицы
    int iActElQty; // Количество активных элементов

    void Resize(); // Изменение размера таблицы

public:
    CHashTable();
    ~CHashTable();

    bool Add(const T& val, const H1& h1 = H1(), const H2& h2 = H2());
    bool Find(const T& val, const H1& h1 = H1(), const H2& h2 = H2());
    bool Remove(const T& val, const H1& h1 = H1(), const H2& h2 = H2());
};

template <class T, class H1, class H2>
CHashTable<T, H1, H2>::CHashTable() {
    iTbSize = iTbSizeDef;
    iActElQty = 0;
    table = new Node*[iTbSize];
    for (int i = 0; i < iTbSize; ++i) {
        table[i] = nullptr;
    }
}

template <class T, class H1, class H2>
CHashTable<T, H1, H2>::~CHashTable() {
    for (int i = 0; i < iTbSize; ++i) {
        delete table[i];
    }
    delete[] table;
}

template <class T, class H1, class H2>
void CHashTable<T, H1, H2>::Resize() {
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

template <class T, class H1, class H2>
bool CHashTable<T, H1, H2>::Add(const T& val, const H1& h1, const H2& h2) {
    if (iActElQty >= static_cast<int>(dLoadFactor * iTbSize)) {
        Resize();
    }

    int hash1 = h1(val, iTbSize);
    int hash2 = h2(val, iTbSize);
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

template <class T, class H1, class H2>
bool CHashTable<T, H1, H2>::Remove(const T& val, const H1& h1, const H2& h2) {
    int hash1 = h1(val, iTbSize);
    int hash2 = h2(val, iTbSize);
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

template <class T, class H1, class H2>
bool CHashTable<T, H1, H2>::Find(const T& val, const H1& h1, const H2& h2) {
    int hash1 = h1(val, iTbSize);
    int hash2 = h2(val, iTbSize);
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

int main() {
    CHashTable<std::string> hashTable;

    std::cout << "Adding 'apple': "  << (hashTable.Add("apple") ? "Success" : "Failed") << std::endl;
    std::cout << "Adding 'banana': " << (hashTable.Add("banana") ? "Success" : "Failed") << std::endl;
    std::cout << "Adding 'cherry': " << (hashTable.Add("cherry") ? "Success" : "Failed") << std::endl;

    std::cout << "Finding 'apple': "  << (hashTable.Find("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Finding 'banana': " << (hashTable.Find("banana") ? "Found" : "Not Found") << std::endl;
    std::cout << "Finding 'cherry': " << (hashTable.Find("cherry") ? "Found" : "Not Found") << std::endl;
    std::cout << "Finding 'date': "   << (hashTable.Find("date") ? "Found" : "Not Found") << std::endl;

    std::cout << "Removing 'banana': " << (hashTable.Remove("banana") ? "Success" : "Failed") << std::endl;
    std::cout << "Removing 'date': "   << (hashTable.Remove("date") ? "Success" : "Failed") << std::endl;

    return 0;
}
