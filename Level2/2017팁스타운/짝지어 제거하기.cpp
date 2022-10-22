//https://school.programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> _stack;

	for (auto element : s)
	{
		if (!_stack.empty())
		{
			if (_stack.top() == element)
			{
				_stack.pop();
				continue;
			}
		}
		_stack.push(element);
	}
	if (_stack.empty())
	{
		return 1;
	}
	return 0;
}