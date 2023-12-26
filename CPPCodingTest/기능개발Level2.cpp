#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DayOne(vector<int>& progresses, vector<int>& speeds)
{
	for (int i = 0; i < progresses.size(); i++)
	{
		if (progresses[i] >= 100)
		{
			continue;
		}
		else
		{
			progresses[i] = progresses[i] + speeds[i] >= 100 ? 100 : progresses[i] + speeds[i];
		}
	}
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (!progresses.empty())
	{
		DayOne(progresses, speeds);
		int count = 0;
		while (true)
		{
			if (progresses.empty() || progresses.front() < 100)
			{
				break;
			}
			count++;
			progresses.erase(progresses.begin());
			speeds.erase(speeds.begin());
		}
		if (count > 0)
		{
			answer.push_back(count);
		}
	}


	return answer;
}



int main()
{
	auto a = solution(vector<int>{ 93, 30, 55 }, vector<int>{ 1, 30, 5 });

	cout << a.size();

	return 0;
}