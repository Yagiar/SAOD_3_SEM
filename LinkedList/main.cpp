#include <iostream>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include "LinkedList.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main()
{
    setlocale(0, "Russian");
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.insert(2, 10);
    cout << "Размер: " << list.size() << endl;
    cout << "Первый элемент: " << list.front() << endl;
    cout << "Последний элемент: " << list.back() << endl;
    cout << "Список: ";
    for (size_t i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    list.pop_back();
    list.pop_front();
    list.remove_at(1);
    cout << "Размер после изменения: " << list.size() << endl;
    cout << "Список: ";
    for (size_t i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    list.clear();
    cout << "Размер после очистки: " << list.size() << endl;
    return 0;
}