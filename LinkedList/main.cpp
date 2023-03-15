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
    cout << "������: " << list.size() << endl;
    cout << "������ �������: " << list.front() << endl;
    cout << "��������� �������: " << list.back() << endl;
    cout << "������: ";
    for (size_t i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    list.pop_back();
    list.pop_front();
    list.remove_at(1);
    cout << "������ ����� ���������: " << list.size() << endl;
    cout << "������: ";
    for (size_t i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    list.clear();
    cout << "������ ����� �������: " << list.size() << endl;
    return 0;
}