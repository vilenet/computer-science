#include <iostream>

class Singleton
{
public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }

    void testMethod(){
        std::cout << "Hello from Singleton!" << std::endl;
    }

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

private:
    Singleton(){}
    ~Singleton(){}
};

int main()
{
    Singleton& instance = Singleton::getInstance();
    instance.testMethod();

    //Singleton anotherInstance; // Compilation error
    return 0;
}