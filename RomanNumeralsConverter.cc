//
// Created by mauro on 7/09/23.
//

#include "RomanNumeralsConverter.h"

string RomanNumeralsConverter::convert(int arabic) {
    string roman;

    for (auto &it: arabic2roman) {
        while (arabic >= get<0>(it)) {
            roman += get<1>(it);
            arabic -= get<0>(it);
        }
    }

    return roman;
}
