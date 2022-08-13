#include <iostream>
#include <string>
#include <utility>

const std::pair<int, std::string> valueSymbols[] = {
        {1000, "M"},
        {900,  "CM"},
        {500,  "D"},
        {400,  "CD"},
        {100,  "C"},
        {90,   "XC"},
        {50,   "L"},
        {40,   "XL"},
        {10,   "X"},
        {9,    "IX"},
        {5,    "V"},
        {4,    "IV"},
        {1,    "I"},
};

std::string intToRoman(int num)
{
    std::string roman;
    // 找到小于当前值的最大值表示的符号，依次相加即可
    for (const auto &[value, symbol] : valueSymbols)
    {
        while (num >= value)
        {
            num -= value;
            roman += symbol;
        }
        if (num == 0)
        {
            break;
        }
    }

    return roman;
}

int main()
{
    /**
     * => 6  VI
     * => 24  XXIV
     * => 60  LX
     * => 120  CXX
     * => 210  CCX
     * => 336  CCCXXXVI
     * => 504  DIV
     * => 720  DCCXX
     * => 990  CMXC
     * => 1320  MCCCXX
     */
    for (int i = 0; i < 10; i++)
    {
        int value = (i + 1) * (i + 2) * (i + 3);
        std::cout << value << "  " << intToRoman(value) << std::endl;
    }

    return 0;
}
