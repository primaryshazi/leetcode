#include <iostream>

bool isBadVersion(int version)
{
    return version >= 7;
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;

    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

int main()
{
    /**
     * => 7
     */
    std::cout << firstBadVersion(100) << std::endl;

    return 0;
}
