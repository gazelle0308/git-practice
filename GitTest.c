#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_List{

    int data;
    struct Linked_List* R_Node;
    struct Linked_List* L_Node;

} Linked_List;

void main() {

    Linked_List* head = NULL;

    head = insert_node(10, NULL, NULL);
    head = insert_node(20, NULL, head);
    head = insert_node(30, NULL, head);

    printf("Hello, Git!\n");

    return;
}

Linked_List* insert_node(int data, Linked_List* R_Node, Linked_List* L_Node) {

    Linked_List* new_node = (Linked_List*)malloc(sizeof(Linked_List));
    
    if (new_node == NULL) {
    
        printf("Memory allocation failed\n");
        return NULL;
    
    }

    new_node->data = data;
    if (R_Node != NULL) {
        new_node->R_Node = R_Node;
        R_Node->L_Node = new_node;
    } else {
        new_node->R_Node = NULL;
    }
    if (L_Node != NULL) {
        new_node->L_Node = L_Node;
        L_Node->R_Node = new_node;
    } else {
        new_node->L_Node = NULL;
    }
    return new_node;

}

Linked_List* delete_node(Linked_List* node) {

    if (node == NULL) {
        return NULL;
    }

    Linked_List* next_node = node->R_Node;
    Linked_List* prev_node = node->L_Node;

    if (prev_node != NULL) {
        prev_node->R_Node = next_node;
    }
    if (next_node != NULL) {
        next_node->L_Node = prev_node;
    }
    free(node);
    return next_node;

}
