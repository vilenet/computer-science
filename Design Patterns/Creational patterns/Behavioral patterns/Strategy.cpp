// Pattern Strategy
#include <iostream>
#include <memory>

//
// Interface
// 
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() {}
    virtual void pay(int amount) = 0;
};

//
// Concrete Strategy 1
//
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
    }
};

//
// Concrete Strategy 2
//
class PaypalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using PayPal." << std::endl;
    }
};

//
// Context
//
class PaymentContext {
private:
    std::unique_ptr<PaymentStrategy> m_pStrategy;

public:
    PaymentContext(PaymentStrategy* pStrategy) : m_pStrategy(pStrategy) {}

    void executePayment(int amount) {
        return m_pStrategy->pay(amount);
    }

    void setStrategy(PaymentStrategy* pStrategy) { 
        m_pStrategy.reset(pStrategy); 
    }
};


int main() 
{
    PaymentContext context(new PaypalPayment());
    context.executePayment(100);

    context.setStrategy(new CreditCardPayment());
    context.executePayment(200);

    return 0;
}
