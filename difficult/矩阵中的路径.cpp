#include <iostream>
#include <vector>
#include <string>

bool existCore(const std::vector<std::vector<char>> &board, const std::string &word, std::vector<std::vector<bool>> &visitor, std::pair<int, int> pos, size_t index)
{
    if (index == word.size())
    {
        return true;
    }
    if (pos.first < 0 || pos.first >= board.size() || pos.second < 0 || pos.second >= board[0].size() || visitor[pos.first][pos.second] || board[pos.first][pos.second] != word[index])
    {
        return false;
    }

    // 当前字母符合，则寻找上下左右下一个字母
    visitor[pos.first][pos.second] = true;
    bool isExist = existCore(board, word, visitor, {pos.first, pos.second + 1}, index + 1) || existCore(board, word, visitor, {pos.first, pos.second - 1}, index + 1) || existCore(board, word, visitor, {pos.first + 1, pos.second}, index + 1) || existCore(board, word, visitor, {pos.first - 1, pos.second}, index + 1);
    if (!isExist)
    {
        visitor[pos.first][pos.second] = false;
        return false;
    }

    return true;
}

bool exist(const std::vector<std::vector<char>> &board, const std::string &word)
{
    if (board.empty() || board[0].empty() || word.empty())
    {
        return false;
    }
    size_t row = board.size();
    size_t col = board[0].size();

    std::vector<std::vector<bool>> visitor(row, std::vector<bool>(col, false)); // 记录每个字母是否被访问
    // 遍历每个字符寻找起点
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (existCore(board, word, visitor, {i, j}, 0))
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
        {'M', 'N', 'O', 'P'}};

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
