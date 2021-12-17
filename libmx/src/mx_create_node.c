#include "../inc/libmx.h"

t_list *mx_create_node(void *data){
    t_list *Node = malloc(16);
    Node->next = NULL;
    Node->data = data;
    return Node;
}

