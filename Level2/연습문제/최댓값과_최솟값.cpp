https://school.programmers.co.kr/learn/courses/30/lessons/12939
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> vec;
    for (int i = 0; i < s.size(); ++i)
    {
        bool isPlus = true;
        if (s[i] == ' ')
        {
            continue;
        }
        if (s[i] == '-')
        {
            ++i;
            isPlus = false;
        }
        string temp = "";
        int num = 0;
        while (i < s.size() && s[i] != ' ')
        {
            temp += s[i++];
        }
        if (isPlus)
        {
            num = stoi(temp);
        }
        else
        {
            num = -(stoi(temp));
        }
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    answer += to_string(vec.front());
    answer += " ";
    answer += to_string(vec.back());
    return answer;
}