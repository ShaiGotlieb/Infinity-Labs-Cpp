#ifndef ILRD_RD61_STRING_HPP
#define ILRD_RD61_STRING_HPP

#include <cstddef>
#include <iostream>

class String
{
    friend std::ostream &operator<<(std::ostream &os_, const String &str_);

public:
    explicit String(const char *str = "");
    String(const String& other_);
    ~String();

    String &operator+=(const String &other_);
    String& operator=(const String& other_);
    bool operator!=(const String &other_) const;
    bool operator==(const String &other_) const;
    char &operator[](size_t idx);
    const char &operator[](size_t idx) const;

    const char *c_str() const;
    size_t Length() const;
    String& SetString(const char *string);

private:
    char *m_str;
};

String operator+(const String& str1, const String& str2);

#endif
