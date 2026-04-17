#include "DisplayBoard.h"

using namespace std;

DisplayBoard::DisplayBoard(const string& hallName) : hallName(hallName) {}

void DisplayBoard::update(const string& eventType, const string& data) {
    if (eventType == "state_changed") {
        cout << "[DisplayBoard:" << hallName << "] Состояние зала: " << data << endl;

        if (data == "Session") {
            cout << "  СЕЙЧАС ИДЁТ СЕАНС" << endl;
        }
        else if (data == "Free") {
            cout << "  ЗАЛ СВОБОДЕН" << endl;
        }
        else if (data == "Preparing") {
            cout << "  ИДЁТ ПОДГОТОВКА" << endl;
        }
        else if (data == "Cleaning") {
            cout << "  ИДЁТ УБОРКА" << endl;
        }
    }
}

string DisplayBoard::getName() const {
    return "DisplayBoard_" + hallName;
}