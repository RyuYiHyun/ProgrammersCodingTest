#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Point
{
    int x; 
    int y;
    int step;
    Point(int _x, int _y, int _step)
    {
        x = _x;
        y = _y;
        step = _step;
    }
};

bool CanMove(vector<vector<int>>& maps, Point _point)
{
    int maxx = maps[0].size();
    int maxy = maps.size();
    int x = _point.x;
    int y = _point.y;
    if (x >= maxx || x < 0 || y >= maxy || y < 0)
    {
        return false;
    }
    if (maps[y][x] == -1 || maps[y][x] == 0)
    {
        return false;
    }
    return true;
}

int FindPath(vector<vector<int>>& maps)
{
    int maxx = maps[0].size();
    int maxy = maps.size();

    queue<Point> Queue;
    Queue.push(Point(0, 0 , 1));
    maps[0][0] = -1;

    while (!Queue.empty())
    {
        //큐 꺼내기
        Point point = Queue.front();
        Queue.pop();
        if (point.x == maxx - 1 && point.y == maxy - 1)
        {
            return point.step;
        }
        //maps[Y][X] 이다
        Point downPoint(point.x, point.y + 1 , point.step+1);
        if (CanMove(maps, downPoint))
        {
            maps[downPoint.y][downPoint.x] = -1;
            Queue.push(downPoint);
        }
        Point upPoint(point.x, point.y - 1 , point.step+1);
        if (CanMove(maps, upPoint))
        {
            maps[upPoint.y][upPoint.x] = -1;
            Queue.push(upPoint);
        }
        Point rightPoint(point.x + 1, point.y , point.step+1);
        if (CanMove(maps, rightPoint))
        {
            maps[rightPoint.y][rightPoint.x] = -1;
            Queue.push(rightPoint);
        }
        Point leftPoint(point.x - 1, point.y , point.step+1);
        if (CanMove(maps, leftPoint))
        {
            maps[leftPoint.y][leftPoint.x] = -1;
            Queue.push(leftPoint);
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = FindPath(maps);
    return answer;
}



int main() 
{
    vector<vector<int> > maps = { {1, 0, 1, 1, 1} ,{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1} };
    //vector<vector<int> > maps = { {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 0},{0, 0, 0, 0, 1} };
    cout << solution(maps);
    return 0;
}