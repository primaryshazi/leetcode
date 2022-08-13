#include <iostream>
#include <vector>
#include <cctype>

bool isValidSudoku(const std::vector<std::vector<char>> &board)
{
    int rowNum[9] = { false };      // 纪律每行
    int colNum[9] = { false };      // 记录每列
    int squalNum[9] = { false };    // 记录每个方块

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int squalIndex = 3 * (i / 3) + j / 3;
            int ch = board[i][j];
            if (std::isdigit(ch))
            {
                int bit = 1 << (ch - '1');
                if ((rowNum[i] & bit) != 0 || (colNum[j] & bit) != 0 || (squalNum[squalIndex] & bit) != 0)
                {
                    return false;
                }
                rowNum[i] |= bit;
                colNum[j] |= bit;
                squalNum[squalIndex] |= bit;
            }
        }
    }

    return true;
}

int main()
{
    std::vector<std::vector<char>> board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    /**
     * => 1
     */
    std::cout << isValidSudoku(board) << std::endl;

    return 0;
}
