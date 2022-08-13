#include <iostream>
#include <vector>

void permuteCore(std::vector<std::vector<int>> &result, std::vector<int> &output, int first, int len)
{
    if (first == len)
    {
        result.emplace_back(output);
        return;
    }

    for (int i = first; i < len; ++i)
    {
        std::swap(output[i], output[first]);
        permuteCore(result, output, first + 1, len);
        std::swap(output[i], output[first]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    permuteCore(result, nums, 0, (int)nums.size());
    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "{ ";
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
        {
            os << ", ";
        }
        os << *it;
    }
    os << " }";

    return os;
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4 };

    /**
     * => { { 1, 2, 3, 4 }, { 1, 2, 4, 3 }, { 1, 3, 2, 4 }, { 1, 3, 4, 2 }, { 1, 4, 3, 2 }, { 1, 4, 2, 3 }, { 2, 1, 3, 4 },
     *      { 2, 1, 4, 3 }, { 2, 3, 1, 4 }, { 2, 3, 4, 1 }, { 2, 4, 3, 1 }, { 2, 4, 1, 3 }, { 3, 2, 1, 4 }, { 3, 2, 4, 1 },
     *      { 3, 1, 2, 4 }, { 3, 1, 4, 2 }, { 3, 4, 1, 2 }, { 3, 4, 2, 1 }, { 4, 2, 3, 1 }, { 4, 2, 1, 3 }, { 4, 3, 2, 1 },
     *      { 4, 3, 1, 2 }, { 4, 1, 3, 2 }, { 4, 1, 2, 3 } }
     */
    std::cout << permute(v) << std::endl;

    return 0;
}
