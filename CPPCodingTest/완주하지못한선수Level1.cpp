#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;



string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> participantCounter;
    unordered_map<string, int> completionCounter;
    for (const auto& var : participant)
    {
        if (participantCounter.count(var) == 0) 
        {
            participantCounter.insert(make_pair(var, 1));
        }
        else
        {
            ++participantCounter[var];
        }
    }
    for (const auto& var : completion)
    {
        if (completionCounter.count(var) == 0)
        {
            completionCounter.insert(make_pair(var, 1));
        }
        else
        {
            ++completionCounter[var];
        }
    }
    //������ ������ >= �������̹Ƿ� ������ - ������ = �̿�����
    for (const auto& var : participantCounter)
    {
        if (completionCounter.count(var.first))
        {//�����ڰ� ������
            participantCounter[var.first] = participantCounter[var.first] - completionCounter[var.first];
        }
    }
    for (const auto& var : participantCounter)
    {
        if (participantCounter[var.first] > 0)
        {// �̿����� - ���� 1���� �ƴϿ����ÿ��� answer�� vector�� ���̰� insert�ϱ�
            answer = var.first;
        }
    }
    return answer;
}
int solution()
{
    int answer = 0;
    
    return answer;
}



int main()
{
    cout << solution();
    
    return 0;
}