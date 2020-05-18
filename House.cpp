//
//  main.cpp
//  dz2
//
//  Created by Броцкий Кирилл on 11/05/2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#include <stdio.h>
#include "House.h"

House::House() // Конструктор без параметров
{
    Number = Application = ' ';
    CostOfRent = Flats = 0;
    RepairNeeded = false;
}

House::House(string name, string app, int rent, double flats, bool repair) // Конструктор для инициализации полей
{
    this->Number = name;
    this->Application = app;
    this->CostOfRent = rent;
    this->Flats = flats;
    this->RepairNeeded = repair;
}

double House::TotalCostOfRent() // Функция для вычисления финальной стоимости аренды
{
    return Flats * CostOfRent;
}

void House::setRepair(bool rep) // получение информации о ремонте
{
    this->RepairNeeded = rep;
}

void House::SetCostOfRent(int new_rent) // получение стоимости аренды
{
    CostOfRent = new_rent;
}

void House::setApplication(string new_app) // установка назначения для поля
{
    Application = new_app;
}

string House::getFullName() // получение номера дома
{
    return Number;
}

House::~House() // Деструктор
{
}

bool operator <(const House &A, const House &B) // Оператор сравнения
{
    return A.Number < B.Number;
}

ostream & operator <<(ostream &cout, House &C) //перегрузка оператора вывода
{
    return cout << "Номер дома: " << C.Number << endl << "Назначение: " << C.Application << endl << "Количество квартир: " << C.Flats << endl
    << "Стоимость аренды: " << C.CostOfRent << endl << "Аренда со всего дома: " << C.TotalCostOfRent() << endl
    << "Требуется ли ремонт: " << boolalpha << C.RepairNeeded << endl;
}
