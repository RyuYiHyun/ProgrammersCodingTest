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
    {//������ ���
        if (sum(numbers) == target)
        {//����� Ÿ�ټ��ڿ� ������ ���̽� ����
            ++counter;
        }
        return;// Ż��
    }
    //��ȣ �״��
    func(numbers, target, index);
    //��ȣ �ٲٱ�
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