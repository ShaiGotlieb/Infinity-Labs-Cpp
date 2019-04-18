#include <cstdlib>
#include <iostream> /* std::cout */

#include "test.hpp"
#include "stack.hpp"
#include "string.hpp"

TestResult TestPush();
TestResult TestTop();
TestResult TestPop();
TestResult TestCount();
TestResult TestIsEmpty();
TestResult TestPushString();
TestResult TestTopString();
TestResult TestPopString();
TestResult TestCountString();
TestResult TestIsEmptyString();

int main()
{
    RUN_TEST(TestPush);
    RUN_TEST(TestPushString);
    RUN_TEST(TestTop);
    RUN_TEST(TestTopString);
    RUN_TEST(TestPop);
    RUN_TEST(TestPopString);
    RUN_TEST(TestCount);
    RUN_TEST(TestCountString);
    RUN_TEST(TestIsEmpty);
    RUN_TEST(TestIsEmptyString);

    return 0;
}

TestResult TestPush()
{
    Stack<double> stack;

    REQUIRE(stack.IsEmpty());

    stack.Push(1);
    REQUIRE(1 == stack.Top());

    stack.Push(2);
    REQUIRE(2 == stack.Top());
    stack.Push(3);
    REQUIRE(3 == stack.Top());
    stack.Push(4);
    REQUIRE(4 == stack.Top());

    REQUIRE(4 == stack.Count());
    REQUIRE(!stack.IsEmpty());


    return TEST_PASS;
}

TestResult TestPushString()
{
    Stack<String> stack;
	String str1("Push Me!");
	String str2("No Push Me!");
	String str3("Ok Push Me!");
	String str4("Ufff Push Me!");

    REQUIRE(stack.IsEmpty());

    stack.Push(str1);
    REQUIRE(str1 == stack.Top());

    stack.Push(str2);
    REQUIRE(str2 == stack.Top());
    stack.Push(str3);
    REQUIRE(str3 == stack.Top());
    stack.Push(str4);
    REQUIRE(str4 == stack.Top());

    REQUIRE(4 == stack.Count());
    REQUIRE(!stack.IsEmpty());


    return TEST_PASS;
}

TestResult TestTop()
{
    Stack<double> stack;
    
    stack.Push(1);
    REQUIRE(1 == stack.Top());

    stack.Push(2);
    REQUIRE(2 == stack.Top());

    stack.Push(3);
    REQUIRE(3 == stack.Top());

    stack.Push(4);
    REQUIRE(4 == stack.Top());

    return TEST_PASS;
}

TestResult TestTopString()
{
	Stack<String> stack;
	String str1("Push Me!");
	String str2("No Push Me!");
	String str3("Ok Push Me!");
	String str4("Ufff Push Me!");
    
    stack.Push(str1);
    REQUIRE(str1 == stack.Top());

    stack.Push(str2);
    REQUIRE(str2 == stack.Top());

    stack.Push(str3);
    REQUIRE(str3 == stack.Top());

    stack.Push(str4);
    REQUIRE(str4 == stack.Top());

    return TEST_PASS;
}

TestResult TestPop()
{
    Stack<double> stack;
    
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    stack.Pop();
    REQUIRE(3 == stack.Count());
    stack.Pop();
    REQUIRE(2 == stack.Count());
    stack.Pop();
    REQUIRE(1 == stack.Count());
    stack.Pop();
    REQUIRE(0 == stack.Count());

    REQUIRE(stack.IsEmpty());

    return TEST_PASS;
}

TestResult TestPopString()
{
	Stack<String> stack;
	String str1("Push Me!");
	String str2("No Push Me!");
	String str3("Ok Push Me!");
	String str4("Ufff Push Me!");
    
    stack.Push(str1);
    stack.Push(str2);
    stack.Push(str3);
    stack.Push(str4);

    stack.Pop();
    REQUIRE(3 == stack.Count());
    stack.Pop();
    REQUIRE(2 == stack.Count());
    stack.Pop();
    REQUIRE(1 == stack.Count());
    stack.Pop();
    REQUIRE(0 == stack.Count());

    REQUIRE(stack.IsEmpty());

    return TEST_PASS;
}

TestResult TestCount()
{
    Stack<double> stack;
    
    stack.Push(1);
    REQUIRE(1 == stack.Count());
    stack.Push(2);
    REQUIRE(2 == stack.Count());
    stack.Push(3);
    REQUIRE(3 == stack.Count());
    stack.Push(4);
    REQUIRE(4 == stack.Count());

    stack.Pop();
    REQUIRE(3 == stack.Count());
    stack.Pop();
    REQUIRE(2 == stack.Count());
    stack.Pop();
    REQUIRE(1 == stack.Count());
    stack.Pop();
    REQUIRE(0 == stack.Count());

    return TEST_PASS;
}

TestResult TestCountString()
{
	Stack<String> stack;
	String str1("Push Me!");
	String str2("No Push Me!");
	String str3("Ok Push Me!");
	String str4("Ufff Push Me!");
    
    stack.Push(str1);
    REQUIRE(1 == stack.Count());
    stack.Push(str2);
    REQUIRE(2 == stack.Count());
    stack.Push(str3);
    REQUIRE(3 == stack.Count());
    stack.Push(str4);
    REQUIRE(4 == stack.Count());

    stack.Pop();
    REQUIRE(3 == stack.Count());
    stack.Pop();
    REQUIRE(2 == stack.Count());
    stack.Pop();
    REQUIRE(1 == stack.Count());
    stack.Pop();
    REQUIRE(0 == stack.Count());

    return TEST_PASS;
}

TestResult TestIsEmpty()
{
    Stack<double> stack;
    
    REQUIRE(stack.IsEmpty());
    stack.Push(1);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    REQUIRE(stack.IsEmpty());
    stack.Push(3);
    REQUIRE(!stack.IsEmpty());
    stack.Push(4);
    stack.Push(5);
    stack.Push(6);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    REQUIRE(stack.IsEmpty());

    return TEST_PASS;
}

TestResult TestIsEmptyString()
{
	Stack<String> stack;
	String str1("Push Me!");
	String str2("No Push Me!");
	String str3("Ok Push Me!");
	String str4("Ufff Push Me!");
    
    REQUIRE(stack.IsEmpty());
    stack.Push(str1);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    REQUIRE(stack.IsEmpty());
    stack.Push(str2);
    REQUIRE(!stack.IsEmpty());
    stack.Push(str3);
    stack.Push(str4);
    stack.Push(str4);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    REQUIRE(stack.IsEmpty());

    return TEST_PASS;
}

