#include <iostream>
#include <cstdio>

struct T
{
    explicit T();

    int i;
    int j;
    int k;
    double a;
    double b;
    double c;
};

struct Y
{
    explicit Y();
    explicit Y(T t);

    T &m_tr;
};

T::T()
{
    i = 0;
    j = 0;
    k=0;
    a=0;
    b=0;
    c=0;
}

// Y::Y()
// {

// }

Y::Y(T t)
    :m_tr(t)
{

}


int main()
{
    T t;
    T& tr(t);
    sizeof(tr);
    Y y(t);
    printf("sizeof: %d\n", sizeof(y));
}
