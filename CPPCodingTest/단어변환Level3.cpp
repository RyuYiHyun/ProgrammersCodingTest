#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



int NodeCheck(string from, string to)
{
    //1이면 연결됨 2이상이면 연결안됨
    int count = 0;
    for (int i = 0; i < from.size(); i++)
    {
        if (from[i] == to[i])
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    if (count == 1)
    {
        return 1;
    }
    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    vector<vector<int>> nodes;
    vector<int> visits;
    bool goalCheck = false;
    //노드 정보 제작
    for (int i = 0; i < words.size(); i++)
    {
        if (target == words[i])
        {//목표 도달 가능여부
            goalCheck = true;
        }
        visits.push_back(0);
        nodes.push_back(vector<int>());
        for (int j = 0; j < words.size(); j++)
        {
            nodes[i].push_back(NodeCheck(words[i], words[j]));
        }
    }
    
    if (!goalCheck)
    {
        return 0;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (NodeCheck(begin, words[i]) != 1)
        {// 시작 가능 여부
            continue;
        }

        for (int v = 0; v < visits.size(); v++)
        {
            visits[v] = 0;
        }

        queue<pair<int,int>> bfsqueue;// 위치,깊이
        bfsqueue.push(make_pair(i,1));
        visits[i] = 1;

        while (!bfsqueue.empty())
        {
            int index = bfsqueue.front().first;
            int count = bfsqueue.front().second;
            bfsqueue.pop();
            if (words[index] == target)
            {//타겟을 찾았으면 탈출
                if (answer == 0)
                {
                    answer = count;
                }
                else
                {
                    if (answer > count)
                    {// 더 작은 값을 넣기
                        answer = count;
                    }
                }
                break;
            }
            //타겟을 못찾았으면 찾기
            for (int j = 0; j < nodes[index].size(); j++)
            {
                if (nodes[index][j] == 0 || visits[j] == 1)
                {
                    continue;
                }
                else
                {
                    visits[j] = 1;
                    bfsqueue.push(make_pair(j, ++count));
                }
            }
        }
        while (!bfsqueue.empty())
        {
            bfsqueue.pop();
        }
    }
   

    return answer;
}



int main() {
    vector<string>  testcase1 = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution("hit","cog", testcase1);
    return 0;
}