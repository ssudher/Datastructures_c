/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 23 May, 2019, 9:37 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef struct bst
{
    struct bst *left,*right;
    int data;
}bst;

bst *root;

bst* create_node(int d)
{
    bst *newnode;
    newnode = (bst*)malloc(sizeof(bst));
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

bst* add(int n, bst *node)
{
    if(node == NULL)
    {
        node = create_node(n);
    }
    else
    {
        if(n < node->data)
        {
            node->left = add(n, node->left);
        }
        else if(n >= node->data)
        {
            node->right = add(n, node->right);
        }
    }
    return node;
}

void inorder(bst* node)
{
    if(root == NULL)
    {
        printf("\nThe BST is empty!\n");
    }
    else if(node != NULL)
    {
        inorder(node->left);
        printf("%p -> %d,",node,node->data);
        inorder(node->right);
    }
}

void search(int n, bst* node)
{
    if(node == NULL)
    {
        printf("\nThe number was not found!\n");
    }
    if(n == node->data)
    {
        printf("\nThe number was found in the BST!%p -> %d\n",node,node->data);
    }
    else if(n < node->data)
    {
        search(n, node->left);
        printf("\nleftie,%p ->%d",node, node->data);
    }
    else if(n > node->data)
    {
        search(n, node->right);
        printf("\nrightie,%p ->%d",node, node->data);
    }
}

bst** find_min(bst **curr)
{
    if((*curr)->left == NULL)
    {
        return &(*curr);
    }
    else
    {
        find_min(&((*curr)->left));
    }
}

void delete(int n, bst** node)
{
    if((*node) == NULL)
    {
        printf("\nThe number was not found!\n");
        return;
    }
    if(n < (*node)->data)
    {
        delete(n, &((*node)->left));
    }
    else if(n > (*node)->data)
    {
        delete(n, &((*node)->right));
    }
    else
    {
        if((*node)->left == NULL && (*node)->right == NULL)
        {
            (*node) = NULL;
            free(*node);
        }
        else if((*node)->left == NULL && (*node)->right != NULL)
        {
            bst* temp = (*node);
            (*node) = (*node)->right;
            free(temp);
        }
        else if((*node)->left != NULL && (*node)->right == NULL)
        {
            bst* temp = (*node);
            (*node) = (*node)->left;
            free(temp);
        }
        else
        {
            bst** right_min;
            right_min = find_min(&((*node)->right));
            (*node)->data = (*right_min)->data;
            *right_min = NULL;
            free(*right_min);
        }
    }
}

int main(int argc, char** argv) {
    
    int num;
    root = NULL;
    int opt, flag = 1;
    
    
    while(flag == 1)
    {
        printf(" 1.Add numbers to BST\n 2.Inorder view\n 3.Search\n 4.Delete node\n -1.exit\n");
        scanf("%d",&opt);
        
        switch(opt)
        {
            case 1:
                printf("\nEnter the numbers to be inserted in BST, enter \"-1\" to exit\n");
                while(num != -1)
                {
                    scanf("%d",&num);
                    if(num!= -1)
                    {
                        root = add(num, root);
                    }
                }
                num = 0;
                break;
            case 2:
                printf("\nPrinting the BST....\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\n----SEARCHING-----\n");
                printf("\nEnter the number you want to search: ");
                scanf("%d",&num);
                if(root == NULL)
                {
                    printf("\nThe tree is empty!\n");
                }
                else
                {
                    search(num, root);
                }
                printf("\n");
                break;
            case 4:
                printf("\nEnter the number you want to delete: ");
                scanf("%d",&num);
                delete(num, &root);
                break;
            case -1:
                flag = 0;
                break;
        }
    }
    printf("\n");
    return 0;
}

