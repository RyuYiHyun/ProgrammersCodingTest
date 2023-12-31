#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //1�ʴ� ����Ǵ� ����
    // 
    //�ٸ����� �������� 1��
    //�ٸ����� 1 length ���ư��� 1��
    //�ٸ��� �ö󰡱� 1��
    queue<int> start;
    queue<int> bridge;
    int bridge_weight = 0;//�ʱ� ���� 0
    //��� Ʈ�� ����
    for (auto truck : truck_weights)
    {
        start.push(truck);
    }
    //�ٸ��� ���̸�ŭ ������ ���� 0�� Ʈ�� �����
    for (int i = 0 ;i < bridge_length; i++)
    {
        bridge.push(0);
    }
    //1�� ���� ���� �Ǵ� ����
    while (true)
    {
        //�ϳ� ������
        //�ϳ� �ٸ� ����
        int out_weight = bridge.front();
        bridge_weight -= out_weight;// ���� ����
        bridge.pop();
        //�ϳ� �ø���
        if (!start.empty())
        {
            int in_weigth = start.front();//�þ ����
            if (bridge_weight + in_weigth <= weight)
            {//��ƿ �� ������ �ø���
                bridge_weight += in_weigth;
                bridge.push(in_weigth);
                start.pop();
            }
            else
            {//���ø��� ���� ���� 0 Ʈ�� �ø��� - �տ� �ִ� Ʈ�� ���� ȿ��
                bridge.push(0);
            }
        }
        answer++;//�ð� ��� 1��
        if (start.empty() && bridge_weight == 0)
        {
            break;
        }
    }
    return answer;
}



int main() 
{
    cout << solution(100, 100 ,vector<int>{10, 10, 10, 10, 10, 10, 10, 10, 10, 10});
    return 0;
}