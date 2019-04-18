#include <iostream>
using namespace std;

struct Counter
{
    Counter& Inc();
    void Dec();
    void Hello();

    int m_a;
    int m_b;
};

Counter& Counter::Inc()
{
    ++m_a;
    m_b += 2;

    return *this;
}

void Counter::Dec()
{
    --m_a;
    m_b /= 2;
}

void Hello()
{
    cout << "Hello?:" << endl;
}

int main()
{
    Counter x1;
    Counter x2;

    x1.m_a = 7;

    x1.Inc().Inc().Inc();
    
    x2.Dec();

    cout << "x1.m_a: " << x1.m_a << "\n";
    cout << "x2.m_a: " << x2.m_a << "\n";
    cout << "x2.m_b: " << x2.m_b << "\n";
    cout << "size of Counter struct: " << sizeof(Counter) << "\n";

    Hello();

    //17.new/delete playing

    float *f = new float(12.6);
    printf("f is: %f\n", *f);
    delete f;
    printf("f after delete is: %f\n", *f);

    f = new float[15];
    f[0] = 0.1456789;
    f[1] = 1.1456789;
    f[2] = 2.1456789;
    f[3] = 3.1456789;
    printf("f[0]  is: %f\n", f[0]);
    printf("f[1] is: %f\n", f[1]);
    printf("f[2] is: %f\n", f[2]);
    printf("f[3] is: %f\n", f[3]);
    delete[] f;
    printf("f[0] after delete is: %f\n", f[0]);
    printf("f[1] after delete is: %f\n", f[1]);
    printf("f[2] after delete is: %f\n", f[2]);
    printf("f[3] after delete is: %f\n", f[3]);
    
    Counter *c1 = new Counter;
    delete c1;

    return 0;
}
