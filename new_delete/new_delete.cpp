#include <iostream> /* std::cout */
#include <cassert>
#include "new_delete.hpp"

Stack::Node::Node() 
    :m_data(0), m_next(NULL)
{
}

Stack::Node::Node(DataType data, const Node* next)
    :m_data(data), m_next(next)
{
}

Stack::Node::~Node()
{
}

Stack::Node::Node(const Node& other)
    :m_data(other.m_data)
{
    m_next = other.m_next;
}

Stack::Stack(const Stack& other)
    :m_dummy(other.m_dummy)
{

}

Stack::Node& Stack::Node::operator=(const Node& other_)
{
    m_next = other_.m_next;

    return *this;
}

DataType Stack::Node::GetData() const
{
    return m_data;
}

bool Stack::Node::HasNext() const
{
    return m_next != NULL;
}

const Stack::Node& Stack::Node::GetNext() const
{
    return *m_next;
}

Stack::Stack()
    :m_dummy(0, NULL)
{
}

Stack::~Stack()
{
    while(!IsEmpty()) 
    {
        Pop();
    }
}

void Stack::Push(DataType data)
{
    Node *node_to_insert = new Node(data, &m_dummy.GetNext());

    m_dummy.SetNext(node_to_insert);
}

void Stack::Node::SetNext(const Node *next)
{
    m_next = next;
}

void Stack::Pop()
{
    const Node *node_to_pop = &m_dummy.GetNext();

    if (IsEmpty())
    {
        std::cout << "Stack is empty!\n";
        return;
    }

    m_dummy.SetNext(&m_dummy.GetNext().GetNext());
    
    delete node_to_pop;
}

DataType Stack::Top() const
{
    if (IsEmpty())    
    {
        std::cout << "Stack is empty!\n";
        return (m_dummy.GetData());
    }

    return m_dummy.GetNext().GetData();
}

size_t Stack::Count() const
{
    int counter = 0;

    for(Node node_runner = m_dummy; node_runner.HasNext(); node_runner = node_runner.GetNext())
    {
        counter++;
    }

    return counter;
}

bool Stack::IsEmpty() const
{
    return NULL == &m_dummy.GetNext();
}
