#pragma once

#include "Stack.h"

template<typename T, bool (*cmp)(const T &a, const T &b)>
class BinTree
{
protected:
    class Node
    {
    public:
        T value_;
        Node *right_;
        Node *left_;

        Node();

        explicit Node(T value);
    };

    Node *root_;

    long long size_;

    void clear(Node *node);

public:
    BinTree();

    explicit BinTree(T value);

    explicit BinTree(Node *node);

    BinTree(const BinTree &other);

    BinTree(BinTree &&other) noexcept;

    virtual ~BinTree();

    BinTree &operator=(const BinTree &other);

    BinTree &operator=(BinTree &&other) noexcept;

    class Iterator
    {
    protected:
        Node *node_;

        Stack<Node *> stack;

        Node *travel_left(Node *node);

    public:
       Iterator(Node *node);

        T &operator*() const;

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        void operator++();

        friend BinTree;
    };

    virtual void add(const T &value);

    long long get_size() const;

    virtual T get_root() const;

    virtual void remove(const T &value);

    Iterator begin() const;

    Iterator end() const;

    Iterator find(const T &value) const;
};

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::Node::Node() = default;

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::Node::Node(T value): value_(value), right_(nullptr), left_(nullptr)
{
}

template<typename T, bool (*cmp)(const T &, const T &)>
void BinTree<T, cmp>::clear(Node *node)
{
    if(node != nullptr)
    {
        if(node->left_ != nullptr)
        {
            clear(node->left_);
        }
        if(node->right_ != nullptr)
        {
            clear(node->right_);
        }
        delete node;
    }
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::BinTree(): root_(nullptr), size_(0)
{
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::BinTree(T value): root_(Node(value)), size_(1)
{
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::BinTree(BinTree::Node *node): root_(node), size_(1)
{
}

template<typename T, bool (*cmp)(const T &, const T &)>
BinTree<T, cmp>::BinTree(const BinTree &other): root_(nullptr), size_(0)
{
    Iterator iterator = other.begin();
    for(iterator; iterator != other.end(); ++iterator)
    {
        add(*iterator);
    }
}

template<typename T, bool (*cmp)(const T &, const T &)>
BinTree<T, cmp>::BinTree(BinTree &&other) noexcept: root_(other.root_), size_(other.size_)
{
    other.root_ = nullptr;
    other.size_ = 0;
}

template<typename T, bool (*cmp)(const T &, const T &)>
BinTree<T, cmp>::~BinTree()
{
    clear(root_);
}

template<typename T, bool (*cmp)(const T &, const T &)>
BinTree<T, cmp> &BinTree<T, cmp>::operator=(const BinTree &other)
{
    if(this != &other)
    {
        Iterator iterator = other.begin();
        for(iterator; iterator != other.end(); ++iterator)
        {
            add(*iterator);
        }
    }
    return *this;
}

template<typename T, bool (*cmp)(const T &, const T &)>
BinTree<T, cmp> &BinTree<T, cmp>::operator=(BinTree &&other) noexcept
{
    if(this != &other)
    {
        this->clear(root_);
        root_ = other.root_;
        size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
BinTree<T, cmp>::Iterator::Iterator(BinTree::Node *node): node_(node)
{
    node_ = travel_left(node);
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
T &BinTree<T, cmp>::Iterator::operator*() const
{
    if(node_)
    {
        return node_->value_;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
bool BinTree<T, cmp>::Iterator::operator==(const BinTree::Iterator &other) const
{
    if(this == &other)
    {
        return true;
    }
    return node_ == other.node_;
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
bool BinTree<T, cmp>::Iterator::operator!=(const BinTree::Iterator &other) const
{
    return !(this->operator==(other));
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
void BinTree<T, cmp>::Iterator::operator++()
{
    if(node_->right_ != nullptr)
    {
        node_ = travel_left(node_->right_);
    } else if(!stack.is_empty())
    {
        node_ = stack.top();
        stack.pop_stack();
    } else
    {
        node_ = nullptr;
    }
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
typename BinTree<T, cmp>::Node *BinTree<T, cmp>::Iterator::travel_left(BinTree::Node *node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    while(node->left_ != nullptr)
    {
        stack.push_stack(node);
        node = node->left_;
    }
    return node;
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
void BinTree<T, cmp>::add(const T &value)
{
    if(root_ == nullptr)
    {
        root_ = new Node(value);
        size_++;
        return;
    }
    Node *current = root_;
    Node *parent = nullptr;

    while(current)
    {
        if(cmp(current->value_, value))
        {
            parent = current;
            current = current->right_;
        } else if(cmp(value, current->value_))
        {
            parent = current;
            current = current->left_;
        } else
        {
            return;
        }
    }
    current = new Node(value);
    if(cmp(parent->value_, value))
    {
        parent->right_ = current;
    } else
    {
        parent->left_ = current;
    }
    size_++;
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
long long BinTree<T, cmp>::get_size() const
{
    return size_;
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
T BinTree<T, cmp>::get_root() const
{
    if(root_ != nullptr)
    {
        return root_->value_;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
void BinTree<T, cmp>::remove(const T &value)
{
    if(root_)
    {
        Node *current = root_;
        Node *parent = nullptr;
        while(current)
        {
            if(cmp(current->value_, value))
            {
                parent = current;
                current = current->right_;
            } else if(cmp(value, current->value_))
            {
                parent = current;
                current = current->left_;
            } else
            {
                Node *del = current;
                if(current->left_ == nullptr)
                {
                    if(parent == nullptr)
                    {
                        root_ = current->right_;
                    } else
                    {
                        if(parent->left_ == current)
                        {
                            parent->left_ == current->right_;
                        } else
                        {
                            parent->right_ = current->right_;
                        }
                    }
                } else if(current->right_ == nullptr)
                {
                    if(parent == nullptr)
                    {
                        root_ = current->left_;
                    } else
                    {
                        if(parent->left_ == current)
                        {
                            parent->left_ = current->left_;
                        } else
                        {
                            parent->right_ = current->left_;
                        }
                    }
                } else
                {
                    parent = current;
                    Node *pos = current->right_;
                    while(pos->left_)
                    {
                        parent = pos;
                        pos = pos->left_;
                    }
                    current->value_ = pos->value_;
                    del = pos;
                    if(pos->right_)
                    {
                        parent->right_ = pos->right_;
                    } else
                    {
                        parent->left_ = nullptr;
                    }
                }
                delete del;
                size_--;
                return;
            }
        }
    }
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
typename BinTree<T, cmp>::Iterator BinTree<T, cmp>::begin() const
{
    return Iterator(root_);
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
typename BinTree<T, cmp>::Iterator BinTree<T, cmp>::end() const
{
    return Iterator(nullptr);
}

template<typename T, bool (*cmp)(const T &a, const T &b)>
typename BinTree<T, cmp>::Iterator BinTree<T, cmp>::find(const T &value) const
{
    if(root_)
    {
        Node *current = root_;
        while(current)
        {
            if(cmp(value, current->value_))
            {
                current = current->left_;
            } else if(cmp(current->value_, value))
            {
                current = current->right_;
            } else
            {
                return Iterator(current);
            }
        }
    }
    return Iterator(nullptr);
}