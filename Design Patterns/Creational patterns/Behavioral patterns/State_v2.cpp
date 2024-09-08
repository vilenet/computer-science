#include <iostream>

class Context;
class State {
protected:
    Context* m_pContext;
public:
    virtual ~State() {}
    void set_context(Context* pContext) {
        m_pContext = pContext;
    }
    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
};

class PlayingState : public State {
public:
    void play() override {
        std::cout << "Already playing.\n";
    }
    void pause() override {
        std::cout << "Pausing playback.\n";
        m_pContext->TransitionTo(new PausedState());
    }
    void stop() override {
        std::cout << "Stopping playback.\n";
        m_pContext->TransitionTo(new StoppedState());
    }
};

class PausedState : public State {
public:
    void play() override {
        std::cout << "Resuming playback.\n";
        m_pContext->TransitionTo(new PlayingState());
    }
    void pause() override {
        std::cout << "Already paused.\n";
    }
    void stop() override {
        std::cout << "Stopping playback from pause.\n";
        m_pContext->TransitionTo(new StoppedState());
    }
};

class StoppedState : public State {
public:
    void play() override {
        std::cout << "Starting playback.\n";
        m_pContext->TransitionTo(new PlayingState());
    }
    void pause() override {
        std::cout << "Can't pause. The player is stopped.\n";
    }
    void stop() override {
        std::cout << "Already stopped.\n";
    }
};

class Context {
private:
    State* m_pState;
public:
    Context(State* pState) : m_pState(pState) {
        pState->set_context(this);
    }
    ~Context() {
        delete m_pState;
    }
    void TransitionTo(State* pState) {
        std::cout << "Transition to " << typeid(*pState).name() << ".\n";
        delete m_pState;
        m_pState = pState;
        pState->set_context(this);
    }
    void play() { m_pState->play(); }
    void pause() { m_pState->pause(); }
    void stop() { m_pState->stop(); }
};

void ClientCode() {
    Context* context = new Context(new StoppedState());
    context->play();
    context->pause();
    context->play();
    context->stop();
    delete context;
}

int main() {
    ClientCode();
    return 0;
}
