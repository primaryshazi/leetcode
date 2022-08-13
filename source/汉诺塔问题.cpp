#include <iostream>
#include <vector>

void move(int n, std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    if (n < 1)
    {
        return;
    }

    move(n - 1, A, C, B);       // 将A中的[n-1, 1]通过C移动到B
    C.emplace_back(A.back());   // 将A中的n移动到C
    A.pop_back();
    move(n - 1, B, A, C);       // 将B中的[n-1, 1]通过A移动到C
}

void hanota(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C)
{
    int n = static_cast<int>(A.size());

    move(n, A, B, C);
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
     * 三阶汉诺塔转换过程
     * => 1
     * => 2
     * => 3
     * => A  B  C
     *
     * => 2
     * => 3     1
     * => A  B  C
     *
     * => 3  2  1
     * => A  B  C
     *
     * =>    1
     * => 3  2
     * => A  B  C
     *
     * =>    1
     * =>    2   3
     * => A  B   C
     *
     * => 1  2  3
     * => A  B  C
     *
     * =>       2
     * => 1     3
     * => A  B  C
     *
     * =>       1
     * =>       2
     * =>       3
     * => A  B  C
     *
     * 多阶汉诺塔，可先将A中的[n-1, 1]层移动至B中，然后将A中的第n层移动到C，再将B中的[n-1, 1]层移动到C上，依次递归
     */
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> C;

    for (int i = 1; i <= 10; i++)
    {
        A.emplace_back(i);
    }

    hanota(A, B, C);

    /**
     * => {  }
     * => {  }
     * => { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }
     */
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;

    return 0;
}
