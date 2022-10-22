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
		people.insert(make_pair(i, 0));// ������
	}
	int number = 1;
	string frontWords = "";
	for (int i = 0; i < words.size(); ++i)// �ܾ� ���ʴ�� ���ϱ�
	{
		++people[number];// ���� �� ����
		//if (talkWords.count(words[i]))// ���� ���� �ִ� �ܾ� ���� Ȯ��
		if (talkWords[words[i]])
		{
			answer.push_back(number);
			answer.push_back(people[number]);
			return answer;
		}
		else
		{
			// ���� ���� ���� �ܾ���
			talkWords[words[i]] = true;//���� �ܾ� ���
			if (frontWords != "")
			{
				if (frontWords.back() != words[i].front())// ���� ö�� Ȯ��
				{
					answer.push_back(number);
					answer.push_back(people[number]);
					return answer;
				}
			}
			frontWords = words[i]; // ���������� ���� ���� ���� ���� ���
			++number;// ���� ���
			if (number > n)// ���� ����� ������ �ٽ� ó�� �������
			{
				number = 1;
			}
		}
	}

	answer.push_back(0);
	answer.push_back(0);
	return answer;
}