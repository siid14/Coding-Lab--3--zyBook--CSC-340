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

    // NS_MATRIX::printMatrix(matrix); // print content of matrix
    // cout << endl;

    // string input = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    // string input1 = "aloha friends aloha aloha yessir";
    // cout << input1 << endl;
    // vector<NS_TOKEN_FREQ::TokenFreq> test;

    // NS_TOKEN_FREQ::getTokenFreqVec(input1, test); // print vector test w/ list of unique and case insensitive tokens and their corresponding frequencies identified within input

    // // * maybe use capacity to check memory usage of vectors

    // UNIT TEST - Matrix Init
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

    // UNIT TEST - Operator LE
    if (NS_UNIT_TESTS::test1_operatorLE() == true)
    {
        cout << "test1_operatorLE is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test2_operatorLE() == true)
    {
        cout << "test2_operatorLE is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test3_operatorLE() == true)
    {
        cout << "test3_operatorLE is true (success)" << endl;
    }

    // UNIT TEST - Operator PLUS
    if (NS_UNIT_TESTS::test1_operatorPlus() == true)
    {
        cout << "test1_operatorPlus is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test2_operatorPlus() == false)
    {
        cout << "test2_operatorPlus is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test3_operatorPlus() == true)
    {
        cout << "test3_operatorPlus is true (success)" << endl;
    }

    // UNIT TEST -  Get TokenFreq
    if (NS_UNIT_TESTS::test1_getTokenFreqVec() == true)
    {
        cout << "test1_getTokenFreqVec is true (success)" << endl;
    }

    if (NS_UNIT_TESTS::test2_getTokenFreqVec() == false)
    {
        cout << "test2_getTokenFreqVec is false (success)" << endl;
    }

    if (NS_UNIT_TESTS::test3_getTokenFreqVec() == true)
    {
        cout << "test3_getTokenFreqVec is true (success)" << endl;
    }

    // UNIT TEST - Operator Insertion Sort
    if (NS_UNIT_TESTS::test1_insertionSort() == true)
    {
        cout << "test1_insertionSort is true (success)" << endl;
    }
    if (NS_UNIT_TESTS::test2_insertionSort() == false)
    {
        cout << "test2_insertionSort is false (success)" << endl;
    }
    if (NS_UNIT_TESTS::test3_insertionSort() == true)
    {
        cout << "test3_insertionSort is true (success)" << endl;
    }

    // UNIT TEST - Operator Selection Sort
    if (NS_UNIT_TESTS::test1_selectionSort() == true)
    {
        cout << "test1_selectionSort is true (success)" << endl;
    }

    // TODO: fix - don't pass zyBook test
    if (NS_UNIT_TESTS::test2_selectionSort() == true)
    {
        cout << "test2_selectionSort is true (success)" << endl;
    }
    // TODO: fix - don't pass zyBook test
    if (NS_UNIT_TESTS::test3_selectionSort() == true)
    {
        cout << "test3_selectionSort is true (success)" << endl;
    }

    return 0;
}