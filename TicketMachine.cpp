#include "TicketMachine.h"

using namespace std;

TicketMachine::TicketMachine(const string& location) : location(location) {}

void TicketMachine::update(const string& eventType, const string& data) {
    if (eventType == "state_changed") {
        cout << "[TicketMachine:" << location << "] Состояние зала: " << data << endl;

        if (data == "Session") {
            cout << "  БЛОКИРУЕМ продажу (идёт сеанс)" << endl;
        }
        else if (data == "Free") {
            cout << "  РАЗБЛОКИРУЕМ продажу (зал свободен)" << endl;
        }
    }
}

string TicketMachine::getName() const {
    return "TicketMachine_" + location;
}