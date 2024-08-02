// Barton Nackman trick
//
// This trick avoids the use of virtual functions and dynamic polymorphism, 
// instead telling the compiler to generate optimized code at compile time 
// and use static polymorphism.

// The basic idea is to use templates and inheritance to implement an 
// interface in a base class and then provide the implementation in a derived class.

// Advantages of the Barton-Nackman Trick:

// 1. Avoidance of Virtual Functions: There is no need to use virtual 
//    functions and virtual tables, reducing overhead and improving performance.

// 2. Static Polymorphism: Everything is resolved at compile-time, allowing the 
//    compiler to generate more optimized code.

// 3. Extensibility: It is easy to add new implementations without changing existing code.

// Disadvantages:

// 1. Increased Compilation Time: The use of templates can increase compilation time.
// 2. Complexity: The code can become less understandable and harder to debug.


#include <iostream>

// example 1

template<typename Derived>
class Base{
public:
    // Call implementation in derived class
    void interface() { static_cast<Derived*>(this)->func(); }

    // Default implementation if the derived class does not override the method
    void func() { 
        std::cout << "Default func implementation" << std::endl; 
    }
};

// Derived class that overrides the implementation
class Derived1 : public Base<Derived1> {
public:
    void func() {
        std::cout << "Derived1 func implementation" << std::endl;
    }
};

// Derived class that does not override the implementation
class Derived2 : public Base<Derived2> {
    // Uses the default implementation from the base class
};

// example 2 

template<typename Derived>
class Computation {
public:
    void execute() { static_cast<Derived*>(this)->execute(); }
};

class FastComputation : public Computation<FastComputation> {
public:
    void execute() { std::cout << "Fast computation\n"; }
};

class AccurateComputation : public Computation<AccurateComputation> {
public:
    void execute() { std::cout << "Accurate computation\n"; }
};


int main()
{
    // example 1
    Derived1 d1;
    Derived2 d2;
    d1.interface(); // Output: Derived1 func implementation
    d2.interface(); // Output: Default func implementation

    // example 2
    FastComputation fast;
    AccurateComputation accurate;
    fast.execute();      // Output: Fast computation
    accurate.execute();  // Output: Accurate computation

    return 0;
}

