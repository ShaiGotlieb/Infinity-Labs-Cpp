#include <cstdio>
#include "default_parameters.hpp"

void Foo(int arg1, int arg2 =3, int arg3 =4);

int main()
{

    Foo(3);
    Foo(5,6);
    // Foo(5, ,6); //not working 
    Foo(4,7,8.7);
    
    return 0;
}

void Foo(int arg1, int arg2, int arg3)
{
    printf("arg1: %d, arg2: %d, arg3: %d\n", arg1, arg2, arg3);
}
