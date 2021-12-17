#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data){
   if(*list == NULL){
      (*list) = mx_create_node(data);
      return;
   }
   t_list *head = mx_create_node(data);
   head->next = *list;
   *list = head;
}

