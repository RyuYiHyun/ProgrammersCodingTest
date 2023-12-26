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
    //프로세스 세팅
    for (int i =0; i<priorities.size();i++)
    {
        OS.push(make_pair(priorities[i], i));//우선순위 값, 위치
    }
    //우선순위값 정렬
    sort(priorities.begin(),priorities.end(), greater<int>());// 내림차순

    while (!OS.empty())
    {
        auto process = OS.front();
        if (process.first == priorities.front())
        {// 먼저 실행해야할 것을 찾음
            //실행 == 큐에서 제거
            answer++;
            if (process.second == location)
            {
                break;
            }
            OS.pop();
            priorities.erase(priorities.begin());
        }
        else
        {// 실행할게 아니면 다음으로 넘기기
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