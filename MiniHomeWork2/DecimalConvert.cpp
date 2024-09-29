#include <cassert>
#include <string>

std::string DecimalConvert(int number, int base) {
    if (number < 0) {return "";}
    if (base < 2 || base > 16) {return "";}

    std::string result;

    while(number > 0) {
        const int digit = number % base;
        result = ((digit < 10) ? char('0' + digit) : char('A' + digit - 10)) + result;
        number /= base;
    }

    return result;
}

void Test() {
    assert(DecimalConvert(670, 8) == "1236");
    assert(DecimalConvert(144, 8) == "220");
    assert(DecimalConvert(47, 8) == "57");

    assert(DecimalConvert(619, 16) == "26B");
    assert(DecimalConvert(934, 16) == "3A6");
    assert(DecimalConvert(9999, 16) == "270F");
}

int main() {
    Test();
}
