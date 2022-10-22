//https://school.programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;

	int width = 0;// 가로가 길게 설정
	int height = 3;// 초기 높이 3

	int apb = (brown / 2) + 2;// a+b
	width = apb - height;// 가로에 최대한 값 초기화
	while (true)
	{
		if (width + height == apb)
		{
			if (yellow == (width - 2) * (height - 2))
			{
				answer.push_back(width);
				answer.push_back(height);
				break;
			}
			else
			{
				--width;// 가로 줄여보고
				++height;// 세로 늘려보고
			}
		}
	}

	return answer;
}