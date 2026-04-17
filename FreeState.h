#pragma once

#include "HallState.h"
using namespace std;

// Состояние "зал свободен" - начальное состояние
// В этом состоянии можно добавлять сеансы и начинать подготовку
class FreeState : public HallState {
public:
    void addSession(Hall* hall, const string& sessionName) override;
    void prepare(Hall* hall) override;
    void startSession(Hall* hall) override;
    void endSession(Hall* hall) override;
    void clean(Hall* hall) override;
    string getStateName() const override;
};