#ifndef ILRD_RD61_STACK_HPP
#define ILRD_RD61_STACK_HPP
#include <iostream> /* std::cout */
#include <cassert>
template <class T>
class Stack
{
public:
    explicit Stack();
    ~Stack();
    Stack(const Stack& other);

    void Push(T data);
    void Pop();
    T Top() const;
    size_t Count() const;
    bool IsEmpty() const;

    struct Node
    {
        explicit Node();
        explicit Node(T data, const Node* next);
        Node& operator=(const Node& other_);
        ~Node();
        Node(const Node& other);

        T GetData() const;
        bool HasNext() const;
        const Node &GetNext() const;
        void SetNext(const Node *node);

        const T m_data;
        const Node* m_next;
    };

    Node m_dummy;
};

template <typename T>
Stack<T>::Node::Node() 
    :m_data(), m_next(NULL)
{
}

template <typename T>
Stack<T>::Node::Node(T data, const Node* next)
    :m_data(data), m_next(next)
{
}

template <typename T>
Stack<T>::Node::~Node()
{
}

template <typename T>
Stack<T>::Node::Node(const Node& other)
    :m_data(other.m_data)
{
    m_next = other.m_next;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
    :m_dummy(other.m_dummy)
{

}

template <typename T>
typename Stack<T>::Node& Stack<T>::Node::operator=(const Node& other_)
{
    m_next = other_.m_next;

    return *this;
}

template <typename T>
T Stack<T>::Node::GetData() const
{
    return m_data;
}

template <typename T>
bool Stack<T>::Node::HasNext() const
{
    return m_next != NULL;
}

template <typename T>
const typename Stack<T>::Node& Stack<T>::Node::GetNext() const
{
    return *m_next;
}

template <typename T>
Stack<T>::Stack()
    :m_dummy()
{
}

template <typename T>
Stack<T>::~Stack()
{
    while(!IsEmpty()) 
    {
        Pop();
    }
}

template <typename T>
void Stack<T>::Push(T data)
{
    Node *node_to_insert = new Node(data, &m_dummy.GetNext());

    m_dummy.SetNext(node_to_insert);
}

template <typename T>
void Stack<T>::Node::SetNext(const Node *next)
{
    m_next = next;
}

template <typename T>
void Stack<T>::Pop()
{
    const Node *node_to_pop = &m_dummy.GetNext();

    if (IsEmpty())
    {
        std::cout << "Stack<T> is empty!\n";
        return;
    }

    m_dummy.SetNext(&m_dummy.GetNext().GetNext());
    
    delete node_to_pop;
}

template <typename T>
T Stack<T>::Top() const
{
    if (IsEmpty())    
    {
        std::cout << "Stack<T> is empty!\n";
        return (m_dummy.GetData());
    }

    return m_dummy.GetNext().GetData();
}

template <typename T>
size_t Stack<T>::Count() const
{
    int counter = 0;

    for(Node node_runner = m_dummy; node_runner.HasNext(); node_runner = node_runner.GetNext())
    {
        counter++;
    }

    return counter;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
    return NULL == &m_dummy.GetNext();
}

#endif
