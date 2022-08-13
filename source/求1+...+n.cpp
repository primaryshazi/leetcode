#include <iostream>

#define SOLUTION_OPTION 4
#define NUMBER_VALUE 10

#if SOLUTION_OPTION == 1
class Sum
{
public:
    Sum()
    {
        ++num_;
        sum_ += num_;
    }

    static int sumNums()
    {
        return Sum::sum_;
    }

private:
    static int num_;
    static int sum_;
};

int Sum::num_ = 0;
int Sum::sum_ = 0;

int sumNums(int n = NUMBER_VALUE)
{
    Sum *sum = new Sum[NUMBER_VALUE]();

    delete[] sum;

    return Sum::sumNums();
}

#elif SOLUTION_OPTION == 2

class Base
{
public:
    virtual int sumNums(int num)
    {
        return 0;
    }
};

Base *g_arrBase[2] = {nullptr};

class Derived : public Base
{
public:
    virtual int sumNums(int num) override
    {
        return g_arrBase[!!num]->sumNums(num - 1) + num;
    }
};

int sumNums(int n = NUMBER_VALUE)
{
    Base b;
    Derived d;

    g_arrBase[0] = &b;
    g_arrBase[1] = &d;

    return g_arrBase[1]->sumNums(n);
}

#elif SOLUTION_OPTION == 3

template <int n>
class Sum
{
public:
    enum Value
    {
        SUM = Sum<n - 1>::SUM + n
    };
};

template <>
class Sum<1>
{
public:
    enum Value
    {
        SUM = 1
    };
};

int sumNums()
{
    return Sum<NUMBER_VALUE>::SUM;
}

#else

int sumNums(int n = NUMBER_VALUE)
{
    static int result = 0;
    bool b = n > 1 && sumNums(n - 1) > 0;
    result += n;
    return result;
}

#endif

int main()
{
    /**
     * => 55
     */
    std::cout << sumNums() << std::endl;

    return 0;
}
