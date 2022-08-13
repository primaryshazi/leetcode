#include <iostream>

bool isUnique(const std::string &astr)
{
    if (astr.empty())
    {
        return true;
    }

    int64_t left = 0;
    int64_t right = 0;
    int64_t bit = 0;

    for (auto c : astr)
    {
        int64_t index = c;
        if (index < 64)
        {
            bit = 1L << index;
            if ((left & bit) != 0)
            {
                return false;
            }
            left |= bit;
        }
        else
        {
            bit = 1L << (index - 64);
            if ((right & bit) != 0)
            {
                return false;
            }
            right |= bit;
        }
    }

    return true;
}

int main()
{
    /**
     * => 1
     * => 0
     */
    std::cout << isUnique("abcdefghijklmnopqrstuvwxyz") << std::endl;
    std::cout << isUnique("isUnique") << std::endl;

    return 0;
}
