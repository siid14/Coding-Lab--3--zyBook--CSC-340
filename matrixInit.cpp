#include "matrixInit.hpp"
#include <vector>
#include <iostream>

namespace NS_MATRIX
{
    using std::vector;

    // * function implementation

    // initialize a 2D Matrix with each value equal to the product of i and j
    void matrixInit(vector<vector<int>> &matrix, int numRows, int numCols)
    {

        // ! With those two lines, I do not get an output from my main?? overflow?
        // ! vector size is unsigned int when here -> assign to an int -> undefined behavior
        // numRows = static_cast<int>(matrix.size());
        // numCols = static_cast<int>(matrix[0].size()); // assumes all rows have same size

        // * Making sure to allocate memory for the sub-vectors of the two-dimensional vector
        matrix.resize(numRows); // resize the matrix vector to have numRows rows

        // init each sub-vector to have numCols columns
        for (int i = 0; i < numRows; i++)
        {
            matrix[i].resize(numCols);
        }

        // init the value of each element of the matrix[i][j]
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                matrix[i][j] = i * j;
            }
        }
    }

    // print size + element of matrix
    void printMatrix(vector<vector<int>> matrix)
    {
        // get + print matrix size
        int numRows = static_cast<int>(matrix.size());
        int numCols = static_cast<int>(matrix[0].size());
        std::cout << "Size of Matrix is (row x cols):  " << numRows << "x" << numCols << std::endl;

        // print every element of matrix
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                std::cout << "Matrix[" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
            }
        }
    }
}
