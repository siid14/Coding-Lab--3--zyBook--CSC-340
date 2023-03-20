#ifndef TOKEN_FREQ_HPP
#define TOKEN_FREQ_HPP

#include <algorithm>
#include <vector>
#include <string>

namespace NS_TOKEN_FREQ
{
    using std::string;
    using std::vector;

    // * structure prototype

    struct TokenFreq // https://stackoverflow.com/questions/2732978/c-how-to-declare-a-struct-in-a-header-file
    {
        std::string token;
        int freq;

        TokenFreq() : token(""), freq(0) {}

        TokenFreq(string userToken, int userFreq)
        {
            token = userToken;
            freq = userFreq;
        }
    };

    // * function prototype

    void getTokenFreqVec(string &istr, vector<TokenFreq> &tfVec);

    void printTokenFreqVec(vector<TokenFreq> &tfVec); // ? maybe implement a different function to print TokenFreq

    bool compareByFreq(const TokenFreq &lhs, const TokenFreq &rhs);

    bool operator<=(const TokenFreq &lhs, const TokenFreq &rhs);

    bool operator==(const TokenFreq &lhs, const TokenFreq &rhs);

    TokenFreq operator+(const TokenFreq &lhs, const TokenFreq &rhs);

    std::ostream &operator<<(std::ostream &os, const TokenFreq &obj);

    void selectionSort(vector<TokenFreq> &tokFreqVector);

    void insertionSort(vector<TokenFreq> &tokFreqVector);

    bool comparebyFreqAscOrder(const TokenFreq &a, const TokenFreq &b);

    bool comparebyFreqDescOrder(const TokenFreq &a, const TokenFreq &b);

}

#endif