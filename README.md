Some OOP Notes

Learned from Houjie.

## complex 小结  (具体代码见complex.h)
* 防卫式声明
* 类名
* 数据放在 private 中
* 函数放在 public 中
* 构造函数（默认值、初值列）
* 成员函数
    * 参数值尽量以reference来传，要不要加const，看情况
    * 返回值也尽量以reference来传
* 友元
    * 相同class的各个object互为friend
* inline 内联
    * 函数若在 class body 内定义完成，便自动成为inline 候选人
* 函数符重载

## string 小结  (具体代码见string.h)
* 防卫式声明
* 类名
* 数据放在 private 中
* 函数放在 public 中
* 构造函数、拷贝构造函数、拷贝赋值函数、析构函数(array delete)
    * class with pointer members, 必须有 copy ctor 和 copy operator=
    * 浅拷贝会 内存泄漏(memory leak)
    * 拷贝赋值函数，首先要检查 自我赋值

* 函数符重载

