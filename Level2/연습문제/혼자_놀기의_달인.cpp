//https://school.programmers.co.kr/learn/courses/30/lessons/131130
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int> cards)
{
	int answer = 0;
	unordered_map<int, bool> box;// �ڽ� ��ȣ : Ȯ�� ����
	vector<int> group(101);// �׷� ��ȣ : ����
	queue<int> boxnum;
	for (int i = 1; i <= cards.size(); ++i) // 1�� �ڽ����� ī�� ����ŭ�� �ڽ� ����
	{
		box[i] = false;// 0 �׷� ��ȣ �ʱ� ����
		boxnum.push(i);
	}
	int groupNum = 1;
	group[groupNum] = 0;
	while (!boxnum.empty())
	{
		if (box[boxnum.front()])
		{
			boxnum.pop();
			continue;
		}
		int index = boxnum.front() - 1;
		boxnum.pop();
		while (true)
		{
			box[index + 1] = true;// �ڽ� Ȯ��
			int nextbox = cards[index];// �ڽ��� �ִ� ���� Ȯ��
			++group[groupNum];// �׷� ī��� ����
			if (box[nextbox])
			{// �̹� Ȯ���� �ڽ� (�׷��� ����)
				++groupNum; // ���� �׷�
				break;
			}
			else
			{
				index = nextbox - 1;
			}
		}
	}
	sort(group.begin(), group.end(), greater<>());

	return group[0] * group[1];
}