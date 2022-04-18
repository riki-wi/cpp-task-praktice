#pragma once
#include "../../simple-list/src/List.h"
#include "Stack.h"

template<typename T>
class BinTree
{
private:
    struct Node
    {
        Node();

        explicit Node(const T& value);

        ~Node();

        T value;
        Node* right;
        Node* left;
    };

    Node* insert_bin_recurse(Node* node, const T& value);

    Node* remove_bin_recurse(Node* node, const T& value);

    Node* root_;
    long long size_;

public:
    BinTree();

    explicit BinTree(const T& value);


    class Iterator
    {

    };

    void insert(const T& value);

    void remove(const T& value);

    Iterator find(const T& value);

    T get_root() const;

    long long get_size() const;
};

template<typename T>
BinTree<T>::Node::Node() = default;

template<typename T>
BinTree<T>::Node::Node(const T &value): value(value), right(nullptr), left(nullptr)
{

}

template<typename T>
BinTree<T>::Node::~Node()
{
    delete right;
    delete left;
}


template<typename T>
BinTree<T>::BinTree(): root_(nullptr), size_(0)
{
}

template<typename T>
BinTree<T>::BinTree(const T& value): root_(Node(value)), size_(1)
{
}

template<typename T>
void BinTree<T>::insert(const T &value)
{
    if(root_ == nullptr)
    {
        root_ = new Node(value);
    }
    else
    {
        root_ = insert_bin_recurse(root_, value);
    }
}

template<typename T>
void BinTree<T>::remove(const T &value)
{
}

template<typename T>
typename BinTree<T>::Node *BinTree<T>::insert_bin_recurse(Node* node, const T &value)
{
    if(node == nullptr)
    {
        return new Node(value);
    }

    if(value < node->value)
    {
        node->left = insert_bin_recurse(node->left, value);
    }
    else if(node->value < value)
    {
        node->right = insert_bin_recurse(node->right, value);
    }
    else
    {
        return new Node(value);
    }
}

template<typename T>
typename BinTree<T>::Node *BinTree<T>::remove_bin_recurse(Node* node, const T &value)
{
    return nullptr;
}

template<typename T>
typename BinTree<T>::Iterator BinTree<T>::find(const T &value)
{
    if(root_ == nullptr)
    {
        return Iterator(nullptr);
    }


}

template<typename T>
T BinTree<T>::get_root() const
{
    if(root_)
    {
        return root_->value;
    }
    else
    {
        throw NullPointerException();
    }
}

template<typename T>
long long BinTree<T>::get_size() const
{
    return size_;
}





