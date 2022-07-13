#include <iostream>
#include <vector>


// Time - O(H*L+H+L) => O(H*L), space - O(H*L+H+L) => O(H*L),
// where vector is of H*L size
void zeroMatrix(std::vector<std::vector<int>>& matrix)
{
    const size_t H = matrix.size();
    const size_t L = matrix[0].size();

    std::vector<bool> columns_to_zero{L, false};
    std::vector<bool> rows_to_zero{H, false};

    size_t x, y;

    for(y = 0; y < H; ++y)
    {
        for(x = 0; x < L; ++x)
        {
            if(matrix[y][x] == 0)
            {
                columns_to_zero[x] = true;
                rows_to_zero[y] = true;
            }
        }
    }
    
    // zero cols
    for(size_t col = 0; col < columns_to_zero.size(); ++col)
        if(columns_to_zero[col])
            for(y = 0; y < H; ++y)
                matrix[y][col] = 0;
    // zero rows
    for(size_t row = 0; row < rows_to_zero.size(); ++row)
        if(rows_to_zero[row])
            for(x = 0; x < L; ++x)
                matrix[row][x] = 0;
}

