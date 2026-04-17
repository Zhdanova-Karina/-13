#include "CleaningState.h"
#include "Hall.h"
#include "FreeState.h"
#include <iostream>

using namespace std;

void CleaningState::addSession(Hall* hall, const string& sessionName) {
    cout << "[CleaningState] Нельзя добавить сеанс: идёт уборка" << endl;
}

void CleaningState::prepare(Hall* hall) {
    cout << "[CleaningState] Нельзя подготовить: сначала завершите уборку" << endl;
}

void CleaningState::startSession(Hall* hall) {
    cout << "[CleaningState] Нельзя начать сеанс: сначала завершите уборку" << endl;
}

void CleaningState::endSession(Hall* hall) {
    cout << "[CleaningState] Сеанс не идёт" << endl;
}

void CleaningState::clean(Hall* hall) {
    cout << "[CleaningState] Уборка завершена. Зал снова свободен" << endl;
    hall->setState(new FreeState());
}

string CleaningState::getStateName() const {
    return "Cleaning";
}