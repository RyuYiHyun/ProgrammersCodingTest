#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum(vector<int>& numbers)
{
    int sum = 0;
    for (auto var : numbers)
    {
        sum += var;
    }
    return sum;
}
int counter = 0;

void func(vector<int> numbers, int target, int index)
{
    index++;
    if (index == numbers.size())
    {//마지막 노드
        if (sum(numbers) == target)
        {//계산이 타겟숫자와 같으면 케이스 증가
            ++counter;
        }
        return;// 탈출
    }
    //부호 그대로
    func(numbers, target, index);
    //부호 바꾸기
    numbers[index] = numbers[index] * -1;
    func(numbers, target, index);
}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    func(numbers, target, -1);
    answer = counter;
    return answer;
}



int main() 
{
    cout << solution();
    return 0;
}