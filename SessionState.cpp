#include "SessionState.h"
#include "Hall.h"
#include "CleaningState.h"
#include <iostream>
using namespace std;

// Во время сеанса нельзя менять расписание
void SessionState::addSession(Hall* hall, const string& sessionName) {
    cout << "[SessionState] Нельзя изменить расписание: идёт сеанс!" << endl;
}

void SessionState::prepare(Hall* hall) {
    cout << "[SessionState] Нельзя подготовить: уже идёт сеанс" << endl;
}

void SessionState::startSession(Hall* hall) {
    cout << "[SessionState] Сеанс уже идёт" << endl;
}

// Завершаем сеанс и переходим к уборке
void SessionState::endSession(Hall* hall) {
    cout << "[SessionState] Сеанс завершён. Начинаем уборку" << endl;
    hall->setState(new CleaningState()); // Переход в состояние "уборка"
}

void SessionState::clean(Hall* hall) {
    cout << "[SessionState] Нельзя убирать: сначала завершите сеанс" << endl;
}

string SessionState::getStateName() const {
    return "Session";
}