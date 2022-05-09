#include <string>
#include <vector>
using namespace std;
//  트리 구조로 생각
//  왼쪽으로 이동시 ( 사용
//  오른쪽으로 이동시 ) 사용

enum class FuncType
{
    USELEFT,    //왼쪽으로 이동
    USERIGHT    // 오른쪽으로 이동
};
// 선언
int Func(int, int, FuncType);
int solution(int);

int solution(int n) {
    int answer = 0;
    // 초기 (,) 는 쌍으로 있기 때문에 N 개씩 있습니다. 처음은 왼쪽 괄호를 먼저 사용합니다.
    answer = Func(n, n, FuncType::USELEFT);
    return answer;
}
int Func(int remainLeftBracket, int remainRightBracket, FuncType type)
{
    int remainLeft = remainLeftBracket;
    int remainRight = remainRightBracket;
    if (type == FuncType::USELEFT)
    {
        remainLeft -= 1;                // 왼쪽 괄호 한개 사용
        if (remainLeft == 0)            // 만약 사용했을 때 다 사용했으면 1가지 경우의 수가 완성.
        {
            return 1;
        }
    }
    else if (type == FuncType::USERIGHT)
    {
        remainRight -= 1;               // 오른쪽 괄호 한개 사용
        if (remainLeft > remainRight)   // 만약 사용했을 때 왼쪽 괄호가 더 많으면 옳바르지 않은 괄호가 됩니다.
        {
            return 0;
        }
    }
    //왼쪽, 오른쪽 노드를 다 실행
    int result1 = Func(remainLeft, remainRight, FuncType::USELEFT);
    int result2 = Func(remainLeft, remainRight, FuncType::USERIGHT);
    return result1 + result2; // 결과 출력
}
int main(void)
{
    printf("%d\n", solution(2));
    printf("%d\n", solution(3));
    return 0;
}