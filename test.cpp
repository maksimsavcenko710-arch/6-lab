#include <gtest/gtest.h>
#include "g.h"

// Тест 1: перевірка обчислення для a=2, b=3
TEST(GTest, BasicCalculation)
{
    // g(2, 3) = (2 * 3) / (2^2 + 3^2) = 6 / 13 ≈ 0.461538
    EXPECT_NEAR(g(2, 3), 6.0 / 13.0, 1e-5);
}

// Тест 2: перевірка для однакових аргументів
TEST(GTest, EqualArguments)
{
    // g(2, 2) = (2 * 2) / (2^2 + 2^2) = 4 / 8 = 0.5
    EXPECT_DOUBLE_EQ(g(2, 2), 0.5);
}