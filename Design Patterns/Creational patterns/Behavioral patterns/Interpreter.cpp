#include <iostream>
#include <string>
using namespace std;

// Задает какой то контекст, класс который оказывает влияние на интерпретацию
class Context {
public:
    Context(){}
    ~Context(){}
};

class AbstractExpression {
protected:
    AbstractExpression(){}
public:
    virtual void Interpret(const Context& refContext) = 0;
    virtual ~AbstractExpression(){}
};


class TerminalExpression : public AbstractExpression {
private:
    string m_strStatement;

public:
    TerminalExpression(const string& strStatement) {
        m_strStatement = strStatement;
    }

    ~TerminalExpression() override {}

    void Interpret(const Context& refContext) override {
        cout << this->m_strStatement << "TerminalExpression" << endl;
    }
};


class NonTerminalExpression : public AbstractExpression {
private:
    AbstractExpression* m_pExpression = nullptr;
    int m_iTimes; // Количество раз сколько нужно пройти в глубину рекурсии

public:
    NonTerminalExpression(AbstractExpression* pExpression, int iTimes) {
        m_pExpression = pExpression;
        m_iTimes = iTimes;
    }

    ~NonTerminalExpression() override {
        m_pExpression = nullptr;
    }

    void Interpret(const Context& refContext) override {
        for (int i = 0; i < m_iTimes; i++) {
            this->m_pExpression->Interpret(refContext);
        }
    }
};

int main()
{
    Context *pContext = new Context();
    AbstractExpression* pTExpr   = new TerminalExpression("hello");
    AbstractExpression* pNTExptr = new NonTerminalExpression(pTExpr, 2);
    pNTExptr->Interpret(*pContext);
    
    delete pContext;
    delete pTExpr;
    delete pNTExptr;

    return 0;
}