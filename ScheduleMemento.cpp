#include "ScheduleMemento.h"
#include <sstream>
#include <iomanip>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

ScheduleMemento::ScheduleMemento(const vector<string>& sessions, int version)
    : sessions(sessions), version(version) {
    timestamp = time(nullptr);
}

vector<string> ScheduleMemento::getSessions() const {
    return sessions;
}

int ScheduleMemento::getVersion() const {
    return version;
}

time_t ScheduleMemento::getTimestamp() const {
    return timestamp;
}

string ScheduleMemento::getTimestampString() const {
    stringstream ss;

    struct tm timeInfo;
    localtime_s(&timeInfo, &timestamp);
    ss << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

    return ss.str();
}