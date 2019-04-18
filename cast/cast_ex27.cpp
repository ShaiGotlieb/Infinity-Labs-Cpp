// #include "cast_ex27.hpp"

typedef struct List List;
typedef struct Person Person;


struct List
{
    int key;
};

struct Person
{
    int age;
};

void *ll_find(List *ll,int key)
{
    void *pv = 0;
    
    return (pv);
}

void Foo(List *ll, int key, int age)
{
    void *vv = ll_find(ll,key);
    Person *p = (Person *)ll;
    p->age = age;
}

int main()
{
    List a;
    Foo(&a, 12, 12);

    return 0;
}

