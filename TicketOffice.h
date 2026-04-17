#pragma once

#include "Observer.h"
#include <iostream>

using namespace std;

// Касса кинотеатра - наблюдатель за изменениями состояния зала
// Реагирует на начало сеанса (прекращает продажу билетов)
class TicketOffice : public Observer {
private:
    string name;

public:
    TicketOffice(const string& name);
    void update(const string& eventType, const string& data) override;
    string getName() const override;
};