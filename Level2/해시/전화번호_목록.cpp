//https://school.programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_map<string, bool> check;
    bool answer = true;
    for (auto phone_num : phone_book)
    {
        check[phone_num] = false;
    }

    for (auto phone_num : phone_book)
    {
        string temp;
        for (auto num : phone_num)
        {
            temp.push_back(num);
            if (check.count(temp) >= 1 && temp != phone_num)
            {
                return false;
            }
        }
    }
    return true;
}