#include "Hall.h"
#include "FreeState.h"
#include <iostream>

using namespace std;

// Конструктор: создаём зал в состоянии Free (свободен)
Hall::Hall() {
    state = new FreeState(); // Начальное состояние - свободен
    schedule = new Schedule(); // Создаём пустое расписание
    currentSessionName = "";
    cout << "[Hall] Создан новый кинозал. Начальное состояние: " << state->getStateName() << endl;
}

// Деструктор: освобождаем память
Hall::~Hall() {
    delete state;      // Удаляем текущее состояние
    delete schedule;   // Удаляем расписание
}

// Изменение состояния - ГЛАВНЫЙ МЕТОД ДЛЯ OBSERVER
// Отсюда отправляются все уведомления наблюдателям
void Hall::setState(HallState* newState) {
    delete state;                   // Удаляем старое состояние
    state = newState;               // Устанавливаем новое
    notifyObservers("state_changed", state->getStateName()); // ОТПРАВЛЯЕМ УВЕДОМЛЕНИЕ ВСЕМ ПОДПИСЧИКАМ
    cout << "[Hall] Состояние изменено на: " << state->getStateName() << endl;
}

// Вернуть указатель на текущее состояние
HallState* Hall::getState() const {
    return state;
}

// Вернуть название текущего состояния
string Hall::getStateName() const {
    return state->getStateName();
}

// Вернуть указатель на расписание
Schedule* Hall::getSchedule() const {
    return schedule;
}

// Установить имя текущего сеанса
void Hall::setCurrentSessionName(const string& name) {
    currentSessionName = name;
}

// Получить имя текущего сеанса
string Hall::getCurrentSessionName() const {
    return currentSessionName;
}

// ДЕЛЕГИРОВАНИЕ: Hall не знает, как выполнять операции,
// он просто передаёт их текущему состоянию
void Hall::addSession(const string& sessionName) {
    state->addSession(this, sessionName);
}

void Hall::prepare() {
    state->prepare(this);
}

void Hall::startSession() {
    state->startSession(this);
}

void Hall::endSession() {
    state->endSession(this);
}

void Hall::clean() {
    state->clean(this);
}

// Вывести текущий статус зала
void Hall::printStatus() const {
    cout << "=== Состояние зала ===" << endl;
    cout << "Текущее состояние: " << state->getStateName() << endl;
    schedule->print();
    cout << "======================" << endl;
}