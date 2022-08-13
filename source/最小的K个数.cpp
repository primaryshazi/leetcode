#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int low, int high)
{
    int index = low;
    int standard = arr[high];

    for (int i = low; i < high; i++)
    {
        if (arr[i] < standard)
        {
            std::swap(arr[i], arr[index]);
            index++;
        }
    }
    std::swap(arr[index], arr[high]);

    return index;
}

std::vector<int> getLeastNumbers(std::vector<int> &arr, int k)
{
    if (k <= 0)
    {
        return {};
    }

    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    int index = partition(arr, low, high);

    while (index + 1 != k)
    {
        if (index + 1 > k)
        {
            high = index - 1;
            index = partition(arr, low, high);
        }
        else
        {
            low = index + 1;
            index = partition(arr, low, high);
        }
    }

    return std::vector<int>(arr.begin(), arr.begin() + k);
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
    std::vector<int> arr = { 7, 5, 3, 9, 1, 8, 2, 6, 4 };

    /**
     * => {  }
     * => { 1 }
     * => { 1, 2 }
     * => { 1, 2, 3 }
     * => { 1, 2, 3, 4 }
     * => { 1, 2, 3, 4, 5 }
     * => { 1, 2, 3, 4, 5, 6 }
     * => { 1, 2, 3, 4, 5, 6, 7 }
     * => { 1, 2, 3, 4, 5, 6, 7, 8 }
     * => { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
     */
    for (int i = 0; i < 10; i++)
    {
        std::cout << getLeastNumbers(arr, i) << std::endl;
    }

    return 0;
}
