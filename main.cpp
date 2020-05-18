//
//  main.cpp
//  dz2
//
//  Created by Броцкий Кирилл on 11/05/2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#include "Street.h"

int main() {
    string Name, a, FullName, Application;
    int Number_of_houses, CostOfRent, new_Number_of_houses;
    double Flats;
    bool Repair;
    Street A;
    House AA;
    cout << "Введите название улицы: ";
    getline(cin, Name);
    cout << "Введите количество домов на улице: ";
    cin >> Number_of_houses;
    A = Street(Name, Number_of_houses);
    cout << endl << "Введите данные домов: ";
    cout << endl;
    cin.ignore();
    for (int i = 0; i < Number_of_houses; i++) {
        cout << "Номер дома: ";
        getline(cin, FullName);
        cout << "Назначение: ";
        getline(cin, Application);
        cout << "Стоимость аренды: ";
        cin >> CostOfRent;
        cout << "Количество квартир: ";
        cin >> Flats;
        cout << "Требуется ли ремонт (YES/NO): ";
        cin >> a;
        cin.ignore();
        if (a == "YES")
            Repair = true;
        else
            Repair = false;
        AA = House(FullName, Application, CostOfRent, Flats, Repair);
        A += AA;
    }
    cout << A;
    cout << endl << "Введите новое количество домов на улице: ";
    cin >> new_Number_of_houses;
    if (Number_of_houses < new_Number_of_houses) {
        cout << "Добавить дом: " << endl;
        cin.ignore();
        for (int i = 0; i < (new_Number_of_houses - Number_of_houses); i++){
            cout << "Номер дома: ";
            getline(cin, FullName);
            cout << "Назначение: ";
            getline(cin, Application);
            cout << "Стоимость аренды: ";
            cin >> CostOfRent;
            cout << "Количество квартир: ";
            cin >> Flats;
            cout << "Требуется ли ремонт (YES/NO): ";
            cin >> a;
            cin.ignore();
            if (a == "YES")
                Repair = true;
            else
                Repair = false;
            AA = House(FullName, Application, CostOfRent, Flats, Repair);
            A += AA;
        }
    }
    else {
        cin.ignore();
        for (int i = 0; i < (Number_of_houses - new_Number_of_houses); i++)
            A.deleteHouse();
    }
    Number_of_houses = new_Number_of_houses;
    A.setNumber_of_houses(new_Number_of_houses);
    cout << A;
    cout << endl << "Новое количество домов на улице: ";
    cin >> new_Number_of_houses;
    if (Number_of_houses < new_Number_of_houses) {
        cout << "Добавить дом: " << endl;
        cin.ignore();
        for (int i = 0; i < (new_Number_of_houses - Number_of_houses); i++){
            cout << "Номер дома: ";
            getline(cin, FullName);
            cout << "Назначение: ";
            getline(cin, Application);
            cout << "Стоимость аренды: ";
            cin >> CostOfRent;
            cout << "Количество квартир: ";
            cin >> Flats;
            cout << "Требуется ли ремонт (YES/NO): ";
            cin >> a;
            cin.ignore();
            if (a == "YES")
                Repair = true;
            else
                Repair = false;
            AA = House(FullName, Application, CostOfRent, Flats, Repair);
            A += AA;
        }
    }
    else {
        cin.ignore();
        for (int i = 0; i < (Number_of_houses - new_Number_of_houses); i++)
            A.deleteHouse();
    }
    Number_of_houses = new_Number_of_houses;
    A.setNumber_of_houses(new_Number_of_houses);
    cout << A;
    cout << "Редактировать улицу? (YES/NO): ";
    cin >> a;
    cin.ignore();
    if (a == "YES")
        A.setDisband_Street(true);
    else
        A.setDisband_Street(false);
    cout << "Изменить параметры домов? (YES/NO): ";
    cin >> a;
    cin.ignore();
    if (a == "YES")
        A.changeParamHouse();
    cout << A;
    return 0;
}

