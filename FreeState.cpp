#include "FreeState.h"
#include "Hall.h"
#include "PreparingState.h"
#include <iostream>
using namespace std;

// В свободном состоянии разрешено добавлять сеансы
void FreeState::addSession(Hall* hall, const string& sessionName) {
    cout << "[FreeState] Сеанс \"" << sessionName << "\" добавлен в расписание" << endl;
    hall->getSchedule()->addSession(sessionName);
    // Уведомление не отправляем, т.к. состояние зала не меняется
}

// Можно начать подготовку к сеансу
void FreeState::prepare(Hall* hall) {
    cout << "[FreeState] Начинаем подготовку зала к сеансу" << endl;
    hall->setState(new PreparingState());
    hall->notifyObservers("state_changed", "Preparing");
}

// Нельзя начать сеанс без подготовки - выводим ошибку
void FreeState::startSession(Hall* hall) {
    cout << "[FreeState] Нельзя начать сеанс: зал свободен. Сначала выполните подготовку" << endl;
}

// Нельзя завершить сеанс, которого нет
void FreeState::endSession(Hall* hall) {
    cout << "[FreeState] Нельзя завершить сеанс: сеанс не идёт" << endl;
}

// Уборка не требуется
void FreeState::clean(Hall* hall) {
    cout << "[FreeState] Уборка не требуется: зал и так свободен" << endl;
}

// Вернуть название состояния
string FreeState::getStateName() const {
    return "Free";
}