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
    {// default 생성자, 다른 생성자를 만들 시 없음
        cout << "default 생성자" << endl;
    }
    TestClass(int n)
    {// 생성자
        value = n;
        cout << "생성자" << endl;
    }
};

class TestClass2
{
    int& refvalue;
public:
    //TestClass2(int n)
    //{
    //    refvalue = n;// 에러
    //    cout << "생성자" << endl;
    //}
    TestClass2(int& n) : refvalue(n)
    {// 초기화 리스트 생성자 (레퍼런스 변수를 초기화, const 초기화시에 사용)
        cout << "레퍼런스 생성자" << endl;
    }
};

class TestClass3
{
    int value;
public:
    TestClass3(int n)
    {// 복사 생성자
        value = n;
        cout << "생성자" << endl;
    }

    // 디폴트 복사 생성자의 경우 얕은 복사를 하여 참조와 값을 똑같이 가지게됨
    // 
    // 따라서 동적할당을 받아 초기화되는 변수가 있으면 사용자정의 복사 생성자로 
    // 깊은 복사가 되도록 해줘야한다.
    TestClass3(const TestClass3& obj)
    {// 복사 생성자
        value = obj.value;
        cout << "복사 생성자" << endl;
    }
};

int main() 
{
    /*
    TestClass t1;// defaalut 생성자 호출
    TestClass t2(2);// 생성자 호출
    TestClass t3 = TestClass(3);// 복사 생성자 호출
    //*/

    /*
    int a =4;
    TestClass2 t4(a);
    //*/

    ///*
    TestClass3 t5(5);
    TestClass3 t6 = t5;//복사 생성자
    TestClass3 t7(t6);//복사 생성자
    //*/

    /*
    //*/

    /*
    //*/

    /*
    //*/
    return 0;
}