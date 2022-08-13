#include <iostream>
#include <vector>
#include <string>

int row = 0;
int column = 0;

bool existCore(std::vector<std::vector<char>> &board, int r, int c, const std::string &word, size_t idx)
{
    if (idx == word.length())
    {
        return true;
    }

    if (r < 0 || r >= row || c < 0 || c >= column || word[idx] != board[r][c])
    {
        return false;
    }

    board[r][c] = '\0';
    if (existCore(board, r + 1, c, word, idx + 1) || existCore(board, r - 1, c, word, idx + 1)
        || existCore(board, r, c + 1, word, idx + 1) || existCore(board, r, c - 1, word, idx + 1))
    {
        return true;
    }
    board[r][c] = word[idx];

    return false;
}

bool exist(std::vector<std::vector<char>> &board, const std::string &word)
{
    if (board.empty() || board[0].empty())
    {
        return false;
    }

    row = board.size();
    column = board[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (existCore(board, i, j, word, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<char>> board = {
    {'A', 'B', 'C', 'D'},
    {'E', 'F', 'G', 'H'},
    {'I', 'J', 'K', 'L'},
    {'M', 'N', 'O', 'P'} };

    /**
     * => 1
     * => 0
     */
    std::string one = "AEFJNOPL";
    std::string two = "AEIJOPLH";

    std::cout << exist(board, one) << std::endl;
    std::cout << exist(board, two) << std::endl;

    return 0;
}
