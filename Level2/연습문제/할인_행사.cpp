//https://school.programmers.co.kr/learn/courses/30/lessons/131127
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
	int answer = 0;
	unordered_map<string, int> count;
	for (auto element : want)
	{
		count.insert(make_pair(element, 0));
	}

	for (int i = 0; i < discount.size() - 9; ++i)
	{
		int range = i + 10;
		for (int j = i; j < range; ++j)
		{
			++count[discount[j]];
		}
		bool flag = true;
		for (int j = 0; j < want.size(); ++j)
		{
			if (count[want[j]] != number[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			++answer;
		}
		for (auto element : want)
		{
			count[element] = 0;
		}
	}
	return answer;
}