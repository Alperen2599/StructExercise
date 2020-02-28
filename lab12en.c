/* 
 * lab12en.c
 * sorted doubly linked list.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node{
    int data;
    struct node *next;  /* address of the next element      */
    struct node *prev;  /* address of the previous element  */
} Node;

Node head, tail;        /* head and tail of the sorted list */   

/* initializes list */
int initialize_list(){
    /* You should NOT change anything in this function */
    
    /* head of the list */
    head.data = INT_MIN;
    head.next= &tail;
    head.prev= NULL;
    
    /* tail of the list */
    tail.data = INT_MAX;
    tail.next = NULL;
    tail.prev = &head; 
    return 1; 
}

/*
 * inserts a node to the right place in the sorted list.
 */
int insert_node (Node *n){
    /*TODO: To insert the node n to the list, 
     * first we need to find the right location for the node: 
     * 1- declare two temp pointers: say temp1 and temp2
     * 2- Assign the address of head to temp1
     * 3- Using a while loop, as long as temp1's data is less than n's data,
     * assign temp1's next member to temp1.
     * After the while loop temp1 holds the address of the first node
     *  which is greater than n. 
     * 4- Assign the address of  temp1's previous node to temp2 pointer
     * We insert n between temp2 and temp1:
     * 5- Assign temp1 as the next node of n
     * 6- Assign temp2 as the previous node of n
     * 7- Assign n to temp2's next
     * 8- Assign n to temp1's prev
     */ 

    return 0;
}

/* prints the list starting from head to tail */
void print_nodes(){
    /* TODO: print all the elements. 
     * Note: there is a similar example in lec13.pdf, 
     * which prints students' names.
     */
}


/* allocates a memory space for a Node, and assings data to its data
 * and returns the pointer for this location 
 */
Node *new_node(int data){
    /* TODO: declare a node pointer. using malloc function, 
     * allocate a memory space for a node type variable, 
     * assign the address to the pointer you have declared.
     * Make data-member of the pointed node equal to data.
     * return the pointer.
     */ 
}


int main(){
    /* You should NOT change anything in this function */
    
    initialize_list();
    insert_node(new_node(5));
    insert_node(new_node(3));
    insert_node(new_node(6));
  
    print_nodes(); /* ouput should be -INT_MIN 3 5 6 INT_MAX*/
    
    /* 
     * as a good programming practice, 
     * nontheless, we free all the dynamic memory. */
    Node *temp = head.next, *temp2;
    while(temp != NULL && temp != &head && temp != &tail){
        temp2 = temp;
        temp = temp->prev;
        free(temp2);
    }
    return 0;
}
