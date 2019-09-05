#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int element;
    struct LinkedList *next;
};

typedef struct LinkedList *node;

/**
	function which printis the list from first element to last element 
**/
void print_list(node pos) {
    node temp = pos;
    while(temp != NULL){
        printf("%d ", temp->element);
        temp = temp->next;
    }
	printf("\n");
}

/**
	function which inserts node after the given position
**/
void insert_node(node pos, int an_element) {
    node a_node = (node)malloc(sizeof(struct LinkedList));
    a_node->element = an_element;
    a_node->next = pos->next;
    pos->next = a_node;
}

/**
	function which deletes node after the given position
**/
void delete_node(node util_node) {
    node a_node = (node)malloc(sizeof(struct LinkedList));
    a_node->next = util_node->next;
    util_node->next = util_node->next->next;
    free(a_node); 
}

int main() {
    node head = (node)malloc(sizeof(struct LinkedList));
    head->next = NULL;		//reference to the first element of the list

    insert_node(head, 100);
	insert_node(head, 55);
    insert_node(head, 10);
    insert_node(head->next, 45);
	print_list(head->next);
    delete_node(head->next);
    print_list(head->next);
    

    return 0;
}