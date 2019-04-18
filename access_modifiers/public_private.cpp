
#include <cstdio>

class X
{

    explicit X();
    explicit X(int a_);
    void Foo();
    int GetA() const;

private:
    int m_a;
};

X::X()
    : m_a(0)
{}

X::X(int a_)
    : m_a(a_)
{}

void X::Foo()
{
    printf("%d\n", m_a);
}

void Foo(const X &x1)
{
    printf("%d\n", x1.GetA());
}

int X::GetA() const
{
    return m_a;
}

int main()
{
    X x1;
    x1.Foo();
    printf("%d\n", x1.GetA());
    Foo(x1);

    return 0;
}
