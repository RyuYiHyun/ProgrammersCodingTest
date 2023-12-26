#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//unique 함수 -> 연속된 값 제거, 중복 제거 후 끝 iterator값 반환
//vector<int> solution(vector<int> arr)
//{
//    arr.erase(unique(arr.begin(), arr.end()), arr.end());
//    vector<int> answer = arr;
//    return answer;
//}
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int index = -1;
    for (auto num : arr)
    {
        if (index == -1)
        {
            answer.push_back(num);
            ++index;
        }
        else if (answer[index] != num)
        {
            answer.push_back(num);
            ++index;
        }
    }

    return answer;
}



int main() 
{
    solution(vector<int>{ 1, 1, 3, 3, 0, 1});
    return 0;
}