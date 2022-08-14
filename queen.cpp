#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> vec, int row)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec.size(); ++j)

        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(std::vector<std::vector<int>> vec, int row, int col)
{
    for (int i = 0; i < col; ++i)
    {
        if (vec[row][i])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (vec[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < vec.size(); i++, j--)
    {
        if (vec[i][j])
        {
            return false;
        }
    }
    return true;
}

bool setQ(std::vector<std::vector<int>> &vec, int col)
{
    if (col >= vec.size())
    {

        return true;
    }

    for (int i = 0; i < vec.size(); ++i)
    {

        if (isSafe(vec, i, col))
        {
            vec[i][col] = 1;
            if (setQ(vec, col + 1))
            {
                return true;
            }
            vec[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    int row = 8;
    int col = 8;
    std::vector<std::vector<int>> vec(col, std::vector<int>(row));

    if (!setQ(vec, 0))
    {
        std::cout << " Solution does not exist" << std::endl;
        return false;
    }
    else
    {
        print(vec, 0);

        std::cout << std::endl;
    }
}