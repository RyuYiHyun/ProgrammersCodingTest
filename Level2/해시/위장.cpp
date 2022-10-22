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
		if (map.count(clothes[i][1])) //키가 이미 존재
		{
			++(map[clothes[i][1]]); // 증가
		}
		else
		{
			map.insert(make_pair(clothes[i][1], 1));// 없었으면 1개 등록
		}
	}
	int total = 1; // 베이스
	for (auto element : map)
	{
		total *= (element.second + 1); // 종류중 안입은 경우 추가해서 곱하기
	}
	answer = total - 1; // 아무것도 안입은 경우 빼기
	return answer;
}