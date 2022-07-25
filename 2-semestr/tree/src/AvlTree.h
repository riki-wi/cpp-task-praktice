#include "BinTree.h"

template<typename T>
class AvlTree : public BinTree<T>
{
protected:
    class AvlNode : public BinTree<T>::Node
    {
    public:
        int height_;
        AvlNode *left_;
        AvlNode *right_;

        AvlNode();

        explicit AvlNode(T value);

        int get_height();

        int balance_factor();

        void fix_height();
    };

    AvlNode *root_;

    AvlNode *rotate_right(AvlNode *node);

    AvlNode *rotate_left(AvlNode *node);

    AvlNode *balance(AvlNode *node);

    AvlNode *add_recurse(AvlNode *node, const T &value);

    AvlNode *remove_recurse(AvlNode *node, const T &value);

public:
    AvlTree();

    explicit AvlTree(T value);

    AvlTree(const AvlTree &other);

    AvlTree(AvlTree &&other) noexcept;

    ~AvlTree();

    AvlTree &operator=(const AvlTree &other);

    AvlTree &operator=(AvlTree &&other) noexcept;

    void add(const T &value) override;

    T get_root() const override;

    void remove(const T &value) override;
};

template<typename T>
AvlTree<T>::AvlNode::AvlNode(): BinTree<T>::Node(), height_(0), left_(nullptr), right_(nullptr)
{

}

template<typename T>
AvlTree<T>::AvlNode::AvlNode(T value): BinTree<T>::Node(value), height_(1), left_(nullptr), right_(nullptr)
{
}

template<typename T>
int AvlTree<T>::AvlNode::balance_factor()
{
    return (right_->get_height() - left_->get_height());
}

template<typename T>
int AvlTree<T>::AvlNode::get_height()
{
    if(this == nullptr)
    {
        return 0;
    } else
    {
        return this->height_;
    }
}

template<typename T>
void AvlTree<T>::AvlNode::fix_height()
{
    if(right_->get_height() > left_->get_height())
    {
        height_ = right_->get_height() + 1;
    } else
    {
        height_ = left_->get_height() + 1;
    }
}

template<typename T>
AvlTree<T>::AvlTree(): BinTree<T>(), root_(nullptr)
{
}

template<typename T>
AvlTree<T>::AvlTree(T value): BinTree<T>(value), root_(new AvlNode(value))
{
}

template<typename T>
AvlTree<T>::AvlTree(const AvlTree &other): root_(nullptr), BinTree<T>::size_(0)
{
    typename BinTree<T>::Iterator iterator = other.begin();
    for(iterator; iterator != other.end(); ++iterator)
    {
        add(*iterator);
    }
}

template<typename T>
AvlTree<T>::AvlTree(AvlTree &&other) noexcept: root_(other.root_), BinTree<T>::size_(other.size_)
{
    other.root_ = nullptr;
    other.size_ = 0;
}

template<typename T>
AvlTree<T>::~AvlTree()
{
    BinTree<T>::clear(root_);
}

template<typename T>
AvlTree<T> &AvlTree<T>::operator=(const AvlTree &other)
{
    if(this != &other)
    {
        typename BinTree<T>::Iterator iterator = other.begin();
        for(iterator; iterator != other.end(); ++iterator)
        {
            add(*iterator);
        }
    }
    return *this;
}

template<typename T>
AvlTree<T> &AvlTree<T>::operator=(AvlTree &&other) noexcept
{
    if(this != &other)
    {
        clear(root_);
        root_ = other.root_;
        BinTree<T>::size_ = other.size_;
        other.root_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<typename T>
T AvlTree<T>::get_root() const
{
    if(this->root_)
    {
        return this->root_->value_;

    } else
    {
        throw NullPointerException();
    }
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::rotate_right(AvlTree::AvlNode *node)
{
    AvlNode *current = node->left_;
    node->left_ = current->right_;
    current->right_ = node;
    node->fix_height();
    current->fix_height();
    return current;
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::rotate_left(AvlTree::AvlNode *node)
{
    AvlNode *current = node->right_;
    node->right_ = current->left_;
    current->left_ = node;
    node->fix_height();
    current->fix_height();
    return current;
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::balance(AvlTree::AvlNode *node)
{
    node->fix_height();
    if(node->balance_factor() == 2)
    {
        if(node->right_->balance_factor() < 0)
        {
            node->right_ = rotate_right(node->right_);
        }
        return rotate_left(node);
    } else if(node->balance_factor() == -2)
    {
        if(node->left_->balance_factor() > 0)
        {
            node->left_ = rotate_left(node->left_);
        }
        return rotate_right(node);
    } else
    {
        return node;
    }
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::add_recurse(AvlTree::AvlNode *node, const T &value)
{
    if(node == nullptr)
    {
        return new AvlNode(value);
    }
    if(node->value_ < value)
    {
        node->right_ = add_recurse(node->right_, value);
    } else
    {
        node->left_ = add_recurse(node->left_, value);
    }
    return balance(node);
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::remove_recurse(AvlTree::AvlNode *node, const T &value)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(value < node->value_)
    {
        node->left_ = remove_recurse(node->left_, value);
    } else if(node->value_ < value)
    {
        node->right_ = remove_recurse(node->right_, value);
    } else
    {
        AvlNode *left = node->left_;
        AvlNode *right = node->right_;
        delete node;
        this->size_--;
        if(right == nullptr)
        {
            return left;
        }
        AvlNode *min = right;
        while(min->left_)
        {
            min = min->left_;
        }
        min->right_ = right;
        min->left_ = left;
        return balance(min);
    }
    return balance(node);
}

template<typename T>
void AvlTree<T>::add(const T &value)
{
    root_ = add_recurse(root_, value);
    this->size_++;
}

template<typename T>
void AvlTree<T>::remove(const T &value)
{
    root_ = remove_recurse(root_, value);
}

