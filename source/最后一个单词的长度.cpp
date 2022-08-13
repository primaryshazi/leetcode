#include <iostream>
#include <string>

int lengthOfLastWord(const std::string &s)
{
    int index = s.size() - 1;

    while (!std::isalpha(s[index]))
    {
        index--;
    }

    int length = 0;

    while (index >= 0 && std::isalpha(s[index]))
    {
        length++;
        index--;
    }

    return length;
}

int main()
{
    std::string s1 = "yuri";
    std::string s2 = "Hello World";
    std::string s3 = "Are You OK?";

    /**
     * => 4
     * => 5
     * => 2
     */
    std::cout << lengthOfLastWord(s1) << std::endl;
    std::cout << lengthOfLastWord(s2) << std::endl;
    std::cout << lengthOfLastWord(s3) << std::endl;

    return 0;
}
