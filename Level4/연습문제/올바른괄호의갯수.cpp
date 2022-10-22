#include <string>
#include <vector>
using namespace std;
//  Ʈ�� ������ ����
//  �������� �̵��� ( ���
//  ���������� �̵��� ) ���

enum class FuncType
{
    USELEFT,    //�������� �̵�
    USERIGHT    // ���������� �̵�
};
// ����
int Func(int, int, FuncType);
int solution(int);

int solution(int n) {
    int answer = 0;
    // �ʱ� (,) �� ������ �ֱ� ������ N ���� �ֽ��ϴ�. ó���� ���� ��ȣ�� ���� ����մϴ�.
    answer = Func(n, n, FuncType::USELEFT);
    return answer;
}
int Func(int remainLeftBracket, int remainRightBracket, FuncType type)
{
    int remainLeft = remainLeftBracket;
    int remainRight = remainRightBracket;
    if (type == FuncType::USELEFT)
    {
        remainLeft -= 1;                // ���� ��ȣ �Ѱ� ���
        if (remainLeft == 0)            // ���� ������� �� �� ��������� 1���� ����� ���� �ϼ�.
        {
            return 1;
        }
    }
    else if (type == FuncType::USERIGHT)
    {
        remainRight -= 1;               // ������ ��ȣ �Ѱ� ���
        if (remainLeft > remainRight)   // ���� ������� �� ���� ��ȣ�� �� ������ �ǹٸ��� ���� ��ȣ�� �˴ϴ�.
        {
            return 0;
        }
    }
    //����, ������ ��带 �� ����
    int result1 = Func(remainLeft, remainRight, FuncType::USELEFT);
    int result2 = Func(remainLeft, remainRight, FuncType::USERIGHT);
    return result1 + result2; // ��� ���
}
int main(void)
{
    printf("%d\n", solution(2));
    printf("%d\n", solution(3));
    return 0;
}