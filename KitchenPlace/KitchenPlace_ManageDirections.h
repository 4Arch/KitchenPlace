/**
    File    : KitchenPlace_ManageDirections.h
    Author  : Menashe Rosemberg
    Created : 2019.03.29            Version: 20190414.2

    Find the best places to install the kitchen on room nearest to all employees

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software developed to SQLLink internal use only.
**/
#ifndef KITCHENPLACE_MANDIR_H
#define KITCHENPLACE_MANDIR_H

#include "KitchenPlace.h"

#include <iostream>
#include <stack>

namespace Turn {
          constexpr uint8_t RT = 0b00000001;
          constexpr uint8_t DW = 0b00000010;
          constexpr uint8_t UP = 0b00000100;
          constexpr uint8_t LF = 0b00001000;

          constexpr uint8_t NW = 0b00001111;
}

using MiniMatrix = vector<vector<uint8_t>>;
constexpr uint8_t wall = numeric_limits<uint8_t>::max();

struct Directions {
       Directions(const Matrix& tMap,
                  uint32_t lin = LCLimit,
                  uint32_t col = LCLimit);

    LinCol NextStep();
    LinCol CurrPosition() const;

    bool HasUnreachablePlace();     //may return a false positive if this->NextStep() didn't finished to run over all reachable places
    //void Reset();                   //The object need to be reset after HasUnreachablePlace() had run

    private:
        const uint32_t dMapLinSize;
        const uint32_t dMapColSize;
        MiniMatrix dMap;
        uint32_t Lin;
        uint32_t Col;

        stack<LinCol> Visited;

        bool HasNoWay_Up() const;
        bool HasNoWay_Lf() const;
        bool HasNoWay_Dw() const;
        bool HasNoWay_Rt() const;

        inline void UpdateLinCol();
        void SetPossibleDirections4CurrPosition();
};


#endif // KITCHENPLACE_MANDIR_H