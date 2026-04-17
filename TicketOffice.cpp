#include "TicketOffice.h"

using namespace std;

TicketOffice::TicketOffice(const string& name) : name(name) {}

void TicketOffice::update(const string& eventType, const string& data) {
    
    if (eventType == "state_changed") {
        cout << "[TicketOffice:" << name << "] Состояние зала: " << data << endl;

        if (data == "Session") {
            cout << "  Прекращаем продажу билетов (идёт сеанс)" << endl;
        }
        else if (data == "Free") {
            cout << "  Возобновляем продажу билетов (зал свободен)" << endl;
        }
    }
}

string TicketOffice::getName() const {
    return "TicketOffice_" + name;
}