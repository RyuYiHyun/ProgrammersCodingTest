//https://school.programmers.co.kr/learn/courses/30/lessons/12945
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int solution(int n)
{
    int answer = 0;
    vector<int> f(n + 1);
    f[0] = 0;// n = 0 , answer = 0
    f[1] = 1;// n = 1 , answer = 1
    for (int i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 1234567;
    }
    return f[n];
}