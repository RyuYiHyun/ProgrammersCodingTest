//https://school.programmers.co.kr/learn/courses/30/lessons/12924
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    vector<int> vec;

    for (int i = 1; i <= n; ++i)
    {
        vec.push_back(i);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int sum = 0;
        for (int j = i; j >= 0; --j)
        {
            sum += vec[j];
            if (sum > n)
            {
                break;
            }
            else if (sum == n)
            {
                ++answer;
                break;
            }
        }
    }

    return answer;
}