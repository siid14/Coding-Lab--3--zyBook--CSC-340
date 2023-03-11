#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include <vector>

#include "tokenFreq.hpp"

namespace NS_UNIT_TESTS

{
    using std::vector;

    // struct TokenFreq
    // {
    //     std::string token;
    //     int freq;

    //     TokenFreq() : token(""), freq(0) {}

    //     TokenFreq(string userToken, int userFreq)
    //     {
    //         token = userToken;
    //         freq = userFreq;
    //     }
    // };

    // * function prototype

    // matrixInit()
    inline bool test1_matrixInit()
    {
        int testNumRows = 10, testNumCols = 5;
        vector<vector<int>> testMatrix;

        NS_MATRIX::matrixInit(testMatrix, testNumRows, testNumCols);

        if (static_cast<int>(testMatrix.size()) == testNumRows && static_cast<int>(testMatrix[0].size()) == testNumCols)
        {
            for (int i = 0; i < testNumRows; i++)
            {
                for (int j = 0; j < testNumCols; j++)
                {
                    if (testMatrix[i][j] == i * j)
                    {
                        return true;
                    }
                }
            }
        }
        return false; // TODO: check if it's the right return condition
    }

    inline bool test2_matrixInit()
    {
        int testNumRows = 4, testNumCols = 5;
        vector<vector<int>> testMatrix;

        NS_MATRIX::matrixInit(testMatrix, testNumRows, testNumCols);

        if (static_cast<int>(testMatrix.size()) == testNumRows && static_cast<int>(testMatrix[0].size()) == testNumCols)
        {
            for (int i = 0; i < testNumRows; i++)
            {
                for (int j = 0; j < testNumCols; j++)
                {
                    if (testMatrix[i][j == i * j])
                    {
                        return true;
                    }
                }
            }
        }
        return false; // TODO: check if it's the right return condition
    }

    inline bool test3_matrixInit()
    {
        int testNumRows = 9, testNumCols = 2;
        vector<vector<int>> testMatrix;

        NS_MATRIX::matrixInit(testMatrix, testNumRows, testNumCols);

        if (static_cast<int>(testMatrix.size()) == testNumRows && static_cast<int>(testMatrix[0].size()) == testNumCols)
        {
            for (int i = 0; i < testNumRows; i++)
            {
                for (int j = 0; j < testNumCols; j++)
                {
                    if (testMatrix[i][j == i * j])
                    {
                        return true;
                    }
                }
            }
        }
        return false; // TODO: check if it's the right return condition
    }

    // operator<=
    // * expecting true
    inline bool test1_operatorLE()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("guns", 10);
        NS_TOKEN_FREQ::TokenFreq tf2("flowers", 40);

        if (tf1 <= tf2)
        {
            return true;
        }

        return false;
    }

    // * expecting false

    inline bool test2_operatorLE()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("guns", 454);
        NS_TOKEN_FREQ::TokenFreq tf2("candy", 100);

        if (tf2 <= tf1)
        {
            return true;
        }

        return false;
    }

    // * expecting true
    inline bool test3_operatorLE()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("games", 1);
        NS_TOKEN_FREQ::TokenFreq tf2("candy", 2);

        if (tf1 <= tf2)
        {
            return true;
        }

        return false;
    }

    // operator+
    // * expect true
    inline bool test1_operatorPlus()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("red", 1);
        NS_TOKEN_FREQ::TokenFreq tf2("blue", 2);

        NS_TOKEN_FREQ::TokenFreq tf3("red or blue", 3);

        if ((tf1 + tf2) == tf3)
        {
            return true;
        }

        return false;
    }

    // * expect true
    inline bool test2_operatorPlus()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("jolie", 111);
        NS_TOKEN_FREQ::TokenFreq tf2("moche", 111);

        NS_TOKEN_FREQ::TokenFreq tf3("jolie or moche", 222);

        if ((tf1 + tf2) == tf3)
        {
            return true;
        }

        return false;
    }

    // * expect true

    inline bool test3_operatorPlus()
    {
        NS_TOKEN_FREQ::TokenFreq tf1("light", 10);
        NS_TOKEN_FREQ::TokenFreq tf2("dark", 2);

        NS_TOKEN_FREQ::TokenFreq tf3("light or dark", 12);

        if ((tf1 + tf2) == tf3)
        {
            return true;
        }

        return false;
    }

    // getTokenFreq()
    // * expect true
    inline bool test1_getTokenFreqVec()
    {

        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "The quick brown fox jumps over the lazy dog";
        vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"brown", 1}, {"dog", 1}, {"fox", 1}, {"jumps", 1}, {"lazy", 1}, {"over", 1}, {"quick", 1}, {"the", 2}};
        vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);

        // for (auto const &tokenObjectOut : output1)
        // {
        //     for (auto const &tokenObjectExp : expected1)
        //     {
        //         if (tokenObjectExp == tokenObjectOut)
        //     }
        // }

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            if (output1[i].token != expected1[i].token || output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true
    inline bool test2_getTokenFreqVec()
    {

        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "hey heye hey heye";
        vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"hey", 2}, {"heye", 2}};
        vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            if (output1[i].token != expected1[i].token || output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true

    inline bool test3_getTokenFreqVec()
    {

        NS_TOKEN_FREQ::TokenFreq tf1;
        // std::cout << "test3_getTokenFreqVec" << std::endl;
        std::string input1 = "Hello baby, I miss u";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"baby,", 1}, {"hello", 1}, {"i", 1}, {"miss", 1}, {"u", 1}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);

        std::cout << "output1.size " << output1.size() << std::endl;
        std::cout << "expected1.size " << expected1.size() << std::endl;

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {

            // std::cout << "output1[" << i << "].token : " << output1[i].token << std::endl;
            // std::cout << "expected1[" << i << "].token : " << expected1[i].token << std::endl << std::endl;
            // std::cout << "output1[" << i << "].freq : " << output1[i].freq << std::endl;
            // std::cout << "expected1[" << i << "].freq : " << expected1[i].freq << std::endl << std::endl;
            if (output1[i].token != expected1[i].token || output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // ascending sorting algorithms
    // * expect true
    inline bool test1_insertionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "Hello baby, I miss u, i Miss you, I miss";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"i", 3}, {"miss", 3}, {"baby", 1}, {"hello", 1}, {"u", 1}, {"you", 1}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::insertionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true
    inline bool test2_insertionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "hey heye hey heye It's you, right you";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"hey", 2}, {"heye", 2}, {"it's", 1}, {"right", 1}, {"you", 1}, {"you,", 1}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::insertionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true
    inline bool test3_insertionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "aloha friends aloha aloha yessir";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"aloha", 3}, {"friends", 1}, {"yessir", 1}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::insertionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // descending sorting algortihm
    // * expect true
    inline bool test1_selectionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "Hello baby, I miss u, i Miss you, I miss";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"baby", 1}, {"hello", 1}, {"u", 1}, {"you,", 1}, {"i", 3}, {"miss", 3}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::selectionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            // std::cout << "output1[" << i << "].freq : " << output1[i].freq << std::endl;
            // std::cout << "expected1[" << i << "].freq : " << expected1[i].freq << std::endl << std::endl;
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true
    // TODO: fix - don't pass zyBook test
    inline bool test2_selectionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "Seoul Korea Korea Korea Oh Ah yes";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"ah", 1}, {"oh", 1}, {"seoul", 1}, {"yes", 1}, {"korea", 3}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::selectionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            std::cout << "output1[" << i << "].freq : " << output1[i].freq << std::endl;
            std::cout << "expected1[" << i << "].freq : " << expected1[i].freq << std::endl
                      << std::endl;
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }

    // * expect true
    // TODO: fix - don't pass zyBook test
    inline bool test3_selectionSort()
    {
        NS_TOKEN_FREQ::TokenFreq tf1;

        std::string input1 = "love amor cristiano ronaldo ronaldo";
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> expected1 = {{"amor", 1}, {"cristiano", 1}, {"love", 1}, {"ronaldo", 2}};
        NS_TOKEN_FREQ::vector<NS_TOKEN_FREQ::TokenFreq> output1;
        NS_TOKEN_FREQ::getTokenFreqVec(input1, output1);
        NS_TOKEN_FREQ::selectionSort(output1);

        if (static_cast<int>(output1.size()) != static_cast<int>(expected1.size()))
        {
            return false;
        }

        for (int i = 0; i < static_cast<int>(output1.size()); i++)
        {
            std::cout << "output1[" << i << "].freq : " << output1[i].freq << std::endl;
            std::cout << "expected1[" << i << "].freq : " << expected1[i].freq << std::endl;
            if (output1[i].freq != expected1[i].freq)
            {
                return false;
            }
        }
        return true;
    }
}

#endif
