#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int partition(std::vector<int> &nums, int left, int right)
{
    int r = rand() % (right - left + 1) + left;
    std::swap(nums[right], nums[r]);
    int standard = nums[right];
    int index = left;

    for (int i = left; i < right; i++)
    {
        if (nums[i] <= standard)
        {
            std::swap(nums[i], nums[index]);
            ++index;
        }
    }
    std::swap(nums[index], nums[right]);

    return index;
}

void quickSort(std::vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int index = partition(nums, left, right);
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }
}

std::vector<int> sortArray(std::vector<int> &nums)
{
    srand(static_cast<int>(time(NULL)));
    quickSort(nums, 0, static_cast<int>(nums.size()) - 1);
    return nums;
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
    std::vector<int> vi = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8 };

    /**
     * => { 1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 8, 9 }
     */
    std::cout << sortArray(vi) << std::endl;

    return 0;
}
