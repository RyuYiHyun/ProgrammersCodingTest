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
        {//computerNumber�� ��ǻ�Ϳ� i ��ǻ�Ͱ� ���� �Ǿ��ְ� ���� ���¸� Ȯ���� ���ΰ� ���� ���
            check[i] = true;// ��ȸ �Ϸ�
            DFS(i);//i�� ���� ���� ��ȸ
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