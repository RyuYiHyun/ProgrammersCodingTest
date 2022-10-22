//https://school.programmers.co.kr/learn/courses/30/lessons/12951
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

string solution(string s) {
    string answer = "";

    bool flag = false;
    for (auto chr : s)
    {
        if (chr == ' ')
        {
            flag = false;
            answer.push_back(chr);
            continue;
        }
        if ('0' <= chr && chr <= '9')// 숫자
        {
            flag = true;
            answer.push_back(chr);
            continue;
        }
        if ('A' <= chr && chr <= 'Z')// 대문자
        {
            if (flag)
            {
                answer.push_back((char)(chr + 32));
            }
            else
            {
                flag = true;
                answer.push_back((char)chr);
            }
            continue;
        }
        if ('a' <= chr && chr <= 'z')// 소문자
        {
            if (flag)
            {
                answer.push_back((char)chr);
            }
            else
            {
                flag = true;
                answer.push_back((char)(chr - 32));
            }
            continue;
        }
    }

    return answer;
}