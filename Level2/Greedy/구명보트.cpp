//https://school.programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());// 작은 ~ 큼 정렬
	int p1 = people.size() - 1;//맨 마지막 index 초기화
	int p2 = 0;// 맨 앞 index 초기화
	int boat = 0;
	while (p1 >= p2)//
	{
		if (p1 != p2)// 같은 사람이 아니다.
		{
			if (people[p1] + people[p2] <= limit) // 탈 수 있다
			{
				++boat;// 배에 탄다.
				--p1;// 다음 가벼운
				++p2;// 다음 무거운
			}
			else //못탄다 (무거운 사람이랑 같이 탈 수 있는 사람은 없다 == 혼자 배타야한다.)
			{
				++boat;// 배에 탄다.
				--p1; // 다음 가벼운
			}
		}
		else if (p1 == p2)// 같은 사람
		{
			++boat;// 배에 탄다.
			--p1;// 다음 가벼운
			++p2;// 다음 무거운
		}
	}

	answer = boat;
	return answer;
}