// header file //https://stackoverflow.com/questions/1945846/what-should-go-into-an-h-file

#ifndef MATRIX_INIT_HPP // https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#define MATRIX_INIT_HPP

#include <vector>

namespace NS_MATRIX // https://stackoverflow.com/questions/10816600/c-namespaces-how-to-use-in-header-and-source-files-correctly
{
    using std::vector;

    // * function prototype
    void matrixInit(vector<vector<int>> &matrix, int numRows, int numCols);

    void printMatrix(vector<vector<int>> matrix);
}

#endif