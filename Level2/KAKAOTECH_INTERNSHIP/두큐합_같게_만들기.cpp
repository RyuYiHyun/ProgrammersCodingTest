//https://school.programmers.co.kr/learn/courses/30/lessons/118667
#include <string>
#include <vector>

using namespace std;

unsigned long long Sum(const vector<int>& queue)
{
	unsigned long long sum = 0;
	for (auto element : queue)
	{
		sum += element;
	}
	return sum;
}

int solution(vector<int> queue1, vector<int> queue2)
{
	int answer = -1;
	int count = queue1.size();
	count = count << 2;// 완전히 섞어서 다시 원상 복귀까지 사이즈의 4번 이동
	unsigned long long goal = (Sum(queue1) + Sum(queue2));
	if (goal & 1)
	{// 합이 홀수 이면 나누기 불가능
		return answer;
	}

	unsigned long long q1sum = Sum(queue1);
	int index1 = 0;
	unsigned long long q2sum = Sum(queue2);
	int index2 = 0;
	answer = 0;
	while (answer <= count)
	{
		if (q1sum > q2sum)
		{
			q1sum -= queue1[index1];
			q2sum += queue1[index1];
			queue2.push_back(queue1[index1]);
			++index1;
			++answer;
		}
		else if (q1sum < q2sum)
		{
			q1sum += queue2[index2];
			q2sum -= queue2[index2];
			queue1.push_back(queue2[index2]);
			++index2;
			++answer;
		}
		else
		{
			return answer;
		}
	}
	return -1;
}