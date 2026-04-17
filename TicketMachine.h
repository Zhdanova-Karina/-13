#pragma once

#include "Observer.h"
#include <iostream>

using namespace std;
// Билетный автомат - наблюдатель за изменениями состояния зала
class TicketMachine : public Observer {
private:
    string location; // Расположение автомата (например "Entrance", "Lobby")

public:
    TicketMachine(const string& location);
    void update(const string& eventType, const string& data) override; // Реакция на уведомления
    string getName() const override; // Возвращает имя наблюдателя
};