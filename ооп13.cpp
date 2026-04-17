#include <iostream>
#include "Hall.h"
#include "ScheduleCaretaker.h"
#include "TicketOffice.h"
#include "TicketMachine.h"
#include "MobileApp.h"
#include "DisplayBoard.h"
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "\n========================================" << endl;
    cout << "  ЛАБОРАТОРНАЯ РАБОТА №12" << endl;
    cout << "  Паттерны: State, Memento, Observer" << endl;
    cout << "========================================\n" << endl;

    // ========== 1. СОЗДАНИЕ СИСТЕМЫ ==========
    cout << "=== 1. Инициализация системы ===" << endl;

    Hall* hall = new Hall(); // Создаём зал
    ScheduleCaretaker* caretaker = new ScheduleCaretaker(10); // Создаём опекуна для сохранения истории расписания (Memento)

    // Создаём наблюдателей (Observer)
    TicketOffice* ticketOffice = new TicketOffice("Main");      // Касса
    TicketMachine* ticketMachine = new TicketMachine("Entrance"); // Билетный автомат
    MobileApp* mobileApp = new MobileApp("User123");            // Мобильное приложение
    DisplayBoard* displayBoard = new DisplayBoard("Hall A");    // Информационное табло

    // Подписываем наблюдателей на события зала
    hall->attach(ticketOffice);
    hall->attach(ticketMachine);
    hall->attach(mobileApp);
    hall->attach(displayBoard);

    cout << endl;

    // ========== 2. РАБОТА С РАСПИСАНИЕМ (MEMENTO) ==========
    cout << "=== 2. Работа с расписанием (Memento) ===" << endl;

    caretaker->saveState(hall->getSchedule()); // Сохраняем пустое расписание
    // Добавляем первый сеанс и сохраняем
    hall->addSession("Аватар: Путь воды");
    caretaker->saveState(hall->getSchedule());
    // Добавляем второй сеанс и сохраняем
    hall->addSession("Оппенгеймер");
    caretaker->saveState(hall->getSchedule());

    hall->getSchedule()->print(); // Выводим текущее расписание
    cout << endl;

    cout << "--- Отмена последнего действия (undo) ---" << endl;
    caretaker->undo(hall->getSchedule());
    hall->getSchedule()->print();
    cout << endl;

    cout << "--- Возврат отменённого (redo) ---" << endl;
    caretaker->redo(hall->getSchedule());
    hall->getSchedule()->print();
    cout << endl;

    // ========== 3. РАБОТА С СОСТОЯНИЯМИ ЗАЛА (STATE) ==========
    cout << "=== 3. Работа с состояниями зала (State) ===" << endl;

    hall->printStatus();
    cout << endl;

    cout << "--- Попытка начать сеанс без подготовки ---" << endl;
    hall->startSession();
    cout << endl;

    cout << "--- Правильная последовательность ---" << endl;
    hall->setCurrentSessionName("Аватар: Путь воды");
    hall->prepare();
    cout << endl;

    cout << "--- Попытка добавить сеанс во время подготовки ---" << endl;
    hall->addSession("Дюна: Часть вторая");
    cout << endl;

    cout << "--- Начало сеанса ---" << endl;
    hall->startSession();
    cout << endl;

    cout << "--- Попытка изменить расписание во время сеанса ---" << endl;
    hall->addSession("Барби");
    cout << endl;

    cout << "--- Завершение сеанса ---" << endl;
    hall->endSession();
    cout << endl;

    cout << "--- Уборка ---" << endl;
    hall->clean();
    cout << endl;

    hall->printStatus();
    cout << endl;

    // ========== 4. ДЕМОНСТРАЦИЯ ОТПИСКИ ==========
    cout << "=== 4. Отписка наблюдателя ===" << endl;
    hall->detach(mobileApp);

    hall->addSession("Новый сеанс после отписки");
    cout << endl;

    // ========== 5. ОЧИСТКА ==========
    cout << "=== 5. Очистка ===" << endl;

    delete displayBoard;
    delete mobileApp;
    delete ticketMachine;
    delete ticketOffice;
    delete caretaker;
    delete hall;

    cout << "\n========================================" << endl;
    cout << "  Работа программы завершена" << endl;
    cout << "========================================" << endl;

    return 0;
}