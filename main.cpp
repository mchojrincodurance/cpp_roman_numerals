#include <gtest/gtest.h>
#include "RomanNumeralsSuite.h"

using namespace std;

string convert(int arabic) {
    if (arabic == 2) {
        return "II";
    }

    return "I";
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
//                ,make_tuple(3, "III")
        )
);