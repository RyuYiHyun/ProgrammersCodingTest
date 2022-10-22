//https://school.programmers.co.kr/learn/courses/30/lessons/12909
#pragma region Default & STL Include
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#pragma endregion

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> _stack;
    for (auto element : s)
    {
        if (element == '(')
        {
            _stack.push(element);
        }
        else if (element == ')')
        {
            if (_stack.empty())
            {
                answer = false;
                return answer;
            }
            else
            {
                _stack.pop();
            }
        }
    }
    if (!_stack.empty())
    {
        answer = false;
        return answer;
    }

    return answer;
}