#include "Schedule.h"
#include <iostream>
#include <algorithm>
using namespace std;

Schedule::Schedule() : version(0) {}

void Schedule::addSession(const string& sessionName) {
    sessions.push_back(sessionName);
    version++;
    cout << "[Schedule] Добавлен сеанс: " << sessionName << " (версия: " << version << ")" << endl;
}

void Schedule::removeSession(const string& sessionName) {
    auto it = find(sessions.begin(), sessions.end(), sessionName);
    if (it != sessions.end()) {
        sessions.erase(it);
        version++;
        cout << "[Schedule] Удалён сеанс: " << sessionName << " (версия: " << version << ")" << endl;
    }
}

vector<string> Schedule::getSessions() const {
    return sessions;
}

int Schedule::getVersion() const {
    return version;
}

ScheduleMemento* Schedule::save() {
    // Создаём новый Memento с копией текущих данных
    cout << "[Schedule] Сохраняем снимок состояния (версия: " << version << ")" << endl;
    return new ScheduleMemento(sessions, version);
}

void Schedule::restore(ScheduleMemento* memento) {
    //текущее расписание полностью заменяется данными из снимка.
    if (memento) {
        sessions = memento->getSessions();   // Восстанавливаем список
        version = memento->getVersion();      // Восстанавливаем версию
        cout << "[Schedule] Восстановлено состояние от " << memento->getTimestampString()
            << " (версия: " << version << ")" << endl;
    }
}

void Schedule::print() const {
    cout << "Расписание (версия " << version << "): ";
    if (sessions.empty()) {
        cout << "(пусто)";
    }
    else {
        for (size_t i = 0; i < sessions.size(); i++) {
            cout << sessions[i];
            if (i < sessions.size() - 1) cout << ", ";
        }
    }
    cout << endl;
}