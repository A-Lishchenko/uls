#include "../inc/libmx.h"


void mx_push_back(t_list **list, void *data){
    if(*list == NULL){
      (*list) = mx_create_node(data);
      return;
   }
    t_list *temp = *list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    t_list *node = mx_create_node(data);
    temp->next = node;
}
