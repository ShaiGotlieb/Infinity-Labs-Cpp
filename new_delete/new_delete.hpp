#ifndef ILRD_RD61_NEW_DELETE_HPP
#define ILRD_RD61_NEW_DELETE_HPP

typedef int DataType;

struct Stack
{
public:
    explicit Stack();
    ~Stack();
    Stack(const Stack& other);

    void Push(DataType data);
    void Pop();
    DataType Top() const;
    size_t Count() const;
    bool IsEmpty() const;

    struct Node
    {
        explicit Node();
        explicit Node(DataType data, const Node* next);
        Node& operator=(const Node& other_);
        ~Node();
        Node(const Node& other);

        DataType GetData() const;
        bool HasNext() const;
        const Node &GetNext() const;
        void SetNext(const Node *node);

        const DataType m_data;
        const Node* m_next;
    };

    Node m_dummy;
};

#endif
