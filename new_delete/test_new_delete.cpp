#include <iostream> /* std::cout */
#include "test.hpp"

#include "new_delete.hpp"

TestResult TestPush();
TestResult TestTop();
TestResult TestPop();
TestResult TestCount();
TestResult TestIsEmpty();

int main()
{
    RUN_TEST(TestPush);
    RUN_TEST(TestTop);
    RUN_TEST(TestPop);
    RUN_TEST(TestCount);
    RUN_TEST(TestIsEmpty);

    return 0;
}

TestResult TestPush()
{
    Stack *stack = new Stack();

    REQUIRE(stack->IsEmpty());

    stack->Push(1);
    REQUIRE(1 == stack->Top());

    stack->Push(2);
    REQUIRE(2 == stack->Top());
    stack->Push(3);
    REQUIRE(3 == stack->Top());
    stack->Push(4);
    REQUIRE(4 == stack->Top());

    REQUIRE(4 == stack->Count());
    REQUIRE(!stack->IsEmpty());

    delete stack;

    return TEST_PASS;
}

TestResult TestTop()
{
    Stack *stack = new Stack();
    
    stack->Push(1);
    REQUIRE(1 == stack->Top());

    stack->Push(2);
    REQUIRE(2 == stack->Top());

    stack->Push(3);
    REQUIRE(3 == stack->Top());

    stack->Push(4);
    REQUIRE(4 == stack->Top());

    delete stack;

    return TEST_PASS;
}

TestResult TestPop()
{
    Stack *stack = new Stack();
    
    stack->Push(1);
    stack->Push(2);
    stack->Push(3);
    stack->Push(4);

    stack->Pop();
    REQUIRE(3 == stack->Count());
    stack->Pop();
    REQUIRE(2 == stack->Count());
    stack->Pop();
    REQUIRE(1 == stack->Count());
    stack->Pop();
    REQUIRE(0 == stack->Count());

    REQUIRE(stack->IsEmpty());

    delete stack;

    return TEST_PASS;
}

TestResult TestCount()
{
    Stack *stack = new Stack();
    
    stack->Push(1);
    REQUIRE(1 == stack->Count());
    stack->Push(2);
    REQUIRE(2 == stack->Count());
    stack->Push(3);
    REQUIRE(3 == stack->Count());
    stack->Push(4);
    REQUIRE(4 == stack->Count());

    stack->Pop();
    REQUIRE(3 == stack->Count());
    stack->Pop();
    REQUIRE(2 == stack->Count());
    stack->Pop();
    REQUIRE(1 == stack->Count());
    stack->Pop();
    REQUIRE(0 == stack->Count());

    delete stack;

    return TEST_PASS;
}

TestResult TestIsEmpty()
{
    Stack *stack = new Stack();
    
    REQUIRE(stack->IsEmpty());
    stack->Push(1);
    REQUIRE(!stack->IsEmpty());
    stack->Pop();
    REQUIRE(stack->IsEmpty());
    stack->Push(3);
    REQUIRE(!stack->IsEmpty());
    stack->Push(4);
    stack->Push(5);
    stack->Push(6);
    REQUIRE(!stack->IsEmpty());
    stack->Pop();
    stack->Pop();
    stack->Pop();
    stack->Pop();
    REQUIRE(stack->IsEmpty());

    delete stack;

    return TEST_PASS;
}
