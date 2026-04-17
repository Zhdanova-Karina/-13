#pragma once

#include "HallState.h"
using namespace std;

// Состояние "уборка" - после сеанса
// В этом состоянии нельзя добавлять сеансы и начинать подготовку
class CleaningState : public HallState {
public:
    void addSession(Hall* hall, const string& sessionName) override;
    void prepare(Hall* hall) override;
    void startSession(Hall* hall) override;
    void endSession(Hall* hall) override;
    void clean(Hall* hall) override;
    string getStateName() const override;
};