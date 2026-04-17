#pragma once

#include "Observer.h"
#include <iostream>

using namespace std;
// Информационное табло - наблюдатель за изменениями состояния зала
// Обновляет информацию на экране в зале
class DisplayBoard : public Observer {
private:
    string hallName;

public:
    DisplayBoard(const string& hallName);
    void update(const string& eventType, const string& data) override;
    string getName() const override;
};