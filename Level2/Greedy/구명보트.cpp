//https://school.programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());// ���� ~ ŭ ����
	int p1 = people.size() - 1;//�� ������ index �ʱ�ȭ
	int p2 = 0;// �� �� index �ʱ�ȭ
	int boat = 0;
	while (p1 >= p2)//
	{
		if (p1 != p2)// ���� ����� �ƴϴ�.
		{
			if (people[p1] + people[p2] <= limit) // Ż �� �ִ�
			{
				++boat;// �迡 ź��.
				--p1;// ���� ������
				++p2;// ���� ���ſ�
			}
			else //��ź�� (���ſ� ����̶� ���� Ż �� �ִ� ����� ���� == ȥ�� ��Ÿ���Ѵ�.)
			{
				++boat;// �迡 ź��.
				--p1; // ���� ������
			}
		}
		else if (p1 == p2)// ���� ���
		{
			++boat;// �迡 ź��.
			--p1;// ���� ������
			++p2;// ���� ���ſ�
		}
	}

	answer = boat;
	return answer;
}