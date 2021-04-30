#include <iostream>
#include <string>

template <typename T>
T addNumbers(T input1, T input2)
{
    return input1 + input2;
}

template <typename T, typename U>
T getBigger(T input1, U input2)
{
    if (input1 > input2)
        return input1;
    return input2;
}
