#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> OS;
    //���μ��� ����
    for (int i =0; i<priorities.size();i++)
    {
        OS.push(make_pair(priorities[i], i));//�켱���� ��, ��ġ
    }
    //�켱������ ����
    sort(priorities.begin(),priorities.end(), greater<int>());// ��������

    while (!OS.empty())
    {
        auto process = OS.front();
        if (process.first == priorities.front())
        {// ���� �����ؾ��� ���� ã��
            //���� == ť���� ����
            answer++;
            if (process.second == location)
            {
                break;
            }
            OS.pop();
            priorities.erase(priorities.begin());
        }
        else
        {// �����Ұ� �ƴϸ� �������� �ѱ��
            OS.push(process);
            OS.pop();
        }
    }
    return answer;
}



int main() 
{
    cout << solution(vector<int>{ 1, 1, 9, 1, 1, 1 }, 2);
    return 0;
}