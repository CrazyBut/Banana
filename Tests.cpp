#include "opz.h"
#include "gtest/gtest.h"

TEST(Parser, parse_is_working) {
    string s = "( 2 + 5 ) ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    list<string> result = n.parse(s);
    string result2 = "";
    for (string x : result) { result2 += x; }
    EXPECT_EQ(result2, "25+2^2^711+^/");
}

TEST(Parser, parser_throw_exeptions) {
    string s = "( 2 ++ 5 ) ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Parser, parser_throw_exeptions_minus) {
    string s = "( 2 +- 5 ) ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Parser, parser_throw_exeptions_double_stepen) {
    string s = "( 2 + 5 ) ^^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Parser, parser_throw_exeptions_with_out) {
    string s = "2 ( 2 + 5 ) ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Parser, parser_mismatched_brackets) {
    string s = "( 2 + 5  ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Parser, parser_back_mismatched_brackets) {
    string s = " 2 + 5 ) ^ 2 ^ 2 /  7 ^ ( 1 + 1 )";
    ExpressionParser n;
    ASSERT_THROW(n.parse(s), logic_error);
}

TEST(Calc, calc_is_working) {
    string s = "( 5 + 2 ) /  7";
    Calculator c;
    ExpressionParser n;
    list<string> result = n.parse(s);
    double result1 = 0;
    result1 = c.calc(result);
    EXPECT_EQ(result1, 1.0);
}