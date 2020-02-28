/* alperen inci
 * 18120205016
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
    Node *temp1;
    Node *temp2;
    temp1=&head;
    while(temp1->data < n->data){
		temp1=n->next;
	}
	temp2=temp1->prev;
	n->next = temp1;
	n->prev = temp2; 
	temp2->next=n;
	temp1->prev=n;
    return 0;
}

/* prints the list starting from head to tail */
void print_nodes(){
   Node *temp1 = &head;
	while(temp1 != NULL){
	
		printf("%d\n", temp1->data);
		temp1 = temp1->next;
	}
}

/* allocates a memory space for a Node, and assings data to its data
 * and returns the pointer for this location 
 */
Node *new_node(int data){
    
	Node *adres = (Node *)malloc(sizeof(Node));
	adres->data = data;
	return adres;
}



int main(){
    /* You should NOT change anything in this function */
    
    initialize_list();
    insert_node(new_node(5));
    insert_node(new_node(3));
    insert_node(new_node(6));
  
    print_nodes(); 
    
    Node *temp = head.next, *temp2;
    while(temp != NULL && temp != &head && temp != &tail){
        temp2 = temp;
        temp = temp->prev;
        free(temp2);
    }
    return 0;
}
