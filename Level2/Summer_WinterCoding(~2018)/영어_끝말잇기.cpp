//https://school.programmers.co.kr/learn/courses/30/lessons/12981
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;

	unordered_map<string, bool> talkWords;
	unordered_map<int, int> people;
	for (int i = 1; i <= n; i++)
	{
		people.insert(make_pair(i, 0));// 사람등록
	}
	int number = 1;
	string frontWords = "";
	for (int i = 0; i < words.size(); ++i)// 단어 차례대로 말하기
	{
		++people[number];// 말한 수 증가
		//if (talkWords.count(words[i]))// 말한 적이 있는 단어 인지 확인
		if (talkWords[words[i]])
		{
			answer.push_back(number);
			answer.push_back(people[number]);
			return answer;
		}
		else
		{
			// 말한 적이 없는 단어임
			talkWords[words[i]] = true;//말한 단어 등록
			if (frontWords != "")
			{
				if (frontWords.back() != words[i].front())// 끝말 철자 확인
				{
					answer.push_back(number);
					answer.push_back(people[number]);
					return answer;
				}
			}
			frontWords = words[i]; // 정상적으로 말함 전에 말한 말로 등록
			++number;// 다음 사람
			if (number > n)// 다음 사람이 없으면 다시 처음 사람으로
			{
				number = 1;
			}
		}
	}

	answer.push_back(0);
	answer.push_back(0);
	return answer;
}