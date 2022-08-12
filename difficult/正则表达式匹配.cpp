#include <iostream>
#include <string>
#include <string_view>
#include <vector>

bool isMatchCore(std::string &s, int i, std::string &p, int j)
{
    if (i == 0)
    {
        return false;
    }
    if (p[j - 1] == '.')
    {
        return true;
    }
    return s[i - 1] == p[j - 1];
};

bool isMatch(std::string &s, std::string &p)
{
    int m = s.size();
    int n = p.size();

    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*')
            {
                f[i][j] |= f[i][j - 2];
                if (isMatchCore(s, i, p, j - 1))
                {
                    f[i][j] |= f[i - 1][j];
                }
            }
            else
            {
                if (isMatchCore(s, i, p, j))
                {
                    f[i][j] |= f[i - 1][j - 1];
                }
            }
        }
    }

    return f[m][n];
}

int main()
{
    std::string s1 = "aaaa";
    std::string p1 = "a*";

    std::string s2 = "aaaa";
    std::string p2 = "a.";

    std::string s3 = "aabb";
    std::string p3 = ".*";

    std::string s4 = "aaaab";
    std::string p4 = "a*";

    std::string s5 = "aaaab";
    std::string p5 = "a*b";

    /**
     * => 1
     * => 0
     * => 1
     * => 0
     * => 1
     */
    std::cout << isMatch(s1, p1) << std::endl;
    std::cout << isMatch(s2, p2) << std::endl;
    std::cout << isMatch(s3, p3) << std::endl;
    std::cout << isMatch(s4, p4) << std::endl;
    std::cout << isMatch(s5, p5) << std::endl;

    return 0;
}
