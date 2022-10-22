//https://school.programmers.co.kr/learn/courses/30/lessons/70129
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string reverse(const string str)
{
    string temp;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        temp.push_back(str[i]);
    }
    return temp;
}

string twoConverter(int value)
{
    string convertString = "";
    while (value >= 2)
    {
        if (value % 2 == 0)
        {
            value = (int)(value / 2);
            convertString.push_back('0');
        }
        else
        {
            value = (int)(value / 2);
            convertString.push_back('1');
        }
    }
    if (value == 1)
    {
        convertString.push_back('1');
    }
    convertString = reverse(convertString);
    return convertString;
}

vector<int> solution(string s) {
    vector<int> answer;

    int zeroNum = 0;
    int convertNum = 0;
    while (s != "1")
    {
        ++convertNum;
        string temp = "";
        for (auto x : s)
        {
            if (x == '0')
            {
                ++zeroNum;
            }
            else
            {
                temp.push_back('1');
            }
        }
        int len = temp.size();
        s = twoConverter(len);
    }
    answer.push_back(convertNum);
    answer.push_back(zeroNum);
    return answer;
}
