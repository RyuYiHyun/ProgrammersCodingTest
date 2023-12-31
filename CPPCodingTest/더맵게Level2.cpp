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
    //초기 음식 정보 입력
    for (auto s : scoville)
    {
        pq.push(s);
    }
    
    while (true)
    {
        // 최소 스코빌이 K 이상인지 체크
        if (pq.top() >= K)
        {
            break;
        }
        //1.최소 스코빌이 K 이상이 아니면 음식을 섞기
        //2.섞기전 음식이 2개 이상인지 체크(섞을 수 있는지)
        if (pq.size() < 2)
        {//섞을 음식이 없다 근데 최소 스코빌이 K에 도달 못함 -> K 이상 도달 불가
            answer = -1;// -1값 정답
            break;
        }
        //3.음식이 있으니 섞기
        answer++;// 섞기 횟수 증가

        //음식 2개 추출
        int food1 = pq.top();
        pq.pop();
        int food2 = pq.top();
        pq.pop();
        int mixscoville = Mix_food_scoville(food1, food2);//섞은 스코빌지수
        pq.push(mixscoville);//섞은 음식의 스코빌 넣기
    }

    return answer;
}



int main() 
{
    
    cout << solution(vector<int>{1, 2, 3, 9, 10, 12}, 7);
    return 0;
}