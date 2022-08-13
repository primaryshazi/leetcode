#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::string> generateBoard(std::vector<int> &queens, int n)
{
    std::vector<std::string> board;
    for (int i = 0; i < n; i++)
    {
        std::string row = std::string(n, '.');
        row[queens[i]] = 'Q';
        board.emplace_back(row);
    }
    return board;
}

void backtrack(std::vector<std::vector<std::string>> &solutions, std::vector<int> &queens, int n, int row,
    std::vector<bool> &columns, std::vector<bool> &diagonalsRight, std::vector<bool> &diagonalsLeft)
{
    if (row == n)
    {
        std::vector<std::string> board = generateBoard(queens, n);
        solutions.emplace_back(board);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (columns[i])
            {
                continue;
            }

            int diagRight = row - i + n;
            if (diagonalsRight[diagRight])
            {
                continue;
            }

            int diagLeft = row + i + n;
            if (diagonalsLeft[diagLeft])
            {
                continue;
            }

            queens[row] = i;
            columns[i] = true;
            diagonalsRight[diagRight] = true;
            diagonalsLeft[diagLeft] = true;

            backtrack(solutions, queens, n, row + 1, columns, diagonalsRight, diagonalsLeft);

            queens[row] = -1;
            columns[i] = false;
            diagonalsRight[diagRight] = false;
            diagonalsLeft[diagLeft] = false;
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> queens(n, -1);
    std::vector<bool> columns(n, false);                // 记录每一列
    std::vector<bool> diagonalsRight(2 * n, false);     // 记录右斜对角线
    std::vector<bool> diagonalsLeft(2 * n, false);      // 记录左斜对角线

    backtrack(solutions, queens, n, 0, columns, diagonalsRight, diagonalsLeft);

    return solutions;
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
     * => { { .Q.., ...Q, Q..., ..Q. }, { ..Q., Q..., ...Q, .Q.. } }
     */
    std::cout << solveNQueens(4) << std::endl;

    return 0;
}
