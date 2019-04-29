#ifndef ILRD_RD61_SHARED_POINTER_COUNTER_HPP
#define ILRD_RD61_SHARED_POINTER_COUNTER_HPP
#include <cstddef>

class SharedCounter
{
public:
    SharedCounter();
    ~SharedCounter();
    // SharedCounter(const SharedCounter& other); generated CCtor
    // SharedCounter& operator=(const SharedCounter& other); generated assignment operator
    void Inc();
    void Dec();
    size_t getCount();
private:
    size_t *m_counter;
};

SharedCounter::SharedCounter()
    : m_counter(new size_t(1))
{
}

SharedCounter::~SharedCounter()
{
}

void SharedCounter::Inc()
{
   __sync_add_and_fetch(m_counter, 1);
}

void SharedCounter::Dec()
{
    __sync_sub_and_fetch(m_counter, 1);
}

size_t SharedCounter::getCount()
{
    return *m_counter;
}

#endif