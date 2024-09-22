// Container adapter "stack" realization one queue based
#include <iostream>
#include <cassert>
#include <utility>
#include <queue>

namespace tst{

//
// stack
//
template <typename T, typename Container = std::queue<T>>
class stack {
protected:
    Container m_container;

public:
    // Types
    typedef T                                   value_type;
    typedef Container                           container_type;
    typedef typename Container::size_type       size_type;
    typedef typename Container::reference       reference;
    typedef typename Container::const_reference const_reference;

public:
    // Constructors
    stack() : m_container() {};
    explicit stack(const Container& container) : m_container(container) {}
    explicit stack(Container&& container) noexcept: m_container(std::move(container)) {}

public:
    // Methods
    bool      empty() const;
    size_type size()  const;

    reference       top();
    const_reference top() const;

    void push(const value_type& value);
    void push(value_type&& value);

    void pop();
    
public:
    // Friend relational operators
    template <typename T1, typename C1>
    friend bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

    template <typename T1, typename C1>
    friend bool operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

    template <typename T1, typename C1>
    friend bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

    template <typename T1, typename C1>
    friend bool operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

    template <typename T1, typename C1>
    friend bool operator>(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

    template <typename T1, typename C1>
    friend bool operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

};

//
// stack implementation
//

template <typename T, typename Container>
bool stack<T, Container>::empty() const { return m_container.empty(); }

template <typename T, typename Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const { 
    return m_container.size(); 
}

template <typename T, typename Container>
void stack<T, Container>::push(const value_type& value) {
    m_container.push(value);
    size_t size = m_container.size();

    for (int i = 0; i < size - 1; ++i) {
        m_container.push(m_container.front());
        m_container.pop();
    }
}

template <typename T, typename Container>
void stack<T, Container>::push(value_type&& value) {
    m_container.push(std::move(value));
    size_t size = m_container.size();

    for (size_t i = 0; i < size - 1; ++i) {
        m_container.push(std::move(m_container.front()));
        m_container.pop();
    }
}

template <typename T, typename Container>
void stack<T, Container>::pop() { if (!m_container.empty()) m_container.pop(); }

template <typename T, typename Container>
typename stack<T, Container>::reference stack<T, Container>::top() {
    return m_container.front();
}

template <typename T, typename Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
    return m_container.front();
}

//
// relational operators implementations
//
template <typename T1, typename C1>
bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return lhs.m_container == rhs.m_container;
}

template <typename T1, typename C1>
bool operator!=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return !(lhs == rhs);
}

template <typename T1, typename C1>
bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return lhs.m_container < rhs.m_container;
}

template <typename T1, typename C1>
bool operator<=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return !(rhs < lhs);
}

template <typename T1, typename C1>
bool operator>(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return rhs < lhs;
}

template <typename T1, typename C1>
bool operator>=(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs) {
    return !(lhs < rhs);
}

}; // end tst namespace

//------------------------------------------------------------------------------
void test_empty_stack();
void test_push_elements();
void test_pop_elements();
void test_empty_stack_after_pop();
void test_pop_on_empty_stack();
void test_stack_comparison();

////////////////////////////////////////////////////////////////////////////////
int main()
{
    void test_empty_stack();
    void test_push_elements();
    void test_pop_elements();
    void test_empty_stack_after_pop();
    void test_pop_on_empty_stack();
    void test_stack_comparison();
    std::cout << "All tests passed!\n";

    return 0;
}

//------------------------------------------------------------------------------
void test_empty_stack() {
    tst::stack<int> stack;
    assert(stack.empty() && "Test failed: stack should be empty after initialization");
}

void test_push_elements() {
    tst::stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.top() == 30 && "Test failed: top element should be 30");
    assert(stack.size() == 3 && "Test failed: stack size should be 3");
}

void test_pop_elements() {
    tst::stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();

    assert(stack.top() == 20 && "Test failed: top element should be 20 after pop");
    assert(stack.size() == 2 && "Test failed: stack size should be 2 after pop");
}

void test_empty_stack_after_pop() {
    tst::stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    stack.pop();

    assert(stack.empty() && "Test failed: stack should be empty after all pops");
}

void test_pop_on_empty_stack() {
    tst::stack<int> stack;
    stack.pop();
    assert(stack.empty() && "Test failed: stack should still be empty after pop on an empty stack");
}

void test_stack_comparison() {
    tst::stack<int> stack1;
    tst::stack<int> stack2;

    stack1.push(10);
    stack1.push(20);

    stack2.push(10);
    stack2.push(20);

    assert(stack1 == stack2 && "Test failed: stacks should be equal");

    stack2.push(30);

    assert(stack1 != stack2 && "Test failed: stacks should not be equal");
    assert(stack1 < stack2 && "Test failed: stack1 should be less than stack2");
    assert(stack2 > stack1 && "Test failed: stack2 should be greater than stack1");
}