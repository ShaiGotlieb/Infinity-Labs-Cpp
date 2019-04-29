#ifndef ILRD_RD61_SHARED_POINTER_HPP
#define ILRD_RD61_SHARED_POINTER_HPP

#include <cstddef> //NULL
#include "sharedcounter.hpp"

namespace ilrd
{
template<class T>
class SharedPtr
{
    template<typename U>
    friend class SharedPtr;
public:
    explicit SharedPtr(T * const ptr = NULL);
    SharedPtr(const SharedPtr& other);
    ~SharedPtr();
    
    template<typename U>
    SharedPtr(const SharedPtr<U>& other);
    template<typename U>
    SharedPtr<T>& operator=(const SharedPtr<U>& other);

    SharedCounter* getCounter();
    SharedPtr<T>& operator=(const SharedPtr& other);
    T& operator*();
    T* operator->();
    bool operator ==(const SharedPtr& other);
    bool operator!=(const SharedPtr& other);
    operator bool() const;

private:
    bool IsReferenced();
    void DeleteMembers();
    T *m_ptr;
    SharedCounter *m_counter;
};

template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr& other)
    : m_ptr(other.m_ptr)
    , m_counter(other.m_counter)
{
    m_counter->Inc();
}

template <class T>
SharedPtr<T>::SharedPtr(T * const ptr)
    : m_ptr(ptr)
    , m_counter(new SharedCounter())
{
}

template <class T>
SharedPtr<T>::~SharedPtr()
{
    m_counter->Dec();
    if (!IsReferenced())
    {   
        DeleteMembers();  
    }
}

template <class T>
template <typename U>
SharedPtr<T>::SharedPtr(const SharedPtr<U>& other)
    : m_ptr(other.m_ptr)
    , m_counter(other.m_counter)
{
    m_counter->Inc();
}

template <class T>
T* SharedPtr<T>::operator->()
{
    return m_ptr;
}

template <class T>
T& SharedPtr<T>::operator*()
{
    return *m_ptr;
}

template <class T>
bool SharedPtr<T>::operator==(const SharedPtr& other)
{
    return m_ptr == other.m_ptr;
}

template <class T>
bool SharedPtr<T>::operator!=(const SharedPtr& other)
{
    return operator=(other);
}

template <class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
    m_counter->Dec();
    other.m_counter->Inc();    

    if (!IsReferenced())
    {
        DeleteMembers();
    }
    
    m_ptr = other.m_ptr;
    m_counter = other.m_counter;
    
    return *this; 
}

template <class T>
template <typename U>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<U>& other)
{
    m_counter->Dec();
    other.m_counter->Inc();    

    if (!IsReferenced())
    {
        DeleteMembers();
    }
    
    m_ptr = other.m_ptr;
    m_counter = other.m_counter;
    
    return *this; 
}

template <class T>
SharedPtr<T>::operator bool() const
{
    return NULL != m_ptr;
}

template <class T>
bool SharedPtr<T>::IsReferenced()
{
    return 0 < m_counter->getCount();
}

template <class T>
SharedCounter* SharedPtr<T>::getCounter()
{
    return m_counter;
}

template <class T>
void SharedPtr<T>::DeleteMembers()
{
    delete m_ptr;
    delete m_counter;
}

}//namespace ilrd
#endif