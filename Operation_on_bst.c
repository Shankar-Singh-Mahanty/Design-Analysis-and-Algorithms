#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct node{
    int data;
    struct node *left;
    struct node *right;
};
// globally initialized root pointer
struct node *root = NULL;
// function prototyping
struct node *create_node(int);
void insert(int);
struct node *delete (struct node *, int);
struct node *search(struct node *, int);
void inorder(struct node *);
void postorder();
void preorder();
int get_data();

int main(){
    int userChoice;
    int userActive = 'Y';
    int data;
    struct node* result = NULL;

    while (userActive == 'Y' || userActive == 'y'){
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n\n-- Traversals --");
        printf("\n\t4. Inorder ");
        printf("\n\t5. Post Order ");
        printf("\n\t6. Pre Oder ");
        printf("\n7. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        printf("\n");
        switch(userChoice){
            case 1:
                data = get_data();
                insert(data);
                break;
            case 2:
                data = get_data();
                root = delete(root, data);
                break;
            case 3:
                data = get_data();
                root = search(root, data);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                preorder(root);
                break;
            case 7:
                printf("\nProgram was terminated\n\n");
                exit(0);
            default:
                printf("\nInvalid Choice\n");
                break;
        }
        printf("\n__________\nDo you want to continue? ");
        fflush(stdin);
        scanf(" %c", &userActive);
    }
    return 0;
}
// creates a new node
struct node *create_node(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated !!!");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
// inserts the data in the BST
void insert(int data){
    struct node *new_node = create_node(data);
    if (new_node != NULL)
    {
        // if the root is empty then make a new node as the root node
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }
        struct node *temp = root;
        struct node *prev = NULL;
        // traverse through the BST to get the correct position for insertion
        while (temp != NULL){
            prev = temp;
            if (data > temp->data)
                temp = temp->right;
            else
                temp = temp->left;
        }
        // found the last node where the new node should insert
        if (data > prev->data)
            prev->right = new_node;
        else
            prev->left = new_node;
        printf("\n* node having data %d is inserted\n", data);
    }
}
// deletes the given key node from the BST
struct node *delete (struct node *root, int key){
    if (root == NULL)
    {
        printf("Tree is empty!");
        return 0;
    }
    if (key < root->data)
        root->left = delete (root->left, key);
    else if (key > root->data)
        root->right = delete (root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    }
    return root;
}
// searching of a key in bst
struct node *search(struct node *root, int key) {
	if(root == NULL)
        printf("\nElement not found!");
    else if (key < root -> data)
        root -> left=search(root->left, key);
    else if(key > root -> data)
        root -> right=search(root->right, key);
    else
        printf("\nElement found is: %d", root->data);
    return root;
}

// inorder traversal of the BST
void inorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// preorder traversal of the BST
void preorder(struct node *root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// postorder travsersal of the BST
void postorder(struct node *root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// getting data from the user
int get_data(){
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}