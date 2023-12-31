#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> prices)
{
	vector<int> answer;
	for (int i = 0; i < prices.size(); i++)
	{
		int time = 0;
		for (int j = i+1; j < prices.size(); j++)
		{
			time++;
			if (prices[i] > prices[j])
			{
				break;
			}
		}
		answer.push_back(time);
	}

	return answer;
}



int main()
{
	vector<int> a = solution(vector<int>{1, 2, 3, 2, 3});
	for (auto e : a)
	{
		cout << e << "\t";
	}
	return 0;
}