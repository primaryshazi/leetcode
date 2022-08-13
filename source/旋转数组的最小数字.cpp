#include <iostream>
#include <vector>

int minArray(std::vector<int> &numbers)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        /**
         * 当中间元素小于右值时，目标值必在[left, mid]中
         * 当中间元素大于右值时，目标值必在[mid + 1, right]中
         * 当中间元素等于右值时，递减右区间，直至满足条件
         */
        if (numbers[mid] < numbers[right])
        {
            right = mid;
        }
        else if (numbers[mid] > numbers[right])
        {
            left = mid + 1;
        }
        else
        {
            right--;
        }
    }

    return numbers[left];
}

int main()
{
    std::vector<int> numbers = { 5, 6, 7, 8, 9, 0, 1, 2, 3, 4 };

    /**
     * => 0
     */
    std::cout << minArray(numbers) << std::endl;

    return 0;
}
