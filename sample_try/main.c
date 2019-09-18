#include <stdio.h> 
  
// Representation of a node 
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to insert node 
void insert(struct Node** root, int item) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = item; 
    temp->next = *root; 
    *root = temp; 
} 
  
void display(struct Node* root) 
{ 
    struct Node *t = root;
    while (t != NULL) { 
        printf("%p -> %d\n",t,t->data);
        t = t->next;
    }
} 
  
struct Node *arrayToList(int arr[], int n) 
{ 
    struct Node *root = NULL; 
    for (int i = n-1; i >= 0 ; i--)
    {
        printf("%d,",arr[i]);
        insert(&root, arr[i]); 
    }
    return root; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    struct Node* root = arrayToList(arr, n); 
    display(root); 
    return 0; 
}