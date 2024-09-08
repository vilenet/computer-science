// Pattern State v1
#include <iostream>
#include <string>
#include <memory>

class Context;

//
// Interface
//
class State {
public:
    virtual ~State(){}
    virtual void doAction(Context* pContext) = 0;
};

//
// Context
//
class Context {
private:
    std::unique_ptr<State> m_pState;
    mutable std::string m_strStatus;

public:
    void setState(State* pState) {
        m_pState.reset(pState); 
        m_pState->doAction(this);
    }

    void setStatus(const std::string& strStatus) const {
        m_strStatus = strStatus;
    }

    void displayStatus() const {
        std::cout << m_strStatus << std::endl;
    }
};

//
// State 1
//
class StartState: public State {
public:
    void doAction(Context* pContext) override {
        pContext->setStatus("Player is in start state");
        pContext->displayStatus();  // Display the updated status
    }
};

//
// State 2
//
class StopState: public State {
public:
    void doAction(Context* pContext) override {
        pContext->setStatus("Player is in stop state");
        pContext->displayStatus();  // Display the updated status
    }
};


int main()
{
    Context context;
    context.setState(new StartState());
    context.setState(new StopState());

    return 0;
}

