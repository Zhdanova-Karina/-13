#include "ScheduleCaretaker.h"
#include <iostream>
using namespace std;

ScheduleCaretaker::ScheduleCaretaker(int maxHistorySize) : maxHistorySize(maxHistorySize) {}

ScheduleCaretaker::~ScheduleCaretaker() {
    clear();
}

void ScheduleCaretaker::saveState(Schedule* schedule) {
    // При новом действии очищаем redo стек
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }

    // Если превышен лимит - удаляем САМЫЙ СТАРЫЙ снимок (в начале очереди)
    if ((int)undoDeque.size() >= maxHistorySize) {
        delete undoDeque.front();  // ? удаляем самый старый
        undoDeque.pop_front();      // ? убираем из начала
    }

    // Добавляем новый снимок в конец очереди
    undoDeque.push_back(schedule->save());
    cout << "[Caretaker] Состояние сохранено. История: " << undoDeque.size() << endl;
}
// Отменить последнее действие
bool ScheduleCaretaker::undo(Schedule* schedule) {
    if (undoDeque.empty()) {
        cout << "[Caretaker] Нечего отменять" << endl;
        return false;
    }

    // Сохраняем текущее состояние в redo стек
    redoStack.push(schedule->save());

    // Достаём последний снимок (из конца очереди)
    ScheduleMemento* lastMemento = undoDeque.back();
    undoDeque.pop_back();

    // Если после удаления остались снимки - восстанавливаем последний
    if (!undoDeque.empty()) {
        schedule->restore(undoDeque.back());
    }
    else {
        // Если снимков не осталось - создаём пустое состояние
        schedule->restore(lastMemento);  // или очищаем расписание
    }

    delete lastMemento; // Удаляем использованный снимок
    cout << "[Caretaker] Выполнен UNDO. История: " << undoDeque.size() << endl;
    return true;
}

bool ScheduleCaretaker::redo(Schedule* schedule) {
    if (redoStack.empty()) {
        cout << "[Caretaker] Нечего повторять" << endl;
        return false;
    }

    // Сохраняем текущее состояние в очередь
    undoDeque.push_back(schedule->save());

    // Восстанавливаем из redo стека
    schedule->restore(redoStack.top());
    delete redoStack.top();
    redoStack.pop();

    cout << "[Caretaker] Выполнен REDO. История: " << undoDeque.size() << endl;
    return true;
}
// Очистить всю историю (удалить все снимки из обоих контейнеров)
void ScheduleCaretaker::clear() {
    while (!undoDeque.empty()) {
        delete undoDeque.front();
        undoDeque.pop_front();
    }
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}
// Установить новый лимит истории
void ScheduleCaretaker::setMaxHistorySize(int size) {
    maxHistorySize = size;
}