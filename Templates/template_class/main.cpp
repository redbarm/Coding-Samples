#include "main.hpp"

int main()
{
    StudentRecord<int> srInt(3);
    srInt.setId(11111);
    srInt.printGrades();

    StudentRecord<char> srChar('B');
    srChar.setId(22222);
    srChar.printGrades();

    StudentRecord<float> srFloat(3.3333);
    srFloat.setId(33333);
    srFloat.printGrades();

    StudentRecord<string> srString("B-");
    srString.setId(44444);
    srString.printGrades();

    return 0;
}
