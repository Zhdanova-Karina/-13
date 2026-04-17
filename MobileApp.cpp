#include "MobileApp.h"

using namespace std;

MobileApp::MobileApp(const string& userName) : userName(userName) {}

void MobileApp::update(const string& eventType, const string& data) {
    if (eventType == "state_changed") {
        cout << "[MobileApp:" << userName << "] Состояние зала: " << data << endl;

        if (data == "Session") {
            cout << "  Сеанс начался!" << endl;
        }
        else if (data == "Free") {
            cout << "  Зал свободен, приходите!" << endl;
        }
        else if (data == "Preparing") {
            cout << "  Скоро начнётся, готовьтесь!" << endl;
        }
        else if (data == "Cleaning") {
            cout << "  Идёт уборка, скоро откроемся" << endl;
        }
    }
}

string MobileApp::getName() const {
    return "MobileApp_" + userName;
}