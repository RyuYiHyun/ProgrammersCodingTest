#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class TestClass
{
    int value;
public:
    TestClass()
    {// default ������, �ٸ� �����ڸ� ���� �� ����
        cout << "default ������" << endl;
    }
    TestClass(int n)
    {// ������
        value = n;
        cout << "������" << endl;
    }
};

class TestClass2
{
    int& refvalue;
public:
    //TestClass2(int n)
    //{
    //    refvalue = n;// ����
    //    cout << "������" << endl;
    //}
    TestClass2(int& n) : refvalue(n)
    {// �ʱ�ȭ ����Ʈ ������ (���۷��� ������ �ʱ�ȭ, const �ʱ�ȭ�ÿ� ���)
        cout << "���۷��� ������" << endl;
    }
};

class TestClass3
{
    int value;
public:
    TestClass3(int n)
    {// ���� ������
        value = n;
        cout << "������" << endl;
    }

    // ����Ʈ ���� �������� ��� ���� ���縦 �Ͽ� ������ ���� �Ȱ��� �����Ե�
    // 
    // ���� �����Ҵ��� �޾� �ʱ�ȭ�Ǵ� ������ ������ ��������� ���� �����ڷ� 
    // ���� ���簡 �ǵ��� ������Ѵ�.
    TestClass3(const TestClass3& obj)
    {// ���� ������
        value = obj.value;
        cout << "���� ������" << endl;
    }
};

int main() 
{
    /*
    TestClass t1;// defaalut ������ ȣ��
    TestClass t2(2);// ������ ȣ��
    TestClass t3 = TestClass(3);// ���� ������ ȣ��
    //*/

    /*
    int a =4;
    TestClass2 t4(a);
    //*/

    ///*
    TestClass3 t5(5);
    TestClass3 t6 = t5;//���� ������
    TestClass3 t7(t6);//���� ������
    //*/

    /*
    //*/

    /*
    //*/

    /*
    //*/
    return 0;
}