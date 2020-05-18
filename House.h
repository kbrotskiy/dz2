//
//  main.cpp
//  dz2
//
//  Created by Броцкий Кирилл on 11/05/2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class House {
protected:
    string Number, Application; // Дом и его назначение
    int CostOfRent; // Стоимость аренды
    double Flats;
    bool RepairNeeded; // Ремонт дома
    
public:
    House(); // Конструктор
    House(string name, string app, int rent, double flats, bool repair);// Конструктор для инициализации полей
    double TotalCostOfRent(); // Функция для вычисления полной суммы стоимости аренды за весь дом
    void setRepair(bool Retraining); // Получение инфо для поля ремонт дома
    void SetCostOfRent(int New_percent_of_allowance); // Получение инфо для поля стоимости аренды
    void setApplication(string New_Job); // Получение инфо для назначения
    string getFullName(); // Получение инфо для поля номера дома
    ~House(); // Деструктор
    friend ostream & operator <<(ostream &cout, House &C);//перегрузка операции вывода cout
    friend bool operator <(const House &A, const House &B);//оператор сравнения
};
