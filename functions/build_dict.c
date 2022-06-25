#include "header.h"

/*
Create a new element
Input:
	n = number from parsed file
	str = words for number from parsed file
Output:
	address of the new dict element
*/
t_dict *dict_create_elem(char *str, unsigned int n)
{
	t_dict *dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (0);
	dict->n = n;
	dict->words = str;
	dict->next = 0;
	return (dict);
}

/*
Append an element to the dictionary
TODO
*/

/*
Find the correct element in the dict
Input:
	t_dict *dict = first element of dictionary
	unsigned int to_find = number to find
Return:
	if found
	 - t_dict *current = address of the correct element
	else
	 - void pointer
*/
t_dict *dict_find_nbr(t_dict *dict, unsigned int to_find)
{
	t_dict *current;
	current = dict;
	if (!dict)
		return (0);
	while (current->next)
	{
		if (current->n == to_find)
			return (current);
		current = current->next;
	}
	if (current->n == to_find)
		return (current);
	return (0);
}

/*
Sort the dictionary from smaller to bigger
Store the address of the n and words in a temp value and switch them.
Input:
	t_dict *dict = address of the first element
Return:
	Nothing
*/
void	dict_sort(t_dict *dict)
{
	t_dict	*current;
	void *tmp_n;
	void *tmp_w;

	current = dict;
	if (!current)
		return ;
	while (current->next)
	{
		if (current->n > current->next->n)
		{
			tmp_n = current->n;
			tmp_w = current->words;
			current->n = current->next->n;
			current->words = current->next->words;
			current->next->n = tmp_n;
			current->next->words = tmp_w;
			
			current = dict;
		}
		else
			current = current->next;
	}
}

#include <stdio.h>
int main(void)
{
	int n = 10;
	char *str = malloc(sizeof("dix"));
	if (!str)
		return (0);
	str = "dix";
	

}