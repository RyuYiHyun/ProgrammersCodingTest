#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp
{//오름차순 값이 낮을수로 먼저 pop (>)
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.first > b.first;
	}
};

struct cmp2
{//오름차순 값이 낮을수로 먼저 pop (>)
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int solution(vector<vector<int>> jobs)
{
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> workPoolQueue;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp2> readyWorkQueue;
	//할 작업 세팅
	for (int i = 0; i < jobs.size(); i++)
	{
		workPoolQueue.push(make_pair(jobs[i][0], jobs[i][1]));
	}

	int time = 0;
	int total = 0;
	while (true)
	{
		if (readyWorkQueue.empty() && workPoolQueue.empty())
		{// 모든 작업을 완료시 나가기
			break;
		}
		while (!workPoolQueue.empty())
		{
			auto job = workPoolQueue.top();
			if (job.first <= time)
			{//작업 요청 가능 - 일감 찾기
				workPoolQueue.pop();
				readyWorkQueue.push(job);
			}
			else
			{
				if (readyWorkQueue.empty())
				{//작업할게 없으면 시간 흐름
					time += 1;
				}
				else
				{//작업할게 있으면 작업으로 넘어감 
					break;
				}
			}
		}
		//작업
		if (!readyWorkQueue.empty())
		{//작업할게 있는면 체크
			auto workjob = readyWorkQueue.top();
			readyWorkQueue.pop();
			time += workjob.second;//작업하기 - 해당 시간동안 다른 작업 불가
			//time여기서 time은 해당 작업을 완료한 시간
			// 완료한 시간 - 요청시간 = 요청에서 종료까지의 시간 (time - workjob.first)
			total = total + (time - workjob.first);
		}
	}

	answer = (int)(total / jobs.size());

	return answer;
}


int main()
{
	cout << solution(vector<vector<int>>{ {0, 3}, { 1,9 }, { 2,6 }});
	return 0;
}