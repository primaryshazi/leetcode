#include <iostream>
#include <unordered_map>

char firstUniqChar(const std::string &s)
{
    int frequency[26] = { 0 };
    for (char ch : s)
    {
        ++frequency[ch - 'a'];
    }
    for (char ch : s)
    {
        if (frequency[ch - 'a'] == 1)
        {
            return ch;
        }
    }

    return ' ';
}

int main()
{
    /**
     * => d
     * => g
     */
    std::cout << firstUniqChar("abcdefghaijkblmcn") << std::endl;
    std::cout << firstUniqChar("aabbccddeffgee") << std::endl;

    return 0;
}
