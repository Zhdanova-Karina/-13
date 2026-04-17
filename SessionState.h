#pragma once

#include "HallState.h"
using namespace std;

// Состояние "идёт сеанс" - показ фильма
// В этом состоянии нельзя изменять расписание и оборудование
class SessionState : public HallState {
public:
    void addSession(Hall* hall, const string& sessionName) override;
    void prepare(Hall* hall) override;
    void startSession(Hall* hall) override;
    void endSession(Hall* hall) override;
    void clean(Hall* hall) override;
    string getStateName() const override;
};