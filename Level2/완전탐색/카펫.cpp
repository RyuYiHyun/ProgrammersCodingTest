//https://school.programmers.co.kr/learn/courses/30/lessons/42842
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;

	int width = 0;// ���ΰ� ��� ����
	int height = 3;// �ʱ� ���� 3

	int apb = (brown / 2) + 2;// a+b
	width = apb - height;// ���ο� �ִ��� �� �ʱ�ȭ
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
				--width;// ���� �ٿ�����
				++height;// ���� �÷�����
			}
		}
	}

	return answer;
}