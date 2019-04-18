#include <iostream>

#include "fraction.hpp"

#define UNUSED(x) (void)(x)

Fraction::Fraction()
    : m_numerator(0)
    , m_denominator(1)
    , m_isUndefinedValue(false)
{
}

Fraction::Fraction(int number)
    : m_numerator(number)
    , m_denominator(1)
    , m_isUndefinedValue(false)
{
}

Fraction::Fraction(int numerator, int denominator)
    : m_numerator(numerator)
{
    m_denominator = 0 != denominator ? denominator : -1;
    m_isUndefinedValue = 0 == denominator ? true : false;
}

Fraction::~Fraction()
{
}

Fraction& Fraction::AddToSelf(const Fraction &other)
{
    CalcFraction(other, POSITIVE);

    return *this;
}

Fraction& Fraction::AddToSelf(int number)
{
    m_numerator += m_denominator * number;

    return *this;
}

Fraction& Fraction::SubstractFromSelf(int number)
{
    m_numerator -= m_denominator * number;

    return *this;
}

Fraction &Fraction::SubstractFromSelf(const Fraction& other)
{
    CalcFraction(other, NEGATIVE);

    return *this;
}

bool Fraction::IsEqual(const Fraction& other) const
{
    double numerator1 = GetNumerator();
    double denominator1 = GetDenominator();
    double numerator2 = other.GetNumerator();
    double denominator2 = other.GetDenominator();
    double result = (numerator1 / denominator1) - (numerator2 / denominator2);
    
    return (result < 0.0000001) && (result > -0.0000001); 
}

bool Fraction::IsEqual(int number) const
{
    Fraction fractionToBeCompared = Fraction(number);

    return IsEqual(fractionToBeCompared);
}

void Fraction::Print()
{
    if (m_isUndefinedValue)
    {
        std::cout << "undefined value\n" << std::endl;
    }
    else if (0 == m_numerator)
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << GetNumerator() << "/" << GetDenominator() << std::endl;
    }
}

Fraction &Fraction::MultiplyBy(const Fraction& other)
{
    if (IsNotValid(other))
    {
        SetIsUndefinedValue(true);

        return *this; 
    }

    SetNumerator(m_numerator * other.GetNumerator());
    SetDenominator(m_denominator * other.GetDenominator()); 

    return *this;
}

Fraction& Fraction::Inc()
{
    AddToSelf(1);

    return *this;
}

Fraction& Fraction::Dec()
{
    SubstractFromSelf(1); 

    return *this;
}

int Fraction::GetNumerator() const
{
    return m_numerator;
}

int Fraction::GetDenominator() const
{
    return m_denominator;
}

bool Fraction::GetIsUndefinedValue() const
{
    return m_isUndefinedValue;
}

Fraction& Fraction::SetNumerator(int numerator)
{
    m_numerator = numerator;

    return *this;
}

Fraction& Fraction::SetDenominator(unsigned int denominator)
{
    m_denominator = denominator;

    return *this;
}

Fraction& Fraction::SetIsUndefinedValue(bool isUndefinedValue)
{
    m_isUndefinedValue = isUndefinedValue;

    return *this;
}

void SetValidFraction(Fraction& frac, Fraction other)
{
    frac.SetIsUndefinedValue(false);

    if ((frac.GetIsUndefinedValue()) || (other.GetIsUndefinedValue()))
    {
        frac.SetIsUndefinedValue(true); 
    }
}

void Fraction::CalcFraction(const Fraction& other, fractionSign sign)
{
    if (IsNotValid(other))
    {
        SetIsUndefinedValue(true);
    }
    else
    { 
        SetNumerator((GetNumerator() * other.GetDenominator()) + sign * 
                    (GetDenominator() * other.GetNumerator()));       
        SetDenominator(GetDenominator() * other.GetDenominator());
    }
}

bool Fraction::IsNotValid(const Fraction &other) const
{
    return GetIsUndefinedValue() || other.GetIsUndefinedValue();
}

Fraction Fraction::operator+(const Fraction& other)
{
    Fraction returnFrac = other;
    returnFrac.AddToSelf(other);

    return returnFrac;
}

Fraction Fraction::operator-(const Fraction& other)
{
    Fraction returnFrac = *this;
    returnFrac.SubstractFromSelf(other);

    return returnFrac;
}

Fraction Fraction::operator*(const Fraction& other)
{
    Fraction returnFrac = other;
    returnFrac.MultiplyBy(other);

    return returnFrac;
}

Fraction Fraction::operator+(int number)
{
    return number + *this;
}

Fraction Fraction::operator-(int number)
{
    return number - *this;
}

Fraction Fraction::operator*(int number)
{
    return number * *this;
}

Fraction& Fraction::operator+()
{
    return *this;
}

Fraction& Fraction::operator-()
{
    SetNumerator(GetNumerator() * -1);

    return *this;
}

Fraction Fraction::operator--(int num)
{
    UNUSED(num);

    Fraction returnFrac = *this;
    Dec();

    return returnFrac;
}

Fraction& Fraction::operator--()
{
    return Dec();
}

Fraction& Fraction::operator++()
{
    return Inc();
}

Fraction Fraction::operator++(int num)
{ 
    UNUSED(num);
    
    Fraction returnFrac = *this;
    Inc();

    return returnFrac;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
    return MultiplyBy(other);
}

bool Fraction::operator==(const Fraction& other) const
{
    return IsEqual(other);
}

bool Fraction::operator==(int num) const
{
    return IsEqual(num);
}

Fraction& Fraction::operator=(const Fraction& other)
{
   SetNumerator(other.GetNumerator());
   SetDenominator(other.GetDenominator());
   SetIsUndefinedValue(other.GetIsUndefinedValue());

   return *this; 
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    return AddToSelf(other);
}

Fraction& Fraction::operator+=(int number)
{
    return AddToSelf(number);
}

Fraction& Fraction::operator-=(const Fraction& other)
{
    return SubstractFromSelf(other);
}
Fraction& Fraction::operator-=(int num)
{
    return SubstractFromSelf(num);
}

Fraction operator+(int number, const Fraction& frac)
{
    Fraction returnFrac = frac;
    returnFrac.AddToSelf(number);

    return returnFrac;
}

Fraction operator-(int number, const Fraction& frac)
{
    Fraction returnFrac = frac;
    returnFrac.SubstractFromSelf(number);

    return returnFrac;
}

Fraction operator*(int number, const Fraction& frac)
{
    Fraction returnFrac = frac;
    returnFrac.SetNumerator(returnFrac.GetNumerator() * number);

    return returnFrac;
}