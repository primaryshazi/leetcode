#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> symbolValues = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

int romanToInt(const std::string &str)
{
    int result = 0;
    int length = str.length();
    for (int i = 0; i < str.length(); i++)
    {
        int value = symbolValues[str[i]];

        // 若该字符比右字符小则减去当前字符
        if (i < length - 1 && value < symbolValues[str[i + 1]])
        {
            result -= value;
        }
        else
        {
            result += value;
        }
    }

    return result;
}

int main()
{
    /**
     * => 5
     * => 4
     * => 6
     * => 334
     * => 1666
     * => 1534
     */
    std::cout << romanToInt("V") << std::endl;
    std::cout << romanToInt("IV") << std::endl;
    std::cout << romanToInt("VI") << std::endl;
    std::cout << romanToInt("IVXLCDM") << std::endl;
    std::cout << romanToInt("MDCLXVI") << std::endl;
    std::cout << romanToInt("IVXLMDC") << std::endl;

    return 0;
}
