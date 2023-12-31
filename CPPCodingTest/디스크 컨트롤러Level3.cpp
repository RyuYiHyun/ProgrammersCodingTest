#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp
{//�������� ���� �������� ���� pop (>)
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.first > b.first;
	}
};

struct cmp2
{//�������� ���� �������� ���� pop (>)
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
	//�� �۾� ����
	for (int i = 0; i < jobs.size(); i++)
	{
		workPoolQueue.push(make_pair(jobs[i][0], jobs[i][1]));
	}

	int time = 0;
	int total = 0;
	while (true)
	{
		if (readyWorkQueue.empty() && workPoolQueue.empty())
		{// ��� �۾��� �Ϸ�� ������
			break;
		}
		while (!workPoolQueue.empty())
		{
			auto job = workPoolQueue.top();
			if (job.first <= time)
			{//�۾� ��û ���� - �ϰ� ã��
				workPoolQueue.pop();
				readyWorkQueue.push(job);
			}
			else
			{
				if (readyWorkQueue.empty())
				{//�۾��Ұ� ������ �ð� �帧
					time += 1;
				}
				else
				{//�۾��Ұ� ������ �۾����� �Ѿ 
					break;
				}
			}
		}
		//�۾�
		if (!readyWorkQueue.empty())
		{//�۾��Ұ� �ִ¸� üũ
			auto workjob = readyWorkQueue.top();
			readyWorkQueue.pop();
			time += workjob.second;//�۾��ϱ� - �ش� �ð����� �ٸ� �۾� �Ұ�
			//time���⼭ time�� �ش� �۾��� �Ϸ��� �ð�
			// �Ϸ��� �ð� - ��û�ð� = ��û���� ��������� �ð� (time - workjob.first)
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