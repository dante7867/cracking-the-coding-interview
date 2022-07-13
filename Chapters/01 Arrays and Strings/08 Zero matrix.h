#include <iostream>
#include <set>
#include <vector>


void zeroMatrix(std::vector<std::vector<int>>& matrix)
{
    const size_t H = matrix.size();
    const size_t L = matrix[0].size();

    std::set<size_t> colums_to_zero;
    std::set<size_t> rows_to_zero;

    size_t x, y;

    for(y = 0; y < H; ++y)
    {
        for(x = 0; x < L; ++x)
        {
            if(matrix[y][x] == 0)
            {
                colums_to_zero.insert(x);
                rows_to_zero.insert(y);
                std::cout << "row: " << y << ", col: " << x << '\n'; 
            }
        }
    }
    
    // zero cols
    for(const size_t col_idx : colums_to_zero)
        for(y = 0; y < H; ++y)
            matrix[y][col_idx] = 0;
    // zero rows
    for(const size_t row_idx : rows_to_zero)
        for(x = 0; x < L; ++x)
            matrix[row_idx][x] = 0;
}

