#include <gtest/gtest.h>

using namespace std;

string convert(int arabic) {
    return "";
}

TEST(ConverterShould, convert_single_digit_numbers_to_roman)
{
    EXPECT_EQ(convert(1), "I");
}