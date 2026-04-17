#include "PreparingState.h"
#include "Hall.h"
#include "SessionState.h"
#include <iostream>
using namespace std;

// Во время подготовки нельзя изменять расписание
void PreparingState::addSession(Hall* hall, const string& sessionName) {
    cout << "[PreparingState] Нельзя изменить расписание во время подготовки зала" << endl;
}

void PreparingState::prepare(Hall* hall) {
    cout << "[PreparingState] Подготовка уже выполняется" << endl;
}

// После подготовки можно начать сеанс
void PreparingState::startSession(Hall* hall) {
    cout << "[PreparingState] Подготовка завершена. Начинаем сеанс!" << endl;
    hall->setState(new SessionState());
}

void PreparingState::endSession(Hall* hall) {
    cout << "[PreparingState] Нельзя завершить сеанс: сеанс ещё не начался" << endl;
}

void PreparingState::clean(Hall* hall) {
    cout << "[PreparingState] Нельзя убирать: идёт подготовка к сеансу" << endl;
}

string PreparingState::getStateName() const {
    return "Preparing";
}