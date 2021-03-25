//
// Created by Illya on 2021/3/23.
//

#ifndef HEAVEN_BINARYTREE_H
#define HEAVEN_BINARYTREE_H
struct Tree
{
    int value = 0;
    struct Tree* left = nullptr;
    struct Tree* right = nullptr;
}Tree,*head;

typedef struct Tree tree;

tree construct(tree* node,int &i)
{
    string choice;
    node = new struct Tree;
    node->value = i;
    node->left = nullptr;
    node->right = nullptr;
    i++;
}
tree display(tree* node)
{
    if (node != nullptr )
    {
        cout << node->value;
    }
    else
    {
        cout << "NULL" << endl;
        return *node;
    }
    display(node->left);
    display(node->right);
}
#endif //HEAVEN_BINARYTREE_H
