//https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 0;

	int row = clothes.size();
	unordered_map<string, int> map;
	for (int i = 0; i < row; ++i)
	{
		if (map.count(clothes[i][1])) //Ű�� �̹� ����
		{
			++(map[clothes[i][1]]); // ����
		}
		else
		{
			map.insert(make_pair(clothes[i][1], 1));// �������� 1�� ���
		}
	}
	int total = 1; // ���̽�
	for (auto element : map)
	{
		total *= (element.second + 1); // ������ ������ ��� �߰��ؼ� ���ϱ�
	}
	answer = total - 1; // �ƹ��͵� ������ ��� ����
	return answer;
}