#pragma once

#include <string>
using namespace std;
// Observer (Ќаблюдатель) - интерфейс дл€ всех объектов,которые хот€т получать уведомлени€ от Subject
class Observer {
public:
    virtual ~Observer() = default;
    // Ётот метод вызываетс€ Subject при изменении состо€ни€
    // eventType - тип событи€ (например "state_changed")
    // data - дополнительные данные (название состо€ни€)
    virtual void update(const string& eventType, const string& data) = 0;
    virtual string getName() const = 0; // ¬озвращает им€ наблюдател€
};