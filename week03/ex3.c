#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node * next;
} LinkedNode;

void print_list(struct Node * head){
  if(head -> next == NULL){
    printf("List in empty\n");
    return;
  }
  head = head -> next;
  while (head != NULL) {
    printf("%d ", head -> data);
    head = head -> next;
  }
  printf("\n");
}

void insert_node(struct Node * head, int data){
    LinkedNode * new_node = NULL;
    new_node = (LinkedNode*)malloc(sizeof(struct Node));
    new_node -> data = data;
    while (head -> next != NULL) {
      head = head -> next;
    }
    head -> next = new_node;
    new_node -> next = NULL;
}

void delete_node(struct Node * head){
  if(head -> next == NULL){
    return;
  }
  else{
    while (head -> next -> next != NULL) {
      head = head -> next;
    }
    free(head -> next -> next);
    free(head -> next);
    head -> next = NULL;
  }
}

int main(){
  LinkedNode * head = NULL;
  head = (LinkedNode*)malloc(sizeof(struct Node));
  head -> next = NULL;
  printf("Empty linked list created\n");
  printf("Pushing data..\n");
  insert_node(head, 3);
  insert_node(head, 5);
  insert_node(head, 7);
  insert_node(head, 12);
  insert_node(head, 123);
  printf("Data in list: \n");
  print_list(head);
  printf("Deleting two last nodes..\n");
  delete_node(head);
  delete_node(head);
  printf("Data in list: \n");
  print_list(head);
  printf("Deleting three last nodes..\n");
  delete_node(head);
  delete_node(head);
  delete_node(head);
  printf("Data in list: \n");
  print_list(head);
  return 0;
}
