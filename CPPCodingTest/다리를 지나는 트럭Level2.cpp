#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //1초당 진행되는 사항
    // 
    //다리에서 내려가기 1초
    //다리에서 1 length 나아가기 1초
    //다리에 올라가기 1초
    queue<int> start;
    queue<int> bridge;
    int bridge_weight = 0;//초기 하중 0
    //대기 트럭 설정
    for (auto truck : truck_weights)
    {
        start.push(truck);
    }
    //다리에 길이만큼 가상의 무게 0인 트럭 세우기
    for (int i = 0 ;i < bridge_length; i++)
    {
        bridge.push(0);
    }
    //1초 마다 진행 되는 로직
    while (true)
    {
        //하나 내리기
        //하나 다리 진행
        int out_weight = bridge.front();
        bridge_weight -= out_weight;// 하중 빼기
        bridge.pop();
        //하나 올리기
        if (!start.empty())
        {
            int in_weigth = start.front();//늘어날 하중
            if (bridge_weight + in_weigth <= weight)
            {//버틸 수 있으면 올리기
                bridge_weight += in_weigth;
                bridge.push(in_weigth);
                start.pop();
            }
            else
            {//못올리면 가상 무게 0 트럭 올리기 - 앞에 있는 트럭 전진 효과
                bridge.push(0);
            }
        }
        answer++;//시간 경과 1초
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