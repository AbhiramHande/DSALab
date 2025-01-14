#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Used to define the maximum length of the line in the text file
#define LENGTH_OF_LINE 50

//The various structures used in the program are defined below

//This is the node of the linked list
//Each node stores an integer value and the pointer to the next node
struct list_node{
    int value;
    struct list_node* next;
};

//This is the head of the linked list (that will be stored in the nodes of a tree)
//Each header stores an the number of nodes in it and the pointer to the first node in the list
struct list_head{
    int count;
    struct list_node* head;
};

//This is the node of the binary search tree
//Each node stores a pointer to the list and the (two) pointers to its children
struct tree_node{
    struct tree_node* right;
    struct tree_node* left;
    struct list_head* list;
};

//This is the header of the binary seach tree
//Each header stores the pointer to its root
struct tree_head{
    struct tree_node* root;
};

typedef struct list_node list_node;
typedef struct list_head list_head;
typedef struct tree_node tree_node;
typedef struct tree_head tree;

typedef list_node* node;
typedef list_head* list;
typedef tree_node* leaf; //Used for convinience - NOT intended to mean the leaf of the BST
typedef tree* bst;

//Following are some functions to create the necessary structures
//All the structers are created in heap so thier respective free functions are written in line TOFILL

//Creates a new linked list with no nodes inside of it and returns its pointer.
list create_new_list(){
    list l = (list)malloc(sizeof(list_head));
    l->count = 0;
    l->head = NULL;
    return l;
}

//Creates a new node of a linked list and returns its pointer.
//Its value is assigned to the integer passed into the function.
//It points to nothing (NULL).
node create_list_node(int data){
    node n = (node)malloc(sizeof(list_node));
    n->value = data;
    n->next = NULL;
    return n;
}

//Creates a new node of a binary search tree and returns its pointer.
//Each (tree) node stores a pointer to a linked list that is passed into the function
//The children of the (tree) node are initialized to NULL
leaf create_tree_node(list l){
    leaf n = (leaf)malloc(sizeof(tree_node));
    n->list = l;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//Creates a new binary seach tree and returns a pointer to it
//It's root is initialized to NULL
bst create_tree(){
    bst t = (bst)malloc(sizeof(tree));
    t->root = NULL;
}

//Implementing insert at end of the linked list
void insert_into_list(list l, node n){
    node head = l->head;

    //Incase the linked list is empty
    if(head == NULL){
        l->head = n;
        n->next = NULL;
        l->count++;
        return;
    }
    
    while(head->next != NULL){
        head = head->next;
    }
    head->next = n;
    n->next = NULL;
    l->count++;
    return;

}

//Takes a string of space separated numbers as its argument
//Each number in the string is made into a node and added to the list (at the end to preserve its original order)
list create_list(char* string){
    list l = create_new_list();
    char* token;
    int value;
    token = strtok(string, " ");
     
    while(token != NULL && isdigit(token[0])){
        int value = atoi(token);
        node n = create_list_node(value);
        insert_into_list(l, n);
        token = strtok(NULL, " ");
    }

    return l;
}

//Inserts a list into the binary search tree based on its key
void insert_into_tree(bst t, list l){
    leaf n = create_tree_node(l);
    //The key in this case is the value of first node of the linked list
    int key = n->list->head->value;

    //Incase the tree has no nodes or leafs in it
    if (t->root == NULL){
        t->root = n;
        return;
    }

    leaf ptr = t->root;
    //Iteratively navigates to the correct place to insert the (tree) node
    while (ptr != NULL){
        //Checks if the key of the (tree) node to be added is lesser than the key of the current (tree) node
        if (key < ptr->list->head->value){
            //Inserts it to its left if the (tree) node has no children on the left
            if (ptr->left == NULL){
                ptr->left = n;
                return;
            }
            //Else moves to left and repeats checking
            ptr = ptr->left;
        }

        //If the key of the (tree) node to be added is greater than or equal to the current (tree) node
        else{
            //Inserts it to its right if the (tree) node has no children on the right
            if (ptr->right == NULL){
                ptr->right = n;
                return;
            }
            //Else moves to right and repeats checking
            ptr = ptr->right;
        }
    }
}

//Takes a file and makes the associated binary tree (as mentioned in the question paper)
bst readData(FILE* fp){
    bst t = create_tree();
    int size;
    char line[LENGTH_OF_LINE];
    fgets(line, LENGTH_OF_LINE, fp);
    size = atoi(line);

    for(int i = 0; i < size; i++){
        fgets(line, LENGTH_OF_LINE, fp);
        list l = create_list(line);
        insert_into_tree(t, l);
    }

    return t;
}

//Following are some functions to print the necessary structures (on console or in a file)

//Takes a pointer to linked list as an argument
//Prints values of the nodes in the linked list (space separated) onto the terminal
//Mainly used for debugging (CAN BE IGNORED)
void print_linked_list(list l){
    node ptr = l->head;
    // printf("%d \t", l->count); //For debugging
    while(ptr != NULL){
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

//Recursively prints the linked list stored in the nodes of the binary search tree
//Uses in order traversal for printing onto the terminal
//Mainly used for debugging (CAN BE IGNORED)
void in_order_terminal(leaf n){
    //base case
    if(n == NULL)
        return;
    
    //recursive call and print 
    in_order_terminal(n->left);
    print_linked_list(n->list);
    in_order_terminal(n->right);
    return;
}

//Wrapper function for in order traversal and printing on console
//Mainly used for debugging (CAN BE IGNORED)
void print_in_order(bst t){
    in_order_terminal(t->root);
}

//Takes a pointer to linked list and the pointer to the file it must print it in as an argument
//Prints values of the nodes in the linked list (space separated) onto the file 
void fprint_linked_list(list l, FILE* fp){
    node ptr = l->head;
    // printf("%d \t", l->count); //For debugging
    while(ptr != NULL){
        fprintf(fp, "%d ", ptr->value);
        ptr = ptr->next;
    }
    fprintf(fp, "\n");
}

//Recursively prints the linked list stored in the nodes of the binary search tree
//Uses in order traversal for printing (into the given file)
void in_order_file(leaf n, FILE* fp){
    //base case
    if(n == NULL)
        return;
    
    //recursive call and print 
    in_order_file(n->left, fp);
    fprint_linked_list(n->list, fp);
    in_order_file(n->right, fp);
    return;
}

//Wrapper function for in order traversal and printing into file
void traverse(bst t, FILE* fp){
    in_order_file(t->root, fp);
}
//Following are some functions to sort (as asked in question)
//Some helper functions are also defined here

void insert_in_order(node n){
    if(n== NULL)
        return;
    
    while(n->next != NULL && n->value > n->next->value){
        int temp = n->value;
        n->value = n->next->value;
        n->next->value = temp;
        n = n->next;
    }
    return;
}

//Recursively sorts the list from  the end
void insertion_sort(node n){
    if(n == NULL)
        return;
    
    insertion_sort(n->next);
    insert_in_order(n);
}

//Sorts the linked list as asked in the question paper using insertion sort
void sort_list(list l){
    //Removes the first node of the linked list (as it must not be sorted)
    node head = l->head;
    l->head = head->next;
    head->next = NULL;
    l->count--; //Although unnecessary done to make it robust

    //Sort the remaining part of the linked list (using insertion sort)
    insertion_sort(l->head);

    //Reattaches the first node of the linked list
    head->next = l->head;
    l->head = head;
    l->count++;

    return;
}

//Recursively sorts the linked list of itself and all descendents
void sort_subtree(leaf n){
    if(n == NULL)
        return;
    
    sort_subtree(n->left);
    sort_subtree(n->right);
    sort_list(n->list);
    return;
}

//Wrapper function that calls the recursive sort on the tree
void sortLists(bst t){
    sort_subtree(t->root);
}

//Following are some functions to free the dynamically allocated memory of the necessary structures

//Frees the node and all subsequent nodes
void free_list_node(node n){
    if(n == NULL)
        return;
    free_list_node(n->next);
    free(n);
}

//Frees all the nodes in the list and the list itself
void free_list(list l){
    free_list_node(l->head);
    free(l);    
    return;
}

//Frees the node and the linked list of itself and all descendents
void free_tree_node(leaf n){
    if(n == NULL)
        return;
    free_tree_node(n->left);
    free_tree_node(n->right);
    free_list(n->list);
    free(n);
    return;
}

//Frees all the nodes in the tree and the tree itself
void free_tree(bst t){
    free_tree_node(t->root);
    free(t);
}


int main(){
    char* input_file_name = "numbers_20.txt";
    FILE* inp_fp = fopen(input_file_name, "r");
    FILE* out_fp = fopen("file2.txt", "w");
    if(inp_fp == NULL){
        printf("File doesn't exist. Pls verify");
        return 0;
    }

    bst t = readData(inp_fp);
    sortLists(t);
    traverse(t, out_fp);

    free(t);
    fclose(inp_fp);
    fclose(out_fp);
    return 0;
}