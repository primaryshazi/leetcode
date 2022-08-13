#include <iostream>
#include <vector>

int candy(const std::vector<int> &ratings)
{
    size_t n = ratings.size();
    int result = 1;
    int inc = 1, dec = 0, pre = 1;

    for (size_t i = 1; i < n; i++)
    {
        /**
         * 当为递增序列时，直接递增1，当出现相同时，则置为1
         * 当为递减序列时，则反向加1，当递减与递增序列相同时，需再增1
         */
        if (ratings[i] >= ratings[i - 1])
        {
            dec = 0;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            result += pre;
            inc = pre;
        }
        else
        {
            dec++;
            if (dec == inc)
            {
                dec++;
            }
            result += dec;
            pre = 1;
        }
    }

    return result;
}

int main()
{
    std::vector<int> v = { 1, 3, 5, 3, 2, 1 };

    /**
     * => 12
     */
    std::cout << candy(v) << std::endl;

    return 0;
}
