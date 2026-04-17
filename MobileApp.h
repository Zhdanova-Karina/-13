#pragma once

#include "Observer.h"
#include <iostream>

using namespace std;
// Мобильное приложение - наблюдатель за изменениями состояния зала
// Отправляет push-уведомления пользователям
class MobileApp : public Observer {
private:
    string userName;

public:
    MobileApp(const string& userName);
    void update(const string& eventType, const string& data) override;
    string getName() const override;
};