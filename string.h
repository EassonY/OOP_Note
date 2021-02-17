#ifndef __OOP_STRING__
#define __OOP_STRING__

class String
{

public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator = (const String& str);
    ~String();
    char* get_c_str() const {return m_data;}

private:
    char* m_data;

};

#include <cstring>

inline
String::String(const char* cstr)
{
    if (cstr) {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}



#endif