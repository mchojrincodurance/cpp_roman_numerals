#include <gtest/gtest.h>
#include <forward_list>
#include "RomanNumeralsSuite.h"

using namespace std;

forward_list<tuple<int, string>> arabic2roman = {
        make_tuple(1000, "M")
        , make_tuple(500, "D")
        , make_tuple(100, "C")
        , make_tuple(50, "L")
        , make_tuple(10, "X")
        , make_tuple(5, "V")
        , make_tuple(4, "IV")
        , make_tuple(1, "I")
};

string convert(int arabic) {
    string roman;

    for (auto &it: arabic2roman) {
        while (arabic >= get<0>(it)) {
            roman += get<1>(it);
            arabic -= get<0>(it);
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
                , make_tuple(4, "IV")
                , make_tuple(5, "V")
                , make_tuple(6, "VI")
                , make_tuple(10, "X")
                , make_tuple(11, "XI")
                , make_tuple(15, "XV")
                , make_tuple(50, "L")
                , make_tuple(52, "LII")
                , make_tuple(103, "CIII")
                , make_tuple(112, "CXII")
                , make_tuple(107, "CVII")
                , make_tuple(136, "CXXXVI")
                , make_tuple(158, "CLVIII")
                , make_tuple(537, "DXXXVII")
                , make_tuple(551, "DLI")
                , make_tuple(762, "DCCLXII")
                , make_tuple(1001, "MI")
                , make_tuple(1012, "MXII")
                , make_tuple(1017, "MXVII")
                , make_tuple(1053, "MLIII")
                , make_tuple(1101, "MCI")
                , make_tuple(1501, "MDI")
        )
);