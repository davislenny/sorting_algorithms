#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct listint_s - DOubly linked list node
 *
 * @n: Integer stored in thenode
 * @prev: Pointer to the previous element of the list
 * @next: POinter to the next element of the list
 */
typedef struct listint_s
{
	int n;
/*	const int n;*/
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *create_listint(const int *array, size_t size);
void swap(listint_t *n1, listint_t *n2);
void _swap(int *arr, size_t size, int *a, int *b);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
