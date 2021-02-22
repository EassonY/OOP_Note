#ifndef __OOP_COMPLEX__
#define __OOP_COMPLEX__

//防卫式声明

class complex;
complex&
    __doapl (complex* ths, const complex& r);  // function
complex&
    __doami (complex* ths, const complex& r);
complex&
    __doaml (complex* ths, const complex& r);


class complex
{

public:

	// 构造函数，创建对象
    complex (double r = 0, double i = 0)
        : re (r), im (i)
    {}
	// 带上默认实参double r = 0, double i = 0 和初值列


	// 操作符重载，参数和返回值 pass by reference
    complex& operator += (const complex&);
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);

	// functions, 常量成员函数，加上const
    double real() const { return re; }
    double imag() const { return im; }

private:
    double re, im; 
	// data 放在private里面


	// 友元，打开封装大门，达到直接拿到数据的效果 (快)，函数后续实现
    friend complex& __doapl (complex*, const complex&);
    friend complex& __doami (complex*, const complex&);
    friend complex& __doaml (complex*, const complex&);

};



// __doapl 函数实现
inline complex&
__doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

//重载 +=
inline complex&
complex::operator += (const complex& r)
{
	return __doapl(this, r);
}


// __doami 函数实现
inline complex&
__doami(complex* ths, const complex& r)
{
	ths->re -= r.re;
	ths->im -= r.im;
	return *ths;
}

//重载 -=
inline complex&
complex::operator -= (const complex& r)
{
	return __doami(this, r);
}


// __doaml 函数实现
inline complex&
__doaml(complex* ths, const complex& r)
{
	double f = ths->re * r.re - ths->im * r.im;
	ths->im = ths->re * r.im + ths->im * r.re;
	ths->re = f;
	return *ths;
}

//重载 *=
inline complex&
complex::operator *= (const complex& r)
{
	return __doaml(this, r);
}


inline double
imag(const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}



// 操作符重载： 加减乘除

// 实现 complex + complex
inline complex
operator + (const complex& x, const complex& y)
{
	return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator + (const complex& x, double y)
{
	return complex(real(x) + y, imag(x));
}

inline complex
operator + (double x, complex& y)
{
	return complex(x + real(y), imag(y));
}


inline complex
operator - (const complex& x, const complex& y)
{
	return complex(real(x) - real(y), imag(x) - imag(y));
}

inline complex
operator - (const complex& x, double y )
{
	return complex(real(x) - y, imag(x));
}

inline complex
operator - (double x, const complex& y)
{
	return complex(x - real(y), imag(y));
}


inline complex
operator * (const complex& x, const complex& y)
{
	return complex(real(x) * real(y) - imag(x) * imag(y),
	               real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator * (const complex& x, double y )
{
	return complex(real(x) * y, imag(x) * y);
}

inline complex
operator * (double x, const complex& y)
{
	return complex(x * real(y), x * imag(y));
}

inline complex
operator / (const complex& x, double y)
{
	return complex(real(x) / y, imag(x) / y);
}


// 重载正负号
inline complex
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x)
{
	return complex(-real(x), -imag(x));
}

// 重载 == 

inline bool
operator == (const complex& x, const complex& y)
{
	return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator == (const complex& x, double y)
{
	return real(x) == y && imag(x) == 0;
}

inline bool
operator == (double x, const complex& y)
{
	return x == real(y) && imag(y) == 0;
}

// 重载 != 

inline bool
operator != (const complex& x, const complex& y)
{
	return real(x) != real(y) || imag(x) == imag(y);
}

inline bool
operator != (const complex& x, double y)
{
	return real(x) != y || imag(x) != 0;
}

inline bool
operator != (double x, const complex& y)
{
	return x != real(y) || imag(y) == 0;
}






#endif
