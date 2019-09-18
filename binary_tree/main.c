/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: shrik
 *
 * Created on 21 May, 2019, 10:23 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
 * 
 */
typedef struct btree
{
    struct btree *left;
    struct btree *right;
    char data;
}btree;

btree *root;

btree* create_node(char d)
{
    btree *new;
    new = (btree*)malloc(sizeof(btree));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}

btree* parse_tree(char t[], int n, int i, btree* root)
{
    if(i<n && t[i]!= '\0')
    {
        btree *temp = create_node(t[i]);
        root = temp;
        
        root->left = parse_tree(t, n, 2 * i + 1, root->left); 
        root->right = parse_tree(t, n, 2 * i + 2, root->right); 
    }
    return root;
}

//left Root Right
void inorder(btree* temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        printf("%c,",temp->data);
        inorder(temp->right);
    }
}

//Root left Right
void preorder(btree *temp)
{
    if(temp!= NULL)
    {
        printf("%c,",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

//Left Right Root
void postorder(btree *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);   
        postorder(temp->right);
        printf("%c,",temp->data);
    }
}

int main(int argc, char** argv) {

    char t[15] = {'A','B','C','D','E','F','G','\0','\0','\0','\0','\0','\0','\0','H'};
    root = parse_tree(t,sizeof(t),0,root);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}