#pragma once

#include "HallState.h"
#include "Schedule.h"
#include "Subject.h"
#include <string>

using namespace std;

class Hall : public Subject {
private:
    HallState* state; // Текущее состояние зала
    Schedule* schedule; // Расписание сеансов
    string currentSessionName; // Имя текущего сеанса

public:
    Hall();
    ~Hall();

    // Управление состоянием
    void setState(HallState* newState); // Изменить состояние
    HallState* getState() const;
    string getStateName() const;

    Schedule* getSchedule() const; // Доступ к расписанию (для Memento)
    // Управление текущим сеансом
    void setCurrentSessionName(const string& name);
    string getCurrentSessionName() const;

    // Методы, которые делегируют поведение текущему состоянию
    void addSession(const string& sessionName);
    void prepare();
    void startSession();
    void endSession();
    void clean();

    void printStatus() const;
};