//
// Created by mauro on 7/09/23.
//

#ifndef ROMAN_NUMERALS_ROMANNUMERALSCONVERTER_H
#define ROMAN_NUMERALS_ROMANNUMERALSCONVERTER_H

#include <string>
#include <forward_list>
#include <tuple>

using namespace std;

class RomanNumeralsConverter {
    forward_list<tuple<int, string>> arabic2roman = {
            make_tuple(1000, "M")
            , make_tuple(900, "CM")
            , make_tuple(500, "D")
            , make_tuple(400, "CD")
            , make_tuple(100, "C")
            , make_tuple(90, "XC")
            , make_tuple(50, "L")
            , make_tuple(40, "XL")
            , make_tuple(10, "X")
            , make_tuple(9, "IX")
            , make_tuple(5, "V")
            , make_tuple(4, "IV")
            , make_tuple(1, "I")
    };

public:
    string convert(int arabic);
};


#endif //ROMAN_NUMERALS_ROMANNUMERALSCONVERTER_H
