#include <iostream> //
#include <iomanip>
#include <string>
#include <sstream>
#include <map> // instead of using <bits/stdc++.h>
#include <vector>

// #include "tokenFreq.hpp"

using namespace std;

struct TokenFreq
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

void countNbrWords(string input) // https://www.geeksforgeeks.org/stringstream-c-applications/get fe
{
    std::cout << "TESTING COUNTING WORDS" << endl;
    // count number word in input -- breaking input into word using string stream
    stringstream ss(input); // Used for breaking words

    int count = 0;
    string token; // To store individual words
    while (ss >> token)
    {
        count++;
    }
    cout << "Number of tokens (without case insensitive): " << count << endl;
    std::cout << "END TESTING COUNTING WORDS" << endl;
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
void sortVectorAscOrderByFreq(vector<TokenFreq> &vector)
{
    sort(vector.begin(), vector.end(), comparebyFreqAscOrder); // https://www.geeksforgeeks.org/sort-c-stl/
                                                               // https://en.cppreference.com/w/cpp/algorithm/sort
}

// sort vectors on descending order by TokenFreq freq
void sortVectorDescOrderByFreq(vector<TokenFreq> &vector)
{
    sort(vector.begin(), vector.end(), comparebyFreqDescOrder); // https://www.geeksforgeeks.org/sort-c-stl/
                                                                // https://en.cppreference.com/w/cpp/algorithm/sort
}

// ! don't work
void selectionSortVector(vector<TokenFreq> vector, int vectorSize)
{

    int i, j, minIndex;
    int tempFreq;

    for (i = 0; i < vectorSize - 1; i++)
    {

        minIndex = i;

        for (j = i + 1; j < vectorSize; j++)

            if (vector[j].freq < vector[minIndex].freq)
            {
                minIndex = j;
            }

        if (minIndex != i)
        {
            tempFreq = vector[i].freq;

            vector[i].freq = vector[minIndex].freq;

            vector[minIndex].freq = tempFreq;
        }
    }
}

void printFrequency(string &st) //
{

    cout << "CHECKING NEGATIVE CASE (EMPTY STRING or ONLY WHITES SPACE STRING)" << endl
         << endl;
    cout << "IT WONT RETURN THE \'END\' OF THE CHECKING IF NEGATIVE CASE NOT PASS" << endl;
    cout << "-> IF NEGATIVE CASE NO PASS, IT WILL EXIT THE FUNCTION PRINT FREQUENCY" << endl;

    // empty string (negative case)
    if (st.empty())
    {
        cout << "empty string"
             << "\n";
        return;
    }

    int isspace(char c);

    // ! if statement will always return true because the address of
    // ! a function, isspace, is not zero and "not zero" means true
    // * been fixed in the unitTest.hpp
    // if (st.begin(), st.end(), isspace == 0)
    // {
    //     std::cout << "there is white space"
    //               << "\n";
    //     return;
    // }
    // else
    // {
    //     cout << "There is no whitespace"
    //          << "\n";
    // }

    int N = st.length();
    // Traverse the string
    for (int i = 0; i < N; i++)
    { // Print current character
        cout << st[i] << " ";
        if (st[i] != ' ')
        {
            cout << "It's not a string of white space only"
                 << "\n";
        }
        else
        {
            st = "Only white space";
            cout << st << "\n";
            return;
        }
    }

    cout << "END CHECKING NEGATIVE CASE (EMPTY STRING or ONLY WHITES SPACE STRING)" << endl;
    cout << "NEGATIVE CASE PASSED -> printFrequency will pursue" << endl
         << endl;

    cout << "TESTING MAPPING TOKEN + FREQUENCY TO MAP KEY VALUE" << endl
         << endl;
    // * TESTING MAPPING TOKEN + FREQUENCY TO MAP KEY VALUE
    //  Each word it mapped to
    //  it's frequency
    map<string, int> FW;

    // Used for breaking words
    stringstream ss(st);

    // To store individual words
    string Word;

    while (ss >> Word)
    {
        // Convert the word to lowercase -- https://www.geeksforgeeks.org/transform-c-stl-perform-operation-elements/
        transform(Word.begin(), Word.end(), Word.begin(), ::tolower);

        FW[Word]++;
    }

    // get the total number of keys
    cout << "Map Size : " << FW.size() << endl; // https://stackoverflow.com/questions/60784338/how-to-get-number-of-keys-in-stdmap

    // print each value-key pair of FW -- basically print map FW
    map<string, int>::iterator m;
    for (auto m = FW.begin(); m != FW.end(); m++) // https://stackoverflow.com/questions/4263640/find-mapped-value-of-map
    {
        cout << m->first << " -> "
             << m->second << endl;
    }
    cout << "END TESTING MAPPING TOKEN + FREQUENCY TO MAP KEY VALUE" << endl
         << endl;
    // * END TESTING MAPPING TOKEN + FREQUENCY TO MAP KEY VALUE

    vector<TokenFreq> test; // init vector test of type TokenFreq

    // * TESTING MAPPING MAP FW to TokenFreq + APPEND TO VECTOR
    std::cout << "TESTING MAPPING MAP FW to TokenFreq + APPEND TO VECTOR" << std::endl;
    for (auto const &pair : FW)
    {
        TokenFreq tokenTest;
        tokenTest.token = pair.first;
        tokenTest.freq = pair.second;
        test.push_back(tokenTest);
    }

    int testSize = test.size();

    int countToken = 0;
    cout << "size = " << testSize << " {" << endl;
    for (auto const &tokenObject : test)
    {
        std::cout << "[" << countToken << "] = (token = \"" << tokenObject.token << "\", freq = " << tokenObject.freq << ")" << endl;
        countToken++;
    }
    cout << "}" << endl;

    cout << "vector test size : " << test.size() << endl;
    std::cout << "END TESTING MAPPING MAP FW to TokenFreq + APPEND TO VECTOR" << std::endl
              << endl;
    // * END TESTING MAPPING MAP FW to TokenFreq + APPEND TO VECTOR

    // * TESTING SORTING ASCENDING
    cout << "TESTING SORTING ASCENDING" << endl;

    sortVectorAscOrderByFreq(test);
    int countTokenSortingAsc = 0;

    cout << "size = " << testSize << " {" << endl;
    for (auto const &tokenObject : test)
    {
        std::cout << "[" << countTokenSortingAsc << "] = (token = \"" << tokenObject.token << "\", freq = " << tokenObject.freq << ")" << endl;
        countTokenSortingAsc++;
    }

    cout << "END TESTING SORTING ASCENDING" << endl
         << endl;
    // * END TESTING SORTING DESCENDING

    // * TESTING SORTING DESCENDING
    cout << "TESTING SORTING DESCENDING" << endl;

    sortVectorDescOrderByFreq(test);
    int countTokenSortingDesc = 0;

    cout << "size = " << testSize << " {" << endl;
    for (auto const &tokenObject : test)
    {
        std::cout << "[" << countTokenSortingDesc << "] = (token = \"" << tokenObject.token << "\", freq = " << tokenObject.freq << ")" << endl;
        countTokenSortingDesc++;
    }

    cout << "END TESTING SORTING DESCENDING" << endl
         << endl;

    // * END TESTING SORTING DESCENDING
}

// compare tokenFreq freq < (needed for overload <=)
bool compareByFreq(const TokenFreq &lhs, const TokenFreq &rhs)
{
    return lhs.freq < rhs.freq;
}

// overload operator less or equal
bool operator<=(const TokenFreq &lhs, const TokenFreq &rhs) // https://en.cppreference.com/w/cpp/language/operators
{
    std::cout << "Value of <= : " << (compareByFreq(lhs, rhs) || lhs.freq == rhs.freq) << std::endl;
    return compareByFreq(lhs, rhs) || lhs.freq == rhs.freq; // return 1 if lhs <= rhs
}

std::ostream &operator<<(std::ostream &os, const TokenFreq &obj)
{
    os << "Token: " << obj.token << ", Freq: " << obj.freq;

    return os; // write obj to stream
}

// overload operator + to add members of two TokenFreq into a third TokenFreq
TokenFreq operator+(const TokenFreq &lhs, const TokenFreq &rhs)
{
    TokenFreq sumTokenFreq;

    sumTokenFreq.token = lhs.token + " or " + rhs.token;
    sumTokenFreq.freq = lhs.freq + rhs.freq;

    cout << "Value of sumTokenFreq.token : " << sumTokenFreq.token << "\nValue of sumTokenFreq.freq : " << sumTokenFreq.freq << endl;
    cout << "Value of sumTokenFreq : " << sumTokenFreq << endl;
    return sumTokenFreq;
}

int main()
{

    cout << "Inside Main (It's working)"
         << "\n";

    // string input = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    // string input1 = "love amor cristiano ronaldo ronaldo";
    // cout << "Size of my input : " << input1.size() << endl
    //      << endl;

    // cout << "Calling countNbrWords function" << endl;
    // countNbrWords(input1); // get the numbers of word inside input

    // cout << endl;
    // cout << "Calling printFrequency function" << endl;
    // printFrequency(input1);

    // cout << "TESTING OPERATOR OVERLOADING <=" << endl;
    // TokenFreq testTokenFreq1("zizi", 50);
    // TokenFreq testTokenFreq2("kekette", 20);

    // if (testTokenFreq1 <= testTokenFreq2)
    // {
    //     cout << "testTokenFreq1.freq <= testTokenFreq2 because " << testTokenFreq1.freq << " <= " << testTokenFreq2.freq << endl;
    // }
    // else
    // {
    //     cout << "testTokenFreq1.freq > testTokenFreq2 because " << testTokenFreq1.freq << " > " << testTokenFreq2.freq << endl;
    // }
    // cout << "END TESTING OPERATOR OVERLOADING <=" << endl
    //      << endl;

    // cout << "TESTING OPERATOR OVERLOADING +" << endl;
    // TokenFreq testTokenFreq3("red", 10);
    // TokenFreq testTokenFreq4("blue", 20);
    // TokenFreq testTokenFreq5("", 0);
    // // * undo comments from overload function for testing

    // testTokenFreq5 = testTokenFreq3 + testTokenFreq4;

    // cout << "END TESTING OPERATOR OVERLOADING +" << endl
    //      << endl;

    // cout << "TESTING OPERATOR OVERLOADING <<" << endl;
    // TokenFreq testTokenFreq6("dream", 12);
    // cout << testTokenFreq6 << endl;

    // cout << "END TESTING OPERATOR OVERLOADING <<" << endl;

    // vector<TokenFreq> test;
    // test.resize(46);

    // for (vector<TokenFreq>::iterator it = test.begin(); it != test.end(); ++it)
    // {
    //     cout << "Token: " << it->token << ", Frequency: " << it->freq << endl;
    // }

    // std::string input2 = "Seoul Korea Korea Korea Oh Ah yes";
    // vector<TokenFreq> expected1 = {{"ah", 1}, {"korea", 3}, {"oh", 1}, {"seoul", 1}, {"yes", 1}};
    // vector<TokenFreq> output1;
    // printFrequency(input2);

    // // * negative case empty string
    // std::string input3 = "";
    // printFrequency(input3);

    // if (input3 == "")
    // {
    //     cout << "test negative case working emty string"
    //          << "\n";
    // }

    // std::string input4 = "Ateyaba";
    // int N = input4.length();
    // // Traverse the string
    // for (int i = 0; i < N; i++)
    // {
    //     int N = input4.length();
    //     // Print current character
    //     cout << input4[i] << " ";
    // }

    // // * negative case space
    std::string input4 = "      ";
    cout << input4.length() << "\n";
    cout << "white space test "
         << "\n";
    printFrequency(input4);

    if (input4 == "Only white space")
    {
        cout << "Only white space test checked"
             << "\n";
    }

    // if (input4 == "")
    // {
    //     cout << "test negative case working multiple space"
    //          << "\n";
    // }

    return 0;
}