#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail of the linked list
 * 
 * @param head Pointer to the first node of the linked list
 * @return The tail of the linked list. If the list is empty (NULL), returns NULL
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL)
    {
        return NULL;
    }

    while(head->next != NULL)
    {
        head = head->next;
    }
    return head;
    
}

/**
 * Counts and returns the number of nodes in the linked list
 * 
 * @param head Pointer to the first node of the linked list
 * @return The number of nodes in the linked list. If the list is empty (NULL), returns 0
 */
int ll_size(struct ll_node *head) {
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
  
}

/**
 * Finds and returns the first node with the specified value in the linked list
 * 
 * @param head Pointer to the first node of the linked list
 * @param value The value to search for in the linked list
 * @return Pointer to the first node with the specified value. If not found, returns NULL
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    while(head != NULL)
    {
        if(head->data == value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
   

/**
 * Converts the linked list to an array of integers
 * 
 * @param head Pointer to the first node of the linked list
 * @return Pointer to the array of integers. The caller is responsible for freeing the allocated memory
 */
int *ll_toarray(struct ll_node *head) {
   int size = ll_size(head);
   if(size == 0) return NULL;

   int *arr = malloc(sizeof(int) * size);
   if(arr == NULL) return NULL;

   struct ll_node *curr = head;
   for(int i = 0; i < size; i++)
   {
         arr[i] = curr->data;
         curr = curr->next;
   }
    return arr;
}

/**
 * Creates a new linked list node with the given data
 * 
 * @param data The data to be stored in the new node
 * @return Pointer to the newly created node
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
   if(node == NULL) return NULL;

   node->data = data;
   node->next = NULL;
   return node;
}

/**
 * Frees all nodes in the linked list
 * 
 * @param head Pointer to the first node of the linked list
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Appends a new node with the given data to the end of the linked list
 * 
 * @param head Pointer to the first node of the linked list
 * @param data The data to be stored in the new node
 */
void ll_append(struct ll_node *head, int data) {
    if(head == NULL) return;

    struct ll_node *tail = ll_tail(head);
    struct ll_node *new_node = ll_create(data);

    if(new_node != NULL)
    {
        tail->next = new_node;
    }
 
}

/**
 * Creates a linked list from an array of integers
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if(data == NULL || len <= 0) return NULL;

    struct ll_node *head = ll_create(data[0]);
    if(head == NULL) return NULL;

    struct ll_node *tail = head;

    for(int i = 1; i < len; i++)
    {
        struct ll_node *new_node = ll_create(data[i]);
        if(new_node == NULL)
        {
            ll_destroy(head);
            return NULL;
        }
        tail->next = new_node;
        tail = new_node;
    }
    return head;

}

/**
 * Removes the first node with the specified value from the linked list
 * 
 * @param head Pointer to the first node of the linked list
 * @param value The value of the node to be removed
 * @return Pointer to the head of the modified linked list
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if(head == NULL) return NULL;

    if(head->data == value)
    {
        struct ll_node *new_head = head->next;
        free(head);
        return new_head;
    }

    struct ll_node *curr = head;
    while(curr->next != NULL && curr->next->data != value)
    {
        curr = curr->next;
    }

    if(curr-> next != NULL)
    {
        struct ll_node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}

