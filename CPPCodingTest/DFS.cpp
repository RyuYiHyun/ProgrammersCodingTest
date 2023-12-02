#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> networkInfos;
vector<bool> check;
int totalNumber;
void DFS(int computerNumber)
{
    for (int i = 0; i < totalNumber; i++)
    {
        if (networkInfos[computerNumber][i] == 1 && !check[i])
        {//computerNumber의 컴퓨터와 i 컴퓨터가 연결 되어있고 연결 상태를 확인한 여부가 없을 경우
            check[i] = true;// 조회 완료
            DFS(i);//i로 들어가서 깊이 순회
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) 
{
    check.assign(n, false);

    networkInfos.assign(computers.size(), vector<int>(computers.size()));
    copy(computers.begin(), computers.end(), networkInfos.begin());
    totalNumber = n;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
        {
            DFS(i);
            answer++;
        }
    }
    return answer;
}



int main() {
    vector<vector<int>>  testcase1 = { {1, 1, 0},{1, 1, 0},{0, 0, 1} };
    cout << solution(3 ,testcase1);
    return 0;
}