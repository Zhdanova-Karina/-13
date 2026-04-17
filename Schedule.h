#pragma once

#include <string>
#include <vector>
#include "ScheduleMemento.h"
using namespace std;
// Создатель - объект, состояние которого мы сохраняем
// Может сохранить своё состояние в Memento и восстановиться из него
class Schedule {
private:
    vector<string> sessions;
    int version;

public:
    Schedule();

    void addSession(const string& sessionName);
    void removeSession(const string& sessionName);
    vector<string> getSessions() const;
    int getVersion() const;

    ScheduleMemento* save();
    void restore(ScheduleMemento* memento);

    void print() const;
};