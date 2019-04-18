#ifndef ILRD_RD61_FRACTION_HPP
#define ILRD_RD61_FRACTION_HPP

class Fraction
{
public:
    enum fractionSign {NEGATIVE = -1, POSITIVE = 1};

    explicit Fraction();
    explicit Fraction(int number);
    explicit Fraction(int numerator, int denominator);
    ~Fraction();
    
    bool operator==(const Fraction& other) const;
    bool operator==(int num) const;
    
    Fraction operator*(const Fraction& other);
    Fraction operator*(int number);
    Fraction operator+(const Fraction& other);
    Fraction operator+(int number);
    Fraction operator++(int num);
    Fraction operator-(const Fraction& other);
    Fraction operator-(int number);
    Fraction operator--(int num);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator+();
    Fraction& operator++();
    Fraction& operator+=(const Fraction& other);
    Fraction& operator+=(int num);
    Fraction& operator-();
    Fraction& operator--();
    Fraction& operator-=(const Fraction& other);
    Fraction& operator-=(int num);
    Fraction& operator=(const Fraction& other);

    Fraction& AddToSelf(const Fraction& other);
    Fraction& AddToSelf(int number);
    Fraction& Dec();
    Fraction& Inc();
    Fraction& MultiplyBy(const Fraction& other);
    Fraction& SetDenominator(unsigned int denominator);
    Fraction& SetIsUndefinedValue(bool isUndefinedValue);
    Fraction& SetNumerator(int numerator);
    Fraction& SubstractFromSelf(const Fraction& other);
    Fraction& SubstractFromSelf(int number);
    
    bool GetIsUndefinedValue() const;
    bool IsEqual(const Fraction& other) const;
    bool IsEqual(const int otherNum) const;
    bool IsNotValid(const Fraction &other) const;
    
    int GetDenominator() const;
    int GetNumerator() const;
    void CalcFraction(const Fraction& frac, fractionSign sign);
    void Print();

private:
    int m_numerator; 
    int m_denominator;
    bool m_isUndefinedValue;
};

Fraction operator*(int number, const Fraction& frac);
Fraction operator-(int number, const Fraction& frac);
Fraction operator+(int number, const Fraction& frac);

#endif