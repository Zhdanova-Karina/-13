#pragma once

#include "ScheduleMemento.h"
#include "Schedule.h"
#include <deque>
#include <stack>
using namespace std;

class ScheduleCaretaker {
private:
    deque<ScheduleMemento*> undoDeque;   // Очередь с двух сторон (для undo)
    stack<ScheduleMemento*> redoStack;   // Стек для redo
    int maxHistorySize;

public:
    ScheduleCaretaker(int maxHistorySize = 20);
    ~ScheduleCaretaker();

    void saveState(Schedule* schedule);
    bool undo(Schedule* schedule);
    bool redo(Schedule* schedule);
    void clear();
    void setMaxHistorySize(int size);
};