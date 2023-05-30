#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//to find the length incresing subquence in an array
int lis_algo(t_list *array)
{
    int n;
    int i;
    int j;
    int *d; //Dynamic array to store the LIS lengths
    t_list *current; //ptr to iterqte through the linked list
    t_list **p; // changed to an array of t_list pointers
    //Dynamic array of t_list pointers to store the predecessor nodes

    n = 0; //to store the number of the element in the linked list
    i = 0;
    j = 0;
    current = array;
    while(current != NULL)
    {
        n++;
        current = current->next;
    }
    d = (int *)malloc(n * sizeof(int));
    p = (t_list **) malloc(n * sizeof(t_list)); // allocate memory for p
    while(i < n)
    {
        //each element itself can be considered as a subsequence of length 1.
        d[i] = 1;
        p[i] = NULL; // Initialize each element of p to NULL
        i++;
    }
    /*loops iterate through the elements of the linked list 
    and compare each element with the previous elements.*/
    current = array;
    i = 1;
    while(i < n)
    {
        t_list *tmp = array;
        j = 0;
        while(j < n)
        {
            if(tmp->data < current->data && d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                p[i] = tmp;
            }
            tmp = tmp->next;
            j++;
        }
        current = current->next;
        i++;
    }
    int ans = d[0];
    i = 1;
    while(i < n)
    {
        if(ans < d[i])
            ans = d[i];//keep track of the max LIS len
        i++;
    }
    free(d);
    free(p);
    return (ans);

}

int main()
{
    t_list *head = NULL;
    t_list *current = NULL;
    t_list *node;
    int i = 0; 

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    while(i < n){
        node = (t_list*) malloc(sizeof(t_list));
        node->data = arr[i];
        node->next = NULL;
        if(head == NULL){
            head = node;
            current = node;
        }
        else{
            current->next = node;
            current = current->next;
        }
        i++;
    }
    lis_algo(head);
    printf("Length of lis is %d\n", lis_algo(head));
    current = head;
    while(current != NULL)
    {
        node = current;
        current = current->next;
        free(node);
    }
    
    return 0;
}