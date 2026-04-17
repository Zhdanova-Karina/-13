#pragma once

#include "Observer.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// Subject - интерфейс для объектов,за которыми наблюдают. Hall наследует этот класс.
class Subject {
private:
    vector<Observer*> observers; // Список подписанных наблюдателей

public:
    // Подписать наблюдателя
    void attach(Observer* observer) {
        observers.push_back(observer);
        cout << "[Subject] Подписан наблюдатель: " << observer->getName() << endl;
    }
    // Отписать наблюдателя
    void detach(Observer* observer) {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
            cout << "[Subject] Отписан наблюдатель: " << observer->getName() << endl;
        }
    }
    // Уведомить всех наблюдателей о событии
    void notifyObservers(const string& eventType, const string& data) {
        for (Observer* observer : observers) {
            observer->update(eventType, data);
        }
    }
};