#pragma once

#include "HallState.h"
using namespace std;

// Состояние "подготовка к сеансу" - включается оборудование
// В этом состоянии нельзя изменять расписание
class PreparingState : public HallState {
public:
    void addSession(Hall* hall, const string& sessionName) override;
    void prepare(Hall* hall) override;
    void startSession(Hall* hall) override;
    void endSession(Hall* hall) override;
    void clean(Hall* hall) override;
    string getStateName() const override;
};