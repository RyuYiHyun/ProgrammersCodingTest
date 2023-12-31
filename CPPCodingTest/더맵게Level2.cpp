#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int Mix_food_scoville(int food1, int food2)
{
    return food1 + food2 * 2;
}

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    int tempK = 0;
    priority_queue<int,vector<int>, greater<int>> pq;
    //�ʱ� ���� ���� �Է�
    for (auto s : scoville)
    {
        pq.push(s);
    }
    
    while (true)
    {
        // �ּ� ���ں��� K �̻����� üũ
        if (pq.top() >= K)
        {
            break;
        }
        //1.�ּ� ���ں��� K �̻��� �ƴϸ� ������ ����
        //2.������ ������ 2�� �̻����� üũ(���� �� �ִ���)
        if (pq.size() < 2)
        {//���� ������ ���� �ٵ� �ּ� ���ں��� K�� ���� ���� -> K �̻� ���� �Ұ�
            answer = -1;// -1�� ����
            break;
        }
        //3.������ ������ ����
        answer++;// ���� Ƚ�� ����

        //���� 2�� ����
        int food1 = pq.top();
        pq.pop();
        int food2 = pq.top();
        pq.pop();
        int mixscoville = Mix_food_scoville(food1, food2);//���� ���ں�����
        pq.push(mixscoville);//���� ������ ���ں� �ֱ�
    }

    return answer;
}



int main() 
{
    
    cout << solution(vector<int>{1, 2, 3, 9, 10, 12}, 7);
    return 0;
}