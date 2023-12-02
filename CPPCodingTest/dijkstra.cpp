#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 10000000000
#define NODECOUNT 3
vector<pair<int, int>> nodes[NODECOUNT];
int dist[NODECOUNT];


void dujkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start)); // 비용, 위치(노드)
    dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) 
        {
            continue;
        }
        for (int i = 0; i < nodes[here].size(); i++)
        {
            int via_cost = cost + nodes[here][i].first;
            if (via_cost < dist[nodes[here][i].second])
            {
                dist[nodes[here][i].second] = via_cost;
                pq.push(make_pair(-via_cost, nodes[here][i].second));
            }
        }
    }
}


int main() 
{
    for (int i = 0; i < NODECOUNT; i++)
    {
        dist[i] = INF;
    }

    nodes[0].push_back(make_pair(5,1));
    nodes[0].push_back(make_pair(1,2));
    nodes[2].push_back(make_pair(3,1));

    dujkstra(0);

    for (int i = 0; i < NODECOUNT; i++)
    {
        cout << dist[i] << endl;
    }
    return 0;
}