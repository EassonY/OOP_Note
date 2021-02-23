#include <iostream>
#include "complex.h"

using namespace std;

ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

int main()
{
    complex c1(2, 1);
    complex c2(4, 0);

    // << 操作符重载测试

    cout << c1 << endl;
    cout << c2 << endl;

    // 加减乘除操作符重载测试

    cout << c1 + c2 << endl;
    cout << c1 - c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 /  2 << endl;
    cout << endl;


    // 正负号重载
    cout << + c1 << endl;
    cout << - c1 << endl;

    // ==   != 重载

    if (c1 == c2) cout << "c1 == c2" << endl;
    if (c1 != c2) cout << "c1 != c2" << endl;

    // polar 测试
    cout << polar(3, 4) << endl;

    // conj 测试
    cout << conj(c2) << endl;

    // norm 测试
    cout << norm(c1) << endl;

    return 0;
}