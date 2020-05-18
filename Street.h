//
//  main.cpp
//  dz2
//
//  Created by Броцкий Кирилл on 11/05/2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#pragma once
#include "House.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Street
{
    string Name, a, NumberOfH, ApplicOfHouse; // Название улицы, номера домов, назначения
    double Total_Rent; // полная стоимость аренды
    int Number_of_houses, CostOfRentH; // Кол-во домов, стоимость аренды.
    bool Disband; // редактировать улицу
    list <House> Houses; // Контейнер(список)
public:
    Street(); // Конструктор
    Street(string Name, int Number_of_workers); //Конструктор для инициализации полей класса
    void deleteHouse(); // Функция для удаления дома улицы
    void setNumber_of_houses(int new_Number_of_houses); // Сеттер для числа домов
    void changeParamHouse(); // Функция для изменения параметров дома
    void setDisband_Street(bool Disband_Department); // Функция для редактирования улицы
    double TotalRentS(); // функция для вычисления финальной стоимости аренды
    ~Street(); // Деструктор
    friend ostream & operator <<(ostream &cout, Street &E); // Перегрузка оператора вывода
    friend Street & operator +=(Street &G, House &F); // Перегрузка оператора присваивания(с добавлением домов (+))...Нужен т к в объекте есть данные из динамической памяти
};
