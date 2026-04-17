#pragma once

#include <string>
using namespace std;
class Hall; // объявление класса Hall для избежания циклической зависимости

// Абстрактный класс - интерфейс для всех состояний зала
// Каждое конкретное состояние должно реализовать все эти методы
class HallState {
public:
    virtual ~HallState() = default;
 
    virtual void addSession(Hall* hall, const std::string& sessionName) = 0;// Добавить сеанс в расписание
    virtual void prepare(Hall* hall) = 0; // Начать подготовку зала к сеансу
    virtual void startSession(Hall* hall) = 0; // Начать показ фильма
    virtual void endSession(Hall* hall) = 0; // Завершить показ фильма
    virtual void clean(Hall* hall) = 0; // Произвести уборку зала

    virtual string getStateName() const = 0;// Вернуть название текущего состояния
};