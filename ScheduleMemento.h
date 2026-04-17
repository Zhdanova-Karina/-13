#pragma once

#include <string>
#include <vector>
#include <ctime>

using namespace std;
// Memento (Хранитель) - неизменяемый объект, который хранит снимок состояния Schedule
// Этот класс не имеет методов для изменения данных
class ScheduleMemento {
private:
    vector<string> sessions;    // Сохранённый список сеансов
    int version;                 // Версия расписания
    time_t timestamp;            // Время создания снимка

public:
    ScheduleMemento(const vector<string>& sessions, int version);

    vector<string> getSessions() const; // Вернуть сохранённый список сеансов
    int getVersion() const; // Вернуть сохранённую версию
    time_t getTimestamp() const;
    string getTimestampString() const;
};