class NullPointerException
{
public:
    const char *what()
    {
        return "Null pointer dereference";
    }
};

template<typename T>
class List
{
private:
    struct Node
    {
    private:
        T data;
        Node *next;
    public:
        Node() = default;

        explicit Node(T data) : data(data), next(nullptr)
        {
        };
        friend List;
    };

    Node *front_;
    long long size_;

public:
    List();

    List(const List &other);

    List(List &&other) noexcept;

    List(T value, long long size);

    ~List();

    List &operator=(const List &other);

    List &operator=(List &&other) noexcept;

    class Iterator
    {
    private:
        Node *node_;
    public:
        explicit Iterator(Node *node);

        T &operator*() const;

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        void operator++();
    };

    void push_front(const T &value);

    void push_back(const T &value);

    void push_after(const T &value, const Iterator &iter);

    T front() const;

    bool empty() const;

    long long size() const;

    void reverse();

    void clear();

    void pop_front();

    void pop_back();

    Iterator end() const;

    Iterator begin() const;

    Iterator find(const T &value) const;
};

template<typename T>
List<T>::List(): size_(0), front_(nullptr)
{
};

template<typename T>
List<T>::List(const List &other): size_(other.size_), front_(nullptr)
{
    Iterator iterator = other.begin();
    for(iterator; iterator != other.end(); ++iterator)
    {
        push_front(*iterator);
    }
    reverse();
}

template<typename T>
List<T>::List(List &&other) noexcept: front_(other.front_), size_(other.size_)
{
    other.clear();
}

template<typename T>
List<T>::List(T value, long long int size): size_(size), front_(nullptr)
{
    for(int i = 0; i < size; i++)
    {
        push_front(value);
    }
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
List<T> &List<T>::operator=(const List &other)
{
    if(this != &other)
    {
        Iterator iterator = other.begin();
        for(iterator; iterator != other.end(); ++iterator)
        {
            push_front(*iterator);
        }
        reverse();
    }
    return *this;
}

template<typename T>
List<T> &List<T>::operator=(List &&other) noexcept
{
    if(this != &other)
    {
        front_ = other.front_;
        size_ = other.size_;
        other.clear();
    }
    return *this;
}

template<typename T>
void List<T>::push_front(const T &value)
{
    Node *node = new Node(value);
    if(node)
    {
        node->next = front_;
        front_ = node;
        size_++;
    }
}

template<typename T>
void List<T>::push_back(const T &value)
{
    Node *node = new Node(value);
    if(!front_)
    {
        push_front(value);
        size_++;
        return;
    }

    Node *temp = front_;
    if(node)
    {
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
        size_++;
    }
}

template<typename T>
void List<T>::push_after(const T &value, const List::Iterator &iter)
{
    if(!front_)
    {
        push_front(value);
        return;
    }

    Iterator iter_null = Iterator(nullptr);
    if(iter_null == iter)
    {
        push_back(value);
        return;
    }

    Node *node = new Node(value);
    if(node)
    {
        Node *temp = front_;
        Iterator iterator = Iterator(temp);
        while(temp)
        {
            if(iterator == iter)
            {
                node->next = temp->next;
                temp->next = node;
                size_++;
            }
            temp = temp->next;
            ++iterator;
        }
    }
}

template<typename T>
T List<T>::front() const
{
    if(front_)
    {
        return front_->data;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
bool List<T>::empty() const
{
    return (size_ == 0);
}

template<typename T>
long long List<T>::size() const
{
    return size_;
}

template<typename T>
void List<T>::reverse()
{
    if(!front_)
        return;

    Node *temp;
    Node *next = nullptr;
    Node *prev = nullptr;
    temp = front_;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    front_ = prev;
    delete temp;
    delete next;
}

template<typename T>
void List<T>::clear()
{
    Node *temp;
    while(front_)
    {
        temp = front_;
        front_ = front_->next;
        delete temp;
    }
    size_ = 0;
}

template<typename T>
void List<T>::pop_front()
{
    Node *node = front_;
    if(node)
    {
        front_ = front_->next;
        delete node;
        size_--;
    }
}

template<typename T>
void List<T>::pop_back()
{
    Node *node = front_;
    Node *prev = nullptr;
    if(node)
    {
        while(node->next)
        {
            prev = node;
            node = node->next;
        }
        delete prev->next;
        prev->next = nullptr;
        size_--;
    }
}

template<typename T>
typename List<T>::Iterator List<T>::end() const
{
    return Iterator(nullptr);
}

template<typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(front_);
}

template<typename T>
typename List<T>::Iterator List<T>::find(const T &value) const
{
    Node *node = front_;
    while(node)
    {
        if(node->data == value)
            return Iterator(node);
        node = node->next;
    }
    return Iterator(nullptr);
}

template<typename T>
List<T>::Iterator::Iterator(Node *node): node_(node)
{
}

template<typename T>
T &List<T>::Iterator::operator*() const
{
    if(node_)
    {
        return node_->data;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
bool List<T>::Iterator::operator==(const Iterator &other) const
{
    if(this == &other)
    {
        return true;
    }
    return node_ == other.node_;
}

template<typename T>
bool List<T>::Iterator::operator!=(const Iterator &other) const
{
    return !(this->operator==(other));
}

template<typename T>
void List<T>::Iterator::operator++()
{
    if(node_)
    {
        node_ = node_->next;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
List<T> intersect_list_sorted(bool (*cmp)(const T &, const T &),
                              const typename List<T>::Iterator list_one_begin,
                              const typename List<T>::Iterator list_two_begin,
                              const typename List<T>::Iterator list_one_end,
                              const typename List<T>::Iterator list_two_end)
{
    List<T> result;
    typename List<T>::Iterator list_one = list_one_begin;
    typename List<T>::Iterator list_two = list_two_begin;


    while(list_two != list_two_end && list_one != list_one_end)
    {
        if(cmp(*list_one, *list_two))
        {
            result.push_front(*list_one);
            ++list_one;
        } else
        {
            result.push_front(*list_two);
            ++list_two;
        }
    }

    if(list_one == list_one_end)
    {
        while(list_two != list_two_end)
        {
            result.push_front(*list_two);
            ++list_two;
        }
    } else
    {
        while(list_one != list_one_end)
        {
            result.push_front(*list_one);
            ++list_one;
        }
    }
    result.reverse();
    return result;
}
