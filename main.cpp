#include <gtest/gtest.h>
#include "RomanNumeralsSuite.h"

#define THRESHOLDS 7

using namespace std;

tuple<int, string> arabic2roman[THRESHOLDS] = {
        make_tuple(1000, "M")
        , make_tuple(500, "D")
        , make_tuple(100, "C")
        , make_tuple(50, "L")
        , make_tuple(10, "X")
        , make_tuple(5, "V")
        , make_tuple(1, "I")
};

string convert(int arabic) {
    string roman;

    for(int i = 0; i < THRESHOLDS; i++) {
        while (arabic >= get<0>(arabic2roman[i])){
            roman += get<1>(arabic2roman[i]);
            arabic -= get<0>(arabic2roman[i]);
        }
    }

    return roman;
}

TEST_P(RomanNumeralsSuite, convert_arabic_numbers_into_roman_numerals) {
    tuple<int, string> param = GetParam();
    EXPECT_EQ(convert(get<0>(param)), get<1>(param))
                        << "I was expecting '" << get<1>(param) << "' but got '" << convert(get<0>(param))
                        << "' instead";
}

INSTANTIATE_TEST_SUITE_P(
        MeenyMinyMoe,
        RomanNumeralsSuite,
        testing::Values(
                make_tuple(1, "I")
                , make_tuple(2, "II")
                , make_tuple(3, "III")
                , make_tuple(5, "V")
                , make_tuple(6, "VI")
                , make_tuple(10, "X")
                , make_tuple(11, "XI")
                , make_tuple(15, "XV")
                , make_tuple(50, "L")
        )
);