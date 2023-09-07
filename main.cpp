#include <gtest/gtest.h>
#include "RomanNumeralsSuite.h"

using namespace std;

string convert(int arabic) {
    return "";
}

TEST_P(RomanNumeralsSuite, convert_arabic_numbers_into_roman_numerals)
{
    std::tuple<int, std::string> param = GetParam();
    EXPECT_EQ(convert(std::get<0>(param)), std::get<1>(param));
}

INSTANTIATE_TEST_SUITE_P(MeenyMinyMoe,
                         RomanNumeralsSuite,
                         testing::Values(std::make_tuple(1, "I")));