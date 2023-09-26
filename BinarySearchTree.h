#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

//-------------------------------------------------------------------------------
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

     /**
	 * @class Binary Search Tree
	 *
	 * @author Fiko Febriyan
	 * @version 01
	 * @date 10/04/2022
	 *
	 **/

//-------------------------------------------------------------------------------

template <class T>
struct NodePointer
{
    T data;// data variable
    NodePointer<T> *left;// node left variable
    NodePointer<T> *right;// node right variable
};

//-------------------------------------------------------------------------------
template <class T>
class BinarySearchTree
{
public:
    typedef void (*f1Typ)(T &);

    /**
    * @brief  default constructor
    **/
    BinarySearchTree();

    /**
    * @brief second constructor
    **/
    BinarySearchTree(T data);

    /**
    * @brief destructor method
    **/
    ~BinarySearchTree();

    /**
    * @brief to insert node
    * @return true
    **/
    bool insertNode(T data);


    /**
    * @brief search node in the tree
    * @return boolean - returns true if the search node is found
    **/
    bool searchNode(const T& item) const;

    /**
    * @brief delete the node
    * @return void
    **/
    void DeleteTree();

    /**
    * @brief get maximum value
    * @return true
    **/
    int MaximumValue();

    /**
    * @brief get minimum value
    * @return true
    **/
    int minValue();

    /**
    * @brief ensure node is in inorder format
    * @return void
    **/
    void inOrderTraversal(f1Typ f1) const;


    /**
    * @brief ensure node is in preorder format
    * @return void
    **/
    void preOrderTraversal(f1Typ f1) const;


    /**
    * @brief ensure node is in postorder format
    * @return void
    **/
    void postOrderTraversal(f1Typ f1) const;

    /**
    * @brief overloaded assignment operator
    **/
    const BinarySearchTree<T>& operator = (const BinarySearchTree<T>& );



private:

    NodePointer<T> *root;


    /**
    * @brief to insert the node from binary search tree by implement the code
    * @param data, node
    * @return true or false
    **/
    bool insertNode(T data, NodePointer<T> *node);

    /**
    * @brief use to search BST for a given value.
    * The pointer root points to the root node of BST then search begin
    **/
    bool searchh(const T& item, NodePointer<T>* current ) const;

    /**
    * @brief get the highest value in the node
    **/
    int MaximumValue(NodePointer<T> *node);

    /**
    * @brief get the lowest value in the node
    **/
    int minValue(NodePointer<T> *node);


    /**
    * @brief to delete the node from binary search tree by implement the code
    * @param node
    * @return void
    **/
    void DeleteTree(NodePointer<T> *node);


    /**
    * @brief to insert the node from binary search tree by implement the code using preorder format
    * @param node
    * @return void
    **/
    void preOrderTraversal(f1Typ f1,NodePointer<T> *node)const;


    /**
    * @brief to insert the node from binary search tree by implement the code using inorder format
    * @param node
    * @return void
    **/
    void inOrderTraversal(f1Typ f1,NodePointer<T> *node) const;


    /**
    * @brief to insert the node from binary search tree by implement the code using postorder format
    * @param node
    * @return void
    **/
    void postOrderTraversal(f1Typ f1,NodePointer<T> *node)const;


    /**
    * @brief makes a copy of binary tree
    * @post -condition : Pointer copiedTreeRoot points to the root of the copied binary tree
    **/
    void  CopyTrees(NodePointer<T>* &CopiedTreeRoot,NodePointer<T>* otherTreeRoot );


};


//-------------------------------------------------------------------------------
template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

//-------------------------------------------------------------------------------
template <class T>
BinarySearchTree<T>::BinarySearchTree(T data)
{
    root = new NodePointer<T>;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    DeleteTree(root);
}

//-------------------------------------------------------------------------------
template <class T>
bool BinarySearchTree<T>::insertNode(T data)
{
    if (root != NULL)
    {
        return insertNode(data, root);
    }
    else
    {
        root = new NodePointer<T>;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return true;
    }
}


//-------------------------------------------------------------------------------
template <class T>
bool BinarySearchTree<T>:: searchNode(const T& item) const
{
    return searchh(item, this -> root);
}




//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::DeleteTree()
{
    DeleteTree(root);
}

//-------------------------------------------------------------------------------
template <class T>
int BinarySearchTree<T>::MaximumValue()
{
    MaximumValue(root);
}

//-------------------------------------------------------------------------------
template <class T>
int BinarySearchTree<T>::minValue()
{
    minValue(root);
}

//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::inOrderTraversal(f1Typ f1) const
{
    inOrderTraversal(f1, root);
}


//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>:: preOrderTraversal(f1Typ f1)const
{
    preOrderTraversal(f1,root);
}


//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::postOrderTraversal(f1Typ f1)const
{
    postOrderTraversal(f1,root);
}

//-------------------------------------------------------------------------------
template <class T>
bool BinarySearchTree<T>::insertNode(T data, NodePointer<T> *node)
{
    if (data < node->data)
    {// Create new node for left
        if (node->left != NULL)
        {insertNode(data, node->left);}
        else
        {
            node->left = new NodePointer<T>;
            node->left->data = data;
            node->left->left = NULL;
            node->left->right = NULL;
            return true;
        }
    }
    if (data > node->data) // Create new node for right
    {
        if (node->right != NULL)
        {insertNode(data, node->right);}
        else
        {
            node->right = new NodePointer<T>;
            node->right->data = data;
            node->right->left = NULL;
            node->right->right = NULL;
            return true;
        }
    }
    return false;
}


//-------------------------------------------------------------------------------
template <class T>
bool BinarySearchTree<T>:: searchh(const T& item, NodePointer<T>* current ) const
{
    if (current == nullptr)
    {
        return false;
    }
    else if (current -> data ==item )
    {
        return true;
    }
    else if (current -> data <item)
    {
        return searchh(item, current -> right);
    }
    else if (current -> data > item)
    {
        return searchh(item, current -> left);
    }
}


//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::DeleteTree(NodePointer<T> *node)
{
    if(node != NULL)
    {
        root = NULL;
    }
    else
    {
        cout << "";
    }
}

//-------------------------------------------------------------------------------
template <class T>
int BinarySearchTree<T>::MaximumValue(NodePointer<T> *node)
{
    struct NodePointer<T> *current  = node;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

//-------------------------------------------------------------------------------
template <class T>
int BinarySearchTree<T>::minValue(NodePointer<T> *node)
{
    struct NodePointer<T> *current  = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}

//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::inOrderTraversal(f1Typ f1, NodePointer<T> *node) const
{
    if (node != NULL)
    {
        inOrderTraversal(f1,node->left);
        (f1)(node->data);
        inOrderTraversal(f1,node->right);
    }
}

//--------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::preOrderTraversal(f1Typ f1, NodePointer<T> *node) const
{
    if (node != NULL)
    {
        (f1)(node->data);
        preOrderTraversal(f1,node->left);
        preOrderTraversal(f1,node->right);
    }
}

//-------------------------------------------------------------------------------
template <class T>
void BinarySearchTree<T>::postOrderTraversal(f1Typ f1, NodePointer<T> *node) const
{
    if (node != NULL)
    {
        postOrderTraversal(f1,node->left);
        postOrderTraversal(f1,node->right);
        (f1)(node->data);
    }
}




template <class T>
void BinarySearchTree<T>:: CopyTrees(NodePointer<T>* &CopiedTreeRoot,NodePointer<T>* otherTreeRoot )
{
    if (otherTreeRoot == nullptr)
    {
        CopiedTreeRoot = nullptr;
    }
    else
    {
        CopiedTreeRoot = new NodePointer<T>;
        CopiedTreeRoot -> data = otherTreeRoot ->data;
        CopyTrees(CopiedTreeRoot ->left, otherTreeRoot ->left);
        CopyTrees(CopiedTreeRoot ->right, otherTreeRoot -> right);
    }
}

//-------------------------------------------------------------------------------

template <class T>
const BinarySearchTree<T>& BinarySearchTree<T>:: operator = (const BinarySearchTree<T>& otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
            DeleteTree(root);

        if (otherTree.root == nullptr)
            root == nullptr;
        else CopyTrees(root, otherTree.root);

    }
    return *this;
}



#endif // BINARYSEARCHTREE_H_INCLUDED
