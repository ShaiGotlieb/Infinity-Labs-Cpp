#include <stdlib.h>
#include <string.h>

#include "fraction.hpp"
#include "test.hpp"

TestResult TestAddToSelf();
TestResult TestSubstractFromSelf();
TestResult TestMultiplyBy();
TestResult TestIsEqual();
TestResult TestInc();
TestResult TestDec();
TestResult TestAssignment();
TestResult TestOperators();

int main()
{
    RUN_TEST(TestAddToSelf);
    RUN_TEST(TestSubstractFromSelf);
    RUN_TEST(TestMultiplyBy);
    RUN_TEST(TestIsEqual);
    RUN_TEST(TestInc);
    RUN_TEST(TestDec);
    RUN_TEST(TestAssignment);
    RUN_TEST(TestOperators);

	return (EXIT_SUCCESS);
}

TestResult TestAddToSelf()
{
	Fraction *f1 = new Fraction();
    Fraction *f2 = new Fraction(1, 2);
    Fraction *f3 = new Fraction(2, 3);
    Fraction *f4 = new Fraction(1, 2);
    int num = 1;

    f1->AddToSelf(*f2);
    f2->AddToSelf(*f3);
    f4->AddToSelf(num);

    REQUIRE(f1->GetNumerator() == 1);
    REQUIRE(f1->GetDenominator() == 2);
    REQUIRE(f2->GetNumerator() == 7);
    REQUIRE(f2->GetDenominator() == 6);
    REQUIRE(f4->GetNumerator() == 3);
    REQUIRE(f4->GetDenominator() == 2);

    delete f1;
    delete f2;
    delete f3;
    delete f4;

	return (TEST_PASS);
}

TestResult TestSubstractFromSelf()
{
	Fraction *f1 = new Fraction();
    Fraction *f2 = new Fraction(1, 2);
    Fraction *f3 = new Fraction(2, 3);

    f1->SubstractFromSelf(*f2);
    f2->SubstractFromSelf(*f3);

    REQUIRE(f1->GetNumerator() == -1);
    REQUIRE(f1->GetDenominator() == 2);
    REQUIRE(f2->GetNumerator() == -1);
    REQUIRE(f2->GetDenominator() == 6);

    delete f1;
    delete f2;
    delete f3;

	return (TEST_PASS);
}

TestResult TestMultiplyBy()
{
	Fraction *f1 = new Fraction();
    Fraction *f2 = new Fraction(1, 2);
    Fraction *f3 = new Fraction(2, 3);

    f1->MultiplyBy(*f2);
    f2->MultiplyBy(*f3);

    REQUIRE(f1->GetNumerator() == 0);

    REQUIRE(f2->GetNumerator() == 2);
    REQUIRE(f2->GetDenominator() == 6);

    delete f1;
    delete f2;
    delete f3;

	return (TEST_PASS);
}

TestResult TestIsEqual()
{
    Fraction *f1 = new Fraction();
    Fraction *f2 = new Fraction(1, 2);
    Fraction *f3 = new Fraction(1, 2);
    Fraction *f4 = new Fraction(2, 1);
    int num = 2;

    REQUIRE(!f2->IsEqual(*f1));
    REQUIRE(f2->IsEqual(*f3));
    REQUIRE(f4->IsEqual(num));
    REQUIRE(!f1->IsEqual(num));

    delete f1;
    delete f2;
    delete f3;
    delete f4;

	return (TEST_PASS);
}

TestResult TestInc()
{
    Fraction *f1 = new Fraction(9,9);

    f1->Inc();

    REQUIRE(f1->GetNumerator() == 18);
    REQUIRE(f1->GetDenominator() == 9);

    delete f1;

    return (TEST_PASS);
}

TestResult TestDec()
{
    Fraction *f1 = new Fraction(9,9);

    f1->Dec();

    REQUIRE(f1->GetNumerator() == 0);
    REQUIRE(f1->GetDenominator() == 9);

    delete f1;

    return (TEST_PASS);
}

TestResult TestAssignment()
{
    Fraction *f1 = new Fraction();
    Fraction *f3 = new Fraction(1, 2);
    Fraction *f2 = new Fraction(*f3);
    
    REQUIRE(!f3->IsEqual(*f1));
    
    f1 = f3;
    
    REQUIRE(f3->IsEqual(*f1));
    REQUIRE(f3->IsEqual(*f2));

    delete f1;
    delete f2;
    delete f3;

    return (TEST_PASS);
}

TestResult TestOperators()
{
    Fraction *f1 = new Fraction(1, 2);
    Fraction *f2 = new Fraction(1, 4);
    Fraction *f3 = new Fraction(*f1);
    
    *f1 += 1;
    *f1 += *f2;
    *f1 -= 1;
    *f1 -= *f2;

    REQUIRE(*f1 == *f3);
    REQUIRE(!(*f1 == *f2));

    Fraction f4(1, 8);
    *f1 *= *f2;
    REQUIRE(*f1 == f4);

    Fraction f5(1, 4);
    *++f2;
    *--f2;
    *f2++;
    *f2--;

    REQUIRE(*f2 == f5);

    f2->SetDenominator(2);
    f2->SetNumerator(1);
    f3->SetDenominator(2);
    f3->SetNumerator(1);
    
    *f1 = *f2 + *f3;

    REQUIRE(*f1 == 1);

    f2->SetDenominator(2);
    f2->SetNumerator(1);
    f3->SetDenominator(4);
    f3->SetNumerator(1);

    *f1 = *f2 - *f3;

    REQUIRE(*f1 == *f3);

    return (TEST_PASS);
}