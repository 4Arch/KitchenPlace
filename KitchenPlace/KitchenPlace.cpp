/**
    File    : KitchenPlace.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.28            Version: 20190415.2

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KitchenPlace_ReadMap.h"
#include "KitchenPlace_MapEmployees.h"
#include "KitchenPlace_ManageDirections.h"
#include "KitchenPlace_FindShortWays.h"
#include "KitchenPlace_PutKitchen.h"
#include "KitchenPlace_ERROR.h"

static void CheckEmptySpaces(const Matrix& tMap) {
       Directions D(tMap);

       if (D.HasUnreachablePlace())
          ERROR("\n\nThis Map has unreachable place(s)\n");
}

int main() {
    vector<string> sMap = ReadMap();

    for (uint16_t Lin = 0; Lin < sMap.size(); ++Lin)        //Print Original Map
        cout << '\n' << sMap[Lin];
    cout << "\n*Original map.\n\n";

    auto Employees = CreateEnployeesList(sMap);

    if (Employees.empty())
       cerr << "\n\nNo Employees were found in this map\n\n";

    CheckEmptySpaces(Employees[0].second);

    for (auto& Emp : Employees) {
        ShortWayFinder SWF(Emp.first, Emp.second);
        SWF.SetDistancesOnMap();
    }

    PutKitchen(Employees);

    return 0;
}
