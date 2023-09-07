#include <gtest/gtest.h>
#include "RomanNumeralsSuite.h"

using namespace std;

string convert(int arabic) {
    string roman;
    int start;

    if (arabic >= 10 ) {
        roman = "X";
        start = 10;
    } else {
        if (arabic >= 5) {
            start = 5;
            roman = "V";
        } else {
            start = 0;
            roman = "";
        }
    }

    for (int i = start; i < arabic; i++) {
        roman += "I";
    }

    return roman;
}

TEST_P(RomanNumeralsSuite, convert_arabic_numbers_into_roman_numerals) {
    tuple<int, string> param = GetParam();
    EXPECT_EQ(convert(get<0>(param)), get<1>(param)) << "I was expecting '" << get<1>(param) << "' but got '" << convert(get<0>(param)) << "' instead";
}

INSTANTIATE_TEST_SUITE_P(
        MeenyMinyMoe,
        RomanNumeralsSuite,
        testing::Values(
                make_tuple(1, "I")
                ,make_tuple(2, "II")
                ,make_tuple(3, "III")
                ,make_tuple(5, "V")
                ,make_tuple(6, "VI")
                ,make_tuple(10, "X")
                ,make_tuple(11, "XI")
        )
);