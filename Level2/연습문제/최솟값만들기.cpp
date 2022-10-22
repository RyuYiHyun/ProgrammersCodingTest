//https://school.programmers.co.kr/learn/courses/30/lessons/12941
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    unsigned int size = A.size();
    for (int i = 0; i < size; ++i)
    {
        answer += A[i] * B[size - 1 - i];
    }
    return answer;
}