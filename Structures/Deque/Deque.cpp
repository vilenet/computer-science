// deque interface realization example
#include <memory>
#include <iterator>

namespace tst
{


//
// deque
//
template<typename T>
class deque {
public:
    // Types
    using value_type      = T;
    using size_type       = std::size_t;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;
    using allocator_type  = std::allocator<T>;

    // Iterators
    class iterator;
    class const_iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Constructors
    deque();
    explicit deque(size_type count, const T& value = T());
    template<typename InputIt>
    deque(InputIt first, InputIt last);
    deque(const deque& other);
    deque(deque&& other) noexcept;
    deque(std::initializer_list<T> init);

    // Деструктор
    ~deque();

    // Операторы присваивания
    deque& operator=(const deque& other);
    deque& operator=(deque&& other) noexcept;
    deque& operator=(std::initializer_list<T> init);

    // Методы доступа
    reference       at(size_type pos);
    const_reference at(size_type pos) const;
    reference       operator[](size_type pos);
    const_reference operator[](size_type pos) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;

    // Модификаторы
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void pop_front();
    void clear();
    void swap(deque& other) noexcept;

    // Итераторы
    class iterator;
    class const_iterator;
    class reverse_iterator;
    class const_reverse_iterator;

    iterator               begin();
    const_iterator         begin() const;
    iterator               end();
    const_iterator         end() const;
    reverse_iterator       rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator       rend();
    const_reverse_iterator rend() const;    

private:
    // Типы для внутреннего использования
    using map_pointer = T**; // Указатель на массив указателей на блоки

    // Константы
    static const std::size_t block_size = 64; // Размер одного блока

    // Внутренние переменные
    map_pointer map_;             // Массив указателей на блоки
    std::size_t map_size_;        // Размер массива map_ (количество блоков)
    std::size_t map_capacity_;    // Емкость массива map_
    T*  start_cur_;               // Указатель на первый элемент в start_block_
    T*  finish_cur_;              // Указатель на позицию после последнего элемента в finish_block_
    T** start_block_;             // Указатель на блок, содержащий первый элемент
    T** finish_block_;            // Указатель на блок, содержащий последний элемент
    std::allocator<T> allocator_; // Аллокатор для управления памятью

    // Вспомогательные методы для управления блоками
    void allocate_map(std::size_t n);
    void deallocate_map();
    void reserve_map_at_back(std::size_t nodes_to_add = 1);
    void reserve_map_at_front(std::size_t nodes_to_add = 1);
    void push_back_aux(const T& value);
    void push_front_aux(const T& value);

    //Другие вспомогательные методы ?
};

//------------------------------------------------------------------------------
//
// iterator
//
template<typename T>
class deque<T>::iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = deque::value_type;
    using difference_type = deque::difference_type;
    using pointer = deque::pointer;
    using reference = deque::reference;

    // Конструкторы
    iterator();
    iterator(const iterator& other);
    // Другие необходимые конструкторы

    // Операторы разыменования
    reference operator*() const;
    pointer operator->() const;

    // Операторы инкремента и декремента
    iterator& operator++();    // Префиксный инкремент
    iterator operator++(int);  // Постфиксный инкремент
    iterator& operator--();    // Префиксный декремент
    iterator operator--(int);  // Постфиксный декремент

    // Арифметические операторы
    iterator& operator+=(difference_type n);
    iterator operator+(difference_type n) const;
    iterator& operator-=(difference_type n);
    iterator operator-(difference_type n) const;
    difference_type operator-(const iterator& other) const;

    // Операторы сравнения
    bool operator==(const iterator& other) const;
    bool operator!=(const iterator& other) const;
    bool operator<(const iterator& other) const;
    bool operator<=(const iterator& other) const;
    bool operator>(const iterator& other) const;
    bool operator>=(const iterator& other) const;

    // Оператор индексирования
    reference operator[](difference_type n) const;

private:
    // Внутренние данные итератора
    // Например, указатель на текущий элемент и индексы блоков
    pointer current_element_;
    // Дополнительные данные для управления блоками
};

//
// const_iterator
//
template<typename T>
class deque<T>::const_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = deque::value_type;
    using difference_type   = deque::difference_type;
    using pointer           = deque::const_pointer;
    using reference         = deque::const_reference;

    // Конструкторы
    const_iterator();
    const_iterator(const const_iterator& other);
    const_iterator(const iterator& other); // Преобразование из iterator в const_iterator

    // Операторы разыменования
    reference operator*() const;
    pointer operator->() const;

    // Операторы инкремента и декремента
    const_iterator& operator++();
    const_iterator operator++(int);
    const_iterator& operator--();
    const_iterator operator--(int);

    // Арифметические операторы
    const_iterator& operator+=(difference_type n);
    const_iterator  operator+(difference_type n) const;
    const_iterator& operator-=(difference_type n);
    const_iterator  operator-(difference_type n) const;
    difference_type operator-(const const_iterator& other) const;

    // Операторы сравнения
    bool operator==(const const_iterator& other) const;
    bool operator!=(const const_iterator& other) const;
    bool operator<(const const_iterator& other) const;
    bool operator<=(const const_iterator& other) const;
    bool operator>(const const_iterator& other) const;
    bool operator>=(const const_iterator& other) const;

    // Оператор индексирования
    reference operator[](difference_type n) const;

private:
    // Внутренние данные итератора
    const_pointer current_element_;
    // Дополнительные данные для управления блоками
};


} // END TST NAMESPACE

/*
map_ (массив указателей на блоки)
+--------+--------+--------+--------+--------+
| block0 | block1 | block2 | block3 | block4 |
+--------+--------+--------+--------+--------+
     |        |        |        |        |
     V        V        V        V        V
[block0] [block1] [block2] [block3] [block4]
  (64T)   (64T)    (64T)    (64T)    (64T)
*/