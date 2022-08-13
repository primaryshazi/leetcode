#include <iostream>
#include <vector>

int gcd(int x, int y)
{
    return y > 0 ? gcd(y, x % y) : x;
}

void rotate(std::vector<int> &nums, int k)
{
    int len = static_cast<int>(nums.size());
    if (len < 2 || k < 0)
    {
        return;
    }

    k = k % len;
    int count = gcd(k, len);    // 获取最多需要轮询多少轮
    for (int start = 0; start < count; ++start)
    {
        int cur = start;
        int prev = nums[start];
        do
        {
            int next = (cur + k) % len;
            std::swap(prev, nums[next]);
            cur = next;
        } while (start != cur);
    }
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
    /**
     * => 0  { 1, 2, 3, 4, 5, 6, 7, 8 }
     * => 3  { 6, 7, 8, 1, 2, 3, 4, 5 }
     * => 6  { 3, 4, 5, 6, 7, 8, 1, 2 }
     * => 9  { 8, 1, 2, 3, 4, 5, 6, 7 }
     */
    for (int i = 0; i < 10; i += 3)
    {
        std::vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8 };
        rotate(vi, i);
        std::cout << i << "  " << vi << std::endl;
    }

    return 0;
}
