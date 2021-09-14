#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <assert.h>

struct data {
    int value;
    struct data * next;
};

struct data * tail_linked_list(struct data *head_linked_list)
{
    struct data *ptr = head_linked_list;
    while (ptr->next != NULL) ptr = ptr->next;
//    printf("== Tail value = %d\n", ptr->value);

    return ptr;
}

void insert_element_tail(struct data *head_linked_list, int val)
{
    struct data *tail = tail_linked_list(head_linked_list);
    struct data *tmp = new struct data;
    tail->next = tmp;
    tmp->value = val;
    tmp->next = NULL;
}

void insert_element(struct data *head_linked_list, int val_before_insertion, int val_to_insert)
{
    //Create a container to store the to-be-inserted value;
    struct data *tmp = new struct data;
    tmp -> value = val_to_insert;

    // Search through the linked list to find "val_before_insertion" or
    // if we didn't find it, it returns the tail
    struct data *ptr = head_linked_list;
    while ((ptr->value != val_before_insertion) && (ptr->next != NULL)) ptr = ptr->next;

    //Let the created container store the next of "value_before_insertion"
    tmp->next = ptr->next;

    //Let the value_before_insertion's next store the created container
    ptr->next = tmp;

}

void delete_value(struct data *head_linked_list, int val){
    struct data *ptr = head_linked_list;
    struct data *ptr_prior = NULL;
    while (ptr->value != val){
        ptr_prior->next = ptr;
        ptr = ptr->next;
        if(ptr->value == val){
            ptr_prior->next = ptr->next;
        }
    }

}

void print_linked_list(struct data *head_linked_list)
{
    struct data *ptr = head_linked_list;
    while (ptr != NULL)
    {
        std::cout<<ptr->value<<" --> ";
        ptr = ptr->next;
    }
    std::cout<<"NULL\n";
}

int main(){
    struct data *my_linked_list = new struct data;
    my_linked_list -> next = NULL;
    my_linked_list -> value = 5;

    //build the linked list;
    //insert_element_tail(my_linked_list, 5);
    insert_element_tail(my_linked_list, 2);
    insert_element_tail(my_linked_list, 3);

    print_linked_list(my_linked_list);

    insert_element(my_linked_list, 2, -1);

    print_linked_list(my_linked_list);
    return 0;
}
