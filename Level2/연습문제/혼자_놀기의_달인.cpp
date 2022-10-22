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
	unordered_map<int, bool> box;// 박스 번호 : 확인 여부
	vector<int> group(101);// 그룹 번호 : 수량
	queue<int> boxnum;
	for (int i = 1; i <= cards.size(); ++i) // 1번 박스에서 카드 수만큼의 박스 설정
	{
		box[i] = false;// 0 그룹 번호 초기 세팅
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
			box[index + 1] = true;// 박스 확인
			int nextbox = cards[index];// 박스에 있는 숫자 확인
			++group[groupNum];// 그룹 카운드 증가
			if (box[nextbox])
			{// 이미 확인한 박스 (그룹이 마감)
				++groupNum; // 다음 그룹
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