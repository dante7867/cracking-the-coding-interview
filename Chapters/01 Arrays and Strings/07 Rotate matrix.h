#include <iostream>
#include <vector>
#include <algorithm>


void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    std::cout << "------------\n";
    const size_t SIZE = matrix[0].size();
    for(int y =0; y < SIZE; ++y)
    {
        for(int x = 0; x < SIZE; ++x)
        {
            std::string alignment = (matrix[y][x] > 9) ? "" : "0"; 
            std::cout << alignment << matrix[y][x] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "------------\n";
}


// Time - O(N*N), space - O(N*N+N) => O(N), where vector is of NxN size 
void rotateMatrixSwapEdges(std::vector<std::vector<int>>& matrix)
{
    const size_t SIZE = matrix[0].size();

    size_t x, y;
    size_t depth = 0;

    std::vector<int> temp;
    temp.reserve(SIZE-1);

    while(depth <= SIZE/2)
    {
        std::copy(std::begin(matrix[depth]) + depth,
                std::end(matrix[depth]) - depth - 1,
                std::back_inserter(temp));
        
        y = depth;
        for(int& cur : temp)
            std::swap(cur, matrix[y++][SIZE-1-depth]); // swap is O(N)
        x = SIZE - 1 - depth;
        for(int& cur : temp)
            std::swap(cur, matrix[SIZE-1-depth][x--]);
        y = SIZE - 1 - depth;
        for(int& cur : temp)
            std::swap(cur, matrix[y--][depth]);
        x = depth;
        for(int& cur : temp)
            matrix[depth][x++] = cur;

        ++depth;
        temp.clear();
    };
}


// Time - O(N*N), space - O(N*N+N) => O(N), where vector is of NxN size. 
// Much less swaps 
void rotateMatrix(std::vector<std::vector<int>>& matrix)
{
    const size_t SIZE = matrix[0].size();

    int x, y;
    int depth = 0;

    std::vector<int> temp;
    temp.reserve(SIZE-1);

    std::cout << "1" << std::endl;
    while(depth < SIZE/2)
    {
        std::copy(std::begin(matrix[depth]) + depth,
                std::end(matrix[depth]) - depth - 1,
                std::back_inserter(temp));
        
        // left -> top
        x = 0;
        for(x = depth; x < SIZE - depth - 1; ++x)
            matrix[depth][x] = matrix[SIZE - x - 1][depth];
        
        //bottom -> left
        y = 0;
        for(y = depth + 1; y < SIZE - depth; ++y)
            matrix[y][depth] = matrix[SIZE - depth - 1][y];

        //right -> bottom
        for(x = depth + 1; x < SIZE - depth; ++x)
            matrix[SIZE-depth-1][x] = matrix[SIZE - x - 1][SIZE - depth - 1];
        
        // buffered top -> right
        y = depth;
        for(int& cur : temp)
            matrix[y++][SIZE-1-depth] = cur;

        ++depth;
        temp.clear();
    };
}

