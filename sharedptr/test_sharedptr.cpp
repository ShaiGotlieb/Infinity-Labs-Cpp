#include <cstdlib>
#include <iostream>

#include "test.hpp"
#include "sharedptr.hpp"

using namespace ilrd;

TestResult TestSharedPtrInt();
TestResult TestCCtor();
TestResult TestAssignmentOperator();
TestResult TestConditionOperator();
TestResult TestArray();
TestResult TestCCtorOtherSharedPtr();
TestResult TestAssignmentOperatorOtherSharedPtr();

int main()
{
	RUN_TEST(TestSharedPtrInt);
	RUN_TEST(TestCCtor);
	RUN_TEST(TestAssignmentOperator);
	RUN_TEST(TestConditionOperator);
	RUN_TEST(TestArray);
	RUN_TEST(TestCCtorOtherSharedPtr);
	RUN_TEST(TestAssignmentOperatorOtherSharedPtr);

	return (EXIT_SUCCESS);
}

TestResult TestSharedPtrInt()
{
	int *intPtr1 = new int(1);
	SharedPtr<int> newPtr1(intPtr1);
	SharedPtr<int> newPtr2;

	newPtr2 = newPtr2;
	newPtr2 = newPtr1;

	REQUIRE(1 == *intPtr1);
	REQUIRE(1 == *newPtr2);	

	return (TEST_PASS);
}

TestResult TestCCtor()
{
	int *intPtr = new int(0);
	size_t ptrCounter = 0;

	SharedPtr<int> sharedPtr1(intPtr);
	ptrCounter++;
	REQUIRE(ptrCounter == sharedPtr1.getCounter()->getCount());	

	SharedPtr<int> sharedPtr2(sharedPtr1);
	ptrCounter++;
	REQUIRE(ptrCounter == sharedPtr1.getCounter()->getCount());	
	REQUIRE(ptrCounter == sharedPtr2.getCounter()->getCount());	

	return (TEST_PASS);
}

TestResult TestAssignmentOperator()
{
	int *intPtr1 = new int(0);
	int *intPtr2 = new int(1);
	size_t ptr1Counter = 0;
	size_t ptr2Counter = 0;
	
	SharedPtr<int> sharedPtr1(intPtr1);
	SharedPtr<int> sharedPtr10[4];
	ptr1Counter++;
	SharedPtr<int> sharedPtr2(sharedPtr1);
	ptr1Counter++;
	REQUIRE(ptr1Counter == sharedPtr1.getCounter()->getCount());	
	REQUIRE(ptr1Counter == sharedPtr2.getCounter()->getCount());	

	SharedPtr<int> sharedPtr3(intPtr2);
	ptr2Counter++;
	SharedPtr<int> sharedPtr4(sharedPtr3);
	ptr2Counter++;
	REQUIRE(ptr2Counter == sharedPtr3.getCounter()->getCount());
	REQUIRE(ptr2Counter == sharedPtr4.getCounter()->getCount());

	sharedPtr3 = sharedPtr1;
	ptr2Counter--;
	ptr1Counter++;
	REQUIRE(ptr1Counter == sharedPtr1.getCounter()->getCount());
	REQUIRE(ptr2Counter == sharedPtr4.getCounter()->getCount());

	sharedPtr3 = sharedPtr1;
	REQUIRE(ptr1Counter == sharedPtr1.getCounter()->getCount());
	REQUIRE(ptr2Counter == sharedPtr4.getCounter()->getCount());

	return (TEST_PASS);
}

TestResult TestConditionOperator()
{
	int *intPtr1 = new int(0);
	int *intPtr2 = new int(1);
	
	SharedPtr<int> sharedPtr1(intPtr1);
	SharedPtr<int> sharedPtr2(sharedPtr1);
	SharedPtr<int> sharedPtr3(intPtr2);
	
	REQUIRE(sharedPtr1 != sharedPtr3);
	REQUIRE(sharedPtr2 != sharedPtr3);

	sharedPtr3 = sharedPtr1;
	REQUIRE(sharedPtr1 == sharedPtr3);
	REQUIRE(sharedPtr2 == sharedPtr3);
	
	REQUIRE(sharedPtr1 == true);
	REQUIRE(!sharedPtr1 == false);
	
	return (TEST_PASS);
}

TestResult TestArray()
{
	SharedPtr<int> *intArr = new SharedPtr<int>[1000];
	SharedPtr<double> *doubleArr = new SharedPtr<double>[1000];
	SharedPtr<float> *floatArr = new SharedPtr<float>[1000];

	delete[] intArr;
	delete[] doubleArr;
	delete[] floatArr;

	return (TEST_PASS);
}

TestResult TestCCtorOtherSharedPtr()
{
	SharedPtr<int> sharedPtr1(new int(0));
	SharedPtr<const int> sharedPtr2(sharedPtr1);
	SharedPtr<const int> sharedPtr3(sharedPtr2);

	REQUIRE(*sharedPtr1 == *sharedPtr2);
	REQUIRE(*sharedPtr3 == *sharedPtr2);

	return (TEST_PASS);
}

TestResult TestAssignmentOperatorOtherSharedPtr()
{
	SharedPtr<float> sharedPtr1(new float(1.0));
	SharedPtr<const float> sharedPtr2(sharedPtr1);
	SharedPtr<const float> sharedPtr3(new float(3.0));

	sharedPtr3 = sharedPtr2;
	REQUIRE(*sharedPtr3 == *sharedPtr2);

	return (TEST_PASS);
}