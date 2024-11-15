#include <iostream> //
#include <iomanip>
#include <string>
#include <vector>

#include "matrixInit.hpp"
#include "tokenFreq.hpp"
#include "unitTests.hpp"

using namespace std;

int main()
{

    // vector<vector<int>> matrix; // matrix to use with matrixInit

    // NS_MATRIX::matrixInit(matrix, 3, 4); // init the matrix "matrix"
    // NS_MATRIX::printMatrix(matrix);      // print content of matrix
    // cout << endl;

    // string input = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    // string input1 = "aloha friends aloha aloha yessir";
    // cout << input1 << endl;
    // vector<NS_TOKEN_FREQ::TokenFreq> test;

    // NS_TOKEN_FREQ::getTokenFreqVec(input1, test); // print vector test w/ list of unique and case insensitive tokens and their corresponding frequencies identified within input

    cout << "UNIT TEST FOR MATRIX"
         << "\n";

    // * UNIT TEST - Matrix Init
    if (NS_UNIT_TESTS::test1_matrixInit() == true)
    {
        cout << "test1_matrixInit is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test2_matrixInit() == true)
    {
        cout << "test2_matrixInit is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test3_matrixInit() == true)
    {
        cout << "test3_matrixInit is true (success)" << endl;
    }

    cout << "\n";

    cout << "UNIT TEST FOR TOKENFREQ UNIT"
         << "\n";

    // * UNIT TEST - Operator LE
    if (NS_UNIT_TESTS::test1_operatorLE() == true)
    {
        cout << "test1_operatorLE is true (success)" << endl;
    }
    else
    {
        cout << "test1_operatorLE is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test2_operatorLE() == true)
    {
        cout << "test2_operatorLE is true (success)" << endl;
    }
    else
    {
        cout << "test2_operatorLE is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test3_operatorLE() == true)
    {
        cout << "test3_operatorLE is true (success)" << endl;
    }
    else
    {
        cout << "test3_operatorLE is false (failed)" << endl;
    }
    cout << "\n";

    //*  UNIT TEST - Operator PLUS
    if (NS_UNIT_TESTS::test1_operatorPlus() == true)
    {
        cout << "test1_operatorPlus is true (success)" << endl;
    }
    else
    {
        cout << "test1_operatorPlus is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test2_operatorPlus() == true)
    {
        cout << "test2_operatorPlus is true (success)" << endl;
    }
    else
    {
        cout << "test2_operatorPlus is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test3_operatorPlus() == true)
    {
        cout << "test3_operatorPlus is true (success)" << endl;
    }
    else
    {
        cout << "test3_operatorPlus is false (failed)" << endl;
    }
    cout << "\n";

    // * UNIT TEST -  Get TokenFreq
    if (NS_UNIT_TESTS::test1_getTokenFreqVec() == true)
    {
        cout << "test1_getTokenFreqVec is true (success)" << endl;
    }
    else
    {
        cout << "test1_getTokenFreqVec is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test2_getTokenFreqVec() == true)
    {
        cout << "test2_getTokenFreqVec is true (success)" << endl;
    }
    else
    {
        cout << "test2_getTokenFreqVec is false (failed)" << endl;
    }

    // negative case (white space only)
    if (NS_UNIT_TESTS::test3_getTokenFreqVec() == false)
    {
        cout << "test3_getTokenFreqVec is false (success)" << endl;
    }
    else
    {
        cout << "test3_getTokenFreqVec is true (failed)" << endl;
    }
    cout << "\n";

    // if (NS_UNIT_TESTS::test4_getTokenFreqVec() == true)
    // {
    //     cout << "test4_getTokenFreqVec is true (success)" << endl;
    // }

    // * UNIT TEST - Operator Insertion Sort
    if (NS_UNIT_TESTS::test1_insertionSort() == true)
    {
        cout << "test1_insertionSort is true (success)" << endl;
    }
    else
    {
        cout << "test1_insertionSort is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test2_insertionSort() == true)
    {
        cout << "test2_insertionSort is true (success)" << endl;
    }
    else
    {
        cout << "test2_insertionSort is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test3_insertionSort() == true)
    {
        cout << "test3_insertionSort is true (success)" << endl;
    }
    else
    {
        cout << "test3_insertionSort is false (failed)" << endl;
    }
    cout << "\n";

    // * UNIT TEST - Operator Selection Sort
    if (NS_UNIT_TESTS::test1_selectionSort() == true)
    {
        cout << "test1_selectionSort is true (success)" << endl;
    }
    else
    {
        cout << "test1_selectionSort is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test2_selectionSort() == true)
    {
        cout << "test2_selectionSort is true (success)" << endl;
    }
    else
    {
        cout << "test2_selectionSort is false (failed)" << endl;
    }

    if (NS_UNIT_TESTS::test3_selectionSort() == true)
    {
        cout << "test3_selectionSort is true (success)" << endl;
    }
    else
    {
        cout << "test3_selectionSort is false (failed)" << endl;
    }
    return 0;
}