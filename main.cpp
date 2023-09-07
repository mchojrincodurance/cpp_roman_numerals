#include <gtest/gtest.h>
#include "RomanNumeralsSuite.h"
#include "RomanNumeralsConverter.h"

using namespace std;

TEST_P(RomanNumeralsSuite, convert_arabic_numbers_into_roman_numerals) {
    tuple<int, string> param = GetParam();

    auto * converter = new RomanNumeralsConverter();

    int &arabic = get<0>(param);
    const string &actual = converter->convert(arabic);
    const string &expected = get<1>(param);

    EXPECT_EQ(actual, expected) << "I was expecting '" << expected << "' but got '" << actual << "' instead";
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
                , make_tuple(9, "IX")
                , make_tuple(10, "X")
                , make_tuple(11, "XI")
                , make_tuple(15, "XV")
                , make_tuple(19, "XIX")
                , make_tuple(41, "XLI")
                , make_tuple(50, "L")
                , make_tuple(52, "LII")
                , make_tuple(59, "LIX")
                , make_tuple(103, "CIII")
                , make_tuple(107, "CVII")
                , make_tuple(112, "CXII")
                , make_tuple(136, "CXXXVI")
                , make_tuple(158, "CLVIII")
                , make_tuple(199, "CXCIX")
                , make_tuple(537, "DXXXVII")
                , make_tuple(549, "DXLIX")
                , make_tuple(551, "DLI")
                , make_tuple(762, "DCCLXII")
                , make_tuple(1001, "MI")
                , make_tuple(1012, "MXII")
                , make_tuple(1017, "MXVII")
                , make_tuple(1053, "MLIII")
                , make_tuple(1101, "MCI")
                , make_tuple(1501, "MDI")
                , make_tuple(3949, "MMMCMXLIX")
                , make_tuple(3999, "MMMCMXCIX")
        )
);