#include <iostream>
#include <vector>
#include <algorithm>

int length = 0;
std::vector<std::vector<int>> result;

void dfs(const std::vector<int> &candidates, int index, int target, std::vector<int> &combine)
{
    if (target == 0)
    {
        result.emplace_back(combine);
        return;
    }
    if (target < 0)
    {
        return;
    }

    for (int i = index; i < length; i++)
    {
        if (target - candidates[i] < 0)
        {
            return;
        }

        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        combine.emplace_back(candidates[i]);
        dfs(candidates, i + 1, target - candidates[i], combine);
        combine.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    if (candidates.empty())
    {
        return {};
    }

    length = static_cast<int>(candidates.size());
    result.clear();

    std::sort(candidates.begin(), candidates.end());

    std::vector<int> combine;
    dfs(candidates, 0, target, combine);

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
    std::vector<int> candidates = { 1, 2, 3, 3, 5, 6 };

    /**
     * => { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 5 }, { 3, 3 }, { 6 } }
     */
    std::cout << combinationSum(candidates, 6) << std::endl;

    return 0;
}
