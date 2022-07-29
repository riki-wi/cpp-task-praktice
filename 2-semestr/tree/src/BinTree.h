#pragma once

#include "Stack.h"

template<typename T>
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

        enum flag{TRAVEL, NO_TRAVEL};

        flag flag_travel_;

    public:
        explicit Iterator(Node *node, flag flag_travel = TRAVEL);

        T &operator*();

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        void operator++();

        friend BinTree;
    };

    void add(const T &value);

    long long get_size() const;

    virtual T get_root() const;

    virtual void remove(const T &value);

    Iterator begin() const;

    Iterator end() const;

    Iterator find(const T &value) const;
};

template<typename T>
BinTree<T>::Node::Node() = default;

template<typename T>
BinTree<T>::Node::Node(T value): value_(value), right_(nullptr), left_(nullptr)
{
}

template<typename T>
void BinTree<T>::clear(Node *node)
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

template<typename T>
BinTree<T>::BinTree(): root_(nullptr), size_(0)
{
}

template<typename T>
BinTree<T>::BinTree(T value): root_(Node(value)), size_(1)
{
}

template<typename T>
BinTree<T>::BinTree(BinTree::Node *node): root_(node), size_(1)
{
}

template<typename T>
BinTree<T>::BinTree(const BinTree &other): root_(nullptr), size_(0)
{
    Iterator iterator = other.begin();
    for(iterator; iterator != other.end(); ++iterator)
    {
        add(*iterator);
    }
}

template<typename T>
BinTree<T>::BinTree(BinTree &&other) noexcept: root_(other.root_), size_(other.size_)
{
    other.root_ = nullptr;
    other.size_ = 0;
}

template<typename T>
BinTree<T>::~BinTree()
{
    clear(root_);
}

template<typename T>
BinTree<T> &BinTree<T>::operator=(const BinTree &other)
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

template<typename T>
BinTree<T> &BinTree<T>::operator=(BinTree &&other) noexcept
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

template<typename T>
BinTree<T>::Iterator::Iterator(BinTree::Node *node, flag flag_travel): node_(node), flag_travel_(flag_travel)
{
    if(flag_travel_ == 0)
    {
        node_ = travel_left(node);
    }
}

template<typename T>
T &BinTree<T>::Iterator::operator*()
{
    if(node_)
    {
        return node_->value_;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
bool BinTree<T>::Iterator::operator==(const BinTree::Iterator &other) const
{
    if(this == &other)
    {
        return true;
    }
    return node_ == other.node_;
}

template<typename T>
bool BinTree<T>::Iterator::operator!=(const BinTree::Iterator &other) const
{
    return !(this->operator==(other));
}

template<typename T>
void BinTree<T>::Iterator::operator++()
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

template<typename T>
typename BinTree<T>::Node *BinTree<T>::Iterator::travel_left(BinTree::Node *node)
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

template<typename T>
void BinTree<T>::add(const T &value)
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
        if(current->value_ < value)
        {
            parent = current;
            current = current->right_;
        } else if(value < current->value_)
        {
            parent = current;
            current = current->left_;
        } else
        {
            return;
        }
    }
    current = new Node(value);
    if(parent->value_ < value)
    {
        parent->right_ = current;
    } else
    {
        parent->left_ = current;
    }
    size_++;
}

template<typename T>
long long BinTree<T>::get_size() const
{
    return size_;
}

template<typename T>
T BinTree<T>::get_root() const
{
    if(root_ != nullptr)
    {
        return root_->value_;
    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
void BinTree<T>::remove(const T &value)
{
    if(root_)
    {
        Node *current = root_;
        Node *parent = nullptr;
        while(current)
        {
            if(current->value_ < value)
            {
                parent = current;
                current = current->right_;
            } else if(value < current->value_)
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

template<typename T>
typename BinTree<T>::Iterator BinTree<T>::begin() const
{
    return Iterator(root_);
}

template<typename T>
typename BinTree<T>::Iterator BinTree<T>::end() const
{
    return Iterator(nullptr);
}

template<typename T>
typename BinTree<T>::Iterator BinTree<T>::find(const T &value) const
{
    if(root_)
    {
        Node *current = root_;
        while(current)
        {
            if(value < current->value_)
            {
                current = current->left_;
            } else if(current->value_ < value)
            {
                current = current->right_;
            } else
            {
                return Iterator(current, Iterator::NO_TRAVEL);
            }
        }
    }
    return Iterator(nullptr);
}