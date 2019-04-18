#include <cstring> /* strlen */
#include "string.hpp"

String::String(const char *str)
{
    SetString(str);
}

String::String(const String& other_)
{
    SetString(other_.m_str);
}

String::~String()
{
    delete[] m_str;
}

String& String::operator=(const String& other_)
{
    if (this == &other_) 
    {
        return *this;
    }
    
    delete[] m_str;
    SetString(other_.c_str());
    
    return *this;
}

char& String::operator[](size_t idx)
{
    return m_str[idx];
}

const char& String::operator[](size_t idx) const
{
    return m_str[idx];
}

bool String::operator==(const String& other_) const
{
    return strcmp(c_str(), other_.c_str()) == 0;
}

bool String::operator!=(const String& other_) const
{
    return !(*this == other_);
}

String& String::operator+=(const String& other_)
{
    char *tempString = new char[Length() + other_.Length() + 1];
    
    strcpy(tempString, m_str);
    strcat(tempString + strlen(tempString), other_.c_str());

    delete[] m_str;
    SetString(tempString);
    delete[] tempString;

    return *this;
}

const char * String::c_str() const 
{
    return m_str;
}

size_t String::Length() const
{
    return strlen(c_str());
}

String& String::SetString(const char *string)
{
    m_str = new char[strlen(string) + 1];
    strcpy(m_str, string);

    return *this;
}

String operator+(const String& str1, const String& str2)
{
    return String(str1) += str2;
}

std::ostream &operator<<(std::ostream &os_, const String &str_)
{
    return os_ << str_.c_str();
}