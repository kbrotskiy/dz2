//
//  main.cpp
//  dz2
//
//  Created by Броцкий Кирилл on 11/05/2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#include <stdio.h>
#include "Street.h"

Street::Street() {
    Name = ApplicOfHouse = a = NumberOfH =' ';
     Number_of_houses = CostOfRentH = Total_Rent = 0;
    Disband = false;
}

Street::Street(string Name, int Number_of_h) {
    this->Name = Name;
    this->Number_of_houses = Number_of_h;
    this->Disband = false;
}

void Street::deleteHouse() {
    cout << "Введите номер дома, который вы хотите удалить: ";
    getline(cin, NumberOfH);
    for (auto iter = Houses.begin(); iter != Houses.end(); ++iter) {
        if (iter->getFullName() == NumberOfH) {
            Houses.erase(iter);
            break;
        }
    }
}

void Street::setNumber_of_houses(int new_Number_of_houses) {
    Number_of_houses = new_Number_of_houses;
}

void Street::changeParamHouse() {
    cout << "Введите номер дома, параметры которого вы хотели бы изменить: ";
    getline(cin, NumberOfH);
    for (auto iter = Houses.begin(); iter != Houses.end(); ++iter)
    {
        if (iter->getFullName() == NumberOfH) {
            cout << "Сделать ремонт дома? (YES/NO): ";
            cin >> a;
            cin.ignore();
            if (a == "YES") {
                iter->setRepair(true); }
            else {
                iter->setRepair(false); }
            cout << "Изменить стоимость аренды? (YES/NO): ";
            cin >> a;
            cin.ignore();
            if (a == "YES") {
                cout << "Введите новую стоимость аренды: ";
                cin >> CostOfRentH;
                iter->SetCostOfRent(CostOfRentH);
            }
            cout << "Изменить назначение? (YES/NO): ";
            cin >> a;
            cin.ignore();
            if (a == "YES") {
                cout << "Введите новое назначение: ";
                getline(cin, ApplicOfHouse);
                iter->setApplication(ApplicOfHouse);
            }
            break;
        }
    }
}

void Street::setDisband_Street(bool Disband_Department) {
    this->Disband = Disband_Department;
}

double Street::TotalRentS() {
    Total_Rent = 0.;
    for (auto iter = Houses.begin(); iter != Houses.end(); ++iter)
        Total_Rent = iter->TotalCostOfRent() + Total_Rent;
    return Total_Rent;
}

Street::~Street() {
    Houses.clear();
}

ostream & operator <<(ostream &cout, Street &E) {
    cout << endl << "Улица: " << E.Name << endl<< "Количество домов: " << E.Number_of_houses << endl << "Список домов: " << endl;
    E.Houses.sort();
    for (auto iter = E.Houses.begin(); iter != E.Houses.end(); ++iter)
        cout << *iter << endl;
    cout << "Учет аренды со всех домов: " << E.TotalRentS() << endl;
    return cout;
}

Street & operator +=(Street &G, House &F) {
    G.Houses.push_back(F);
    return G;
}
