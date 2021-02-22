#include "string.h"
#include <iostream>

using namespace std;

int main()
{
    // 测试构造函数

    String s1("hello");
    String s2("world!");

    // 测试拷贝构造函数
    String s3(s2);

    // 操作符重载 <<
    cout << s3 << endl;

    // 测试拷贝赋值函数
    s3 = s1;
    cout << s3 << endl;
    cout << s2 << endl;
    cout << s1 << endl;
}