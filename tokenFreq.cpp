#include "tokenFreq.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <map> // instead of using <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>

namespace NS_TOKEN_FREQ
{
    // using std::vector;

    // * function implementation

    // print the list of unique and case insensitive tokens and their corresponding frequencies identified within istr
    void getTokenFreqVec(string &istr, vector<TokenFreq> &tfVec)
    {

        // * get individual words (token) of istr into a map FW of key-value
        std::map<string, int> FW; // Each word it mapped to it's frequency

        std::stringstream ss(istr); // used for breaking words

        string Word; // to store individual words

        // store each individuals words into map
        while (ss >> Word)
        {
            // Convert the word to lowercase -- https://www.geeksforgeeks.org/transform-c-stl-perform-operation-elements/
            transform(Word.begin(), Word.end(), Word.begin(), ::tolower);

            FW[Word]++;
        }

        // * assign each key-value to struct tokenTest then append to vector tfVec
        for (auto const &pair : FW)
        {
            TokenFreq tokenTest;
            tokenTest.token = pair.first;
            tokenTest.freq = pair.second;
            tfVec.push_back(tokenTest);
        }

        // * print vector tfVec
        int testSize = static_cast<int>(tfVec.size()); // get the size of the vector tfVec
        int countToken = 0;
        std::cout << "size = " << testSize << " {" << std::endl;
        for (auto const &tokenObject : tfVec)
        {
            std::cout << "[" << countToken << "] = (token = \"" << tokenObject.token << "\", freq = " << tokenObject.freq << ")" << std::endl;
            countToken++;
        }
        std::cout << "}" << std::endl;
    }

    // ! remove it if unused
    // void printTokenFreqVec(vector<TokenFreq> &tfVec)
    // {
    //     // * print vector tfVec
    //     int testSize = tfVec.size(); // get the size of the vector tfVec
    //     int countToken = 0;
    //     std::cout << "size = " << testSize << " {" << std::endl;
    //     for (auto const &tokenObject : tfVec)
    //     {
    //         std::cout << "[" << countToken << "] = (token = \"" << tokenObject.token << "\", freq = " << tokenObject.freq << ")" << std::endl;
    //         countToken++;
    //     }
    //     std::cout << "}" << std::endl;
    // }

    // compare tokenFreq freq < (needed for overload <=)
    bool compareByFreq(const TokenFreq &lhs, const TokenFreq &rhs)
    {
        return lhs.freq < rhs.freq;
    }

    // overload operator less or equal <=
    bool operator<=(const TokenFreq &lhs, const TokenFreq &rhs) // https://en.cppreference.com/w/cpp/language/operators
    {
        std::cout << "Value of <= : " << (compareByFreq(lhs, rhs) || lhs.freq == rhs.freq) << std::endl;
        return compareByFreq(lhs, rhs) || lhs.freq == rhs.freq;
    }

    bool operator==(const TokenFreq &lhs, const TokenFreq &rhs)
    {
        return (lhs.token == rhs.token) && (lhs.freq == rhs.freq);
    }

    // bool operator==(const std::vector<TokenFreq> &lhs, const std::vector<TokenFreq> &rhs)
    // {
    //     if (lhs.size() != rhs.size())
    //     {
    //         return false;
    //     }
    //     for (int i = 0; i < lhs.size(); ++i)
    //     {
    //         if (lhs[i].token != rhs[i].token || lhs[i].freq != rhs[i].freq)
    //         {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    std::ostream &operator<<(std::ostream &os, const TokenFreq &obj)
    {
        os << "Token: " << obj.token << ", Freq: " << obj.freq;

        return os; // write obj to stream
    }

    // overload operator + to add members of two TokenFreq into a third TokenFreq
    // overload operator + to add members of two TokenFreq into a third TokenFreq
    TokenFreq operator+(const TokenFreq &lhs, const TokenFreq &rhs)
    {
        TokenFreq sumTokenFreq;

        sumTokenFreq.token = lhs.token + " or " + rhs.token;
        sumTokenFreq.freq = lhs.freq + rhs.freq;

        // std::cout << "Value of sumTokenFreq.token : " << sumTokenFreq.token << "\nValue of sumTokenFreq.freq : " << sumTokenFreq.freq << std::endl;
        // std::cout << "Value of sumTokenFreq : " << sumTokenFreq << std::endl;
        return sumTokenFreq;
    }

    // custom comparator who compare ascending order of TokenFreq freq
    bool comparebyFreqAscOrder(const TokenFreq &a, const TokenFreq &b)
    {
        return a.freq < b.freq;
    }

    // custom comparator who compare descending order of TokenFreq freq
    bool comparebyFreqDescOrder(const TokenFreq &a, const TokenFreq &b)
    {
        return a.freq > b.freq;
    }

    // sort vectors on ascending order by TokenFreq freq
    void selectionSort(vector<TokenFreq> &tokFreqVector)
    {
        sort(tokFreqVector.begin(), tokFreqVector.end(), comparebyFreqAscOrder); // https://www.geeksforgeeks.org/sort-c-stl/
                                                                                 // https://en.cppreference.com/w/cpp/algorithm/sort
    }

    // sort vectors on descending order by TokenFreq freq
    void insertionSort(vector<TokenFreq> &tokFreqVector)
    {
        sort(tokFreqVector.begin(), tokFreqVector.end(), comparebyFreqDescOrder); // https://www.geeksforgeeks.org/sort-c-stl/
                                                                                  // https://en.cppreference.com/w/cpp/algorithm/sort
    }
}