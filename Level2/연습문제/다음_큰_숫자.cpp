//https://school.programmers.co.kr/learn/courses/30/lessons/12911
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bitcounter(unsigned int N)
{
    int counter = 0;
    for (int i = 31; i >= 0; --i) // int 의 최대 비트에서 수량 세기
    {
        if (N & (1 << i))
        {
            ++counter;// 1인 비트 수 세기
        }
    }
    return counter;
}

// 1111 1111 1111 1111 1111 1111 1111 1111
int solution(int n)
{
    int answer = 0;
    unsigned int N = n;
    int count = bitcounter(N);
    unsigned int i = N;
    while (true)
    {
        ++i;
        if (count == bitcounter(i))
        {
            answer = i;
            break;
        }
        if (i == 0xFFFFFFFF)
        {
            break;
        }
    }
    return answer;
}