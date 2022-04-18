#include "../../simple-list/src/List.h"

template<typename T>
T max(const T &a, const T &b)
{
    return a <= b ? b : a;
}

template<typename T>
class AvlTree
{
private:
    struct Node
    {
        T value;
        char height;
        Node *left;
        Node *right;

        Node();

        explicit Node(const T &value);

        ~Node();
    };

    Node *root_;
    long long size_;

    char get_height(Node *node) const;

    void height_fix(Node *node);

    int balance_factor(Node *node) const;

    Node *single_turn_left(Node *node);

    Node *single_turn_right(Node *node);

    Node *double_turn_left(Node *node);

    Node *double_turn_right(Node *node);

    Node* balance(Node *node);

    Node *insert_avl_recurse(Node *node, const T &value);

public:
    AvlTree();

    explicit AvlTree(const T &value);

    long long get_size() const;

    void insert(const T &value);

    Node* get_root() const;
};

template<typename T>
AvlTree<T>::Node::Node() = default;

template<typename T>
AvlTree<T>::Node::Node(const T &value): value(value), height(1), right(nullptr), left(nullptr)
{
}

template<typename T>
AvlTree<T>::Node::~Node()
{
    delete right;
    delete left;
}

template<typename T>
AvlTree<T>::AvlTree(): root_(nullptr), size_(0)
{
}

template<typename T>
AvlTree<T>::AvlTree(const T &value): root_(Node(value)), size_(1)
{
}

template<typename T>
char AvlTree<T>::get_height(AvlTree::Node *node) const
{
    if(node == nullptr)
    {
        return 0;
    } else
    {
        return node->height;
    }
}

template<typename T>
void AvlTree<T>::height_fix(AvlTree::Node *node)
{
    if(!node)
        throw NullPointerException();
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
}

template<typename T>
int AvlTree<T>::balance_factor(AvlTree::Node *node) const
{
    return get_height(node->right) - get_height(node->left);
}

template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::single_turn_left(AvlTree::Node *node)
{
    if(node->right == nullptr)
        throw NullPointerException();

    Node *node_right = node->right;
    node->right = node_right->left;
    node_right->left = node;
    height_fix(node_right);
    height_fix(node);
    return node_right;
}

template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::single_turn_right(AvlTree::Node *node)
{
    if(node->left == nullptr)
        throw NullPointerException();

    Node *node_left = node->left;
    node->left = node_left->right;
    node_left->right = node;
    height_fix(node);
    height_fix(node_left);
    return node_left;
}

/*template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::double_turn_left(AvlTree::Node *node)
{
    node->left = single_turn_right(node->right);
    return single_turn_right(node);
}

template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::double_turn_right(AvlTree::Node *node)
{
    node->right = single_turn_left(node->left);
    return single_turn_left(node);
}*/

template<typename T>
void AvlTree<T>::insert(const T &value)
{
    if(!root_)
    {
        root_ = new Node(value);
    } else
    {
        insert_avl_recurse(root_, value);
    }
}

template<typename T>
typename AvlTree<T>::Node* AvlTree<T>::balance(AvlTree::Node *node)
{
    height_fix(node);
    if(balance_factor(node) == 2)
    {
        if(balance_factor(node->right) < 0)
        {
            single_turn_right(node->right);
        }
        single_turn_left(node);
    } else if(balance_factor(node) == -2)
    {
        if(balance_factor(node->left) > 0)
        {
            single_turn_left(node->left);
        }
        single_turn_right(node);
    } else
    {
        return node;
    }
}

template<typename T>
long long AvlTree<T>::get_size() const
{
    return size_;
}

template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::insert_avl_recurse(AvlTree::Node *node, const T &value)
{
    if(node == nullptr)
    {
        return new Node(value);
    }

    if(value < node->value)
    {
        node->left = insert_avl_recurse(node->left, value);
    } else if(value > node->value)
    {
        node->right = insert_avl_recurse(node->right, value);
    } else
    {
        //return new Node(value);
    }
    //return node;
    node = balance(node);
}

template<typename T>
typename AvlTree<T>::Node *AvlTree<T>::get_root() const
{
    return root_;
}
