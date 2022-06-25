/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:04:44 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/25 19:41:20 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ************************************************************************** *
Create a new element

Input:
	- char *str : number from parsed file
	- unsigned int n : words for number from parsed file
Output:
	- t_dict *dict : address of the new dict element
* ************************************************************************** */
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

/* ************************************************************************** *
Append an element to the dictionary

Goes to the last element of the list and call dict_create_elem with the
provided parameters.

Input:
	- char *str : number from parsed file
	- unsigned int n : words for number from parsed file
Output:
	if (success)
		t_dict *current->next : address of the newly created element
	else (fail)
		void pointer
* ************************************************************************** */
t_dict *dict_append_elem(t_dict *dict, char *str, unsigned int n)
{
	t_dict *current;

	current = dict;
	while (current->next)
		current = current->next;
	current->next = dict_create_elem(str, n);
	if (!current->next)
		return (0);
	return (current->next);
}

/* ************************************************************************** *
Find the correct element in the dict

Input:
	t_dict *dict = first element of dictionary
	unsigned int to_find = number to find
Return:
	if found
	 - t_dict *current = address of the correct element
	else
	 - void pointer
* ************************************************************************** */
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

/* ************************************************************************** *
Sort the dictionary from smaller to bigger
Store the address of the n and words in a temp value and switch them.

Input:
	t_dict *dict = address of the first element
Return:
	Nothing
* ************************************************************************** */
void	dict_sort(t_dict *dict)
{
	t_dict			*current;
	unsigned int	tmp_n;
	char			*tmp_w;

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

/* ************************************************************************** *
Free all the dictionary
Input:
	- t_dict *dict : first element of the dict
Output:
	- Nothing
* ************************************************************************** */
void	dict_free(t_dict *current)
{
	t_dict	*previous;

	if (!current)
		return ;
	while (current->next)
	{
		previous = current;
		current = current->next;
		free(previous->words);
		free(previous);
	}
	//free(current->words);
	free(current);
}

/********************** DEBUG ***********************/
#include <stdio.h>
#ifdef __linux__
  #include <bsd/string.h>
#elif __APPLE__
  #include <string.h>
#endif

void debug_print_dict(t_dict *dict, char *str)
{
	t_dict			*current;

	current = dict;
	if (!current)
		return ;
	while (current->next)
	{
		printf("-------------%s--------------\n", str);
		printf("current->n: %u\ncurrent->words: %s\ncurrent->next: %p\n", current->n, current->words, current->next);
		current = current->next;
	}
	printf("-------------%s--------------\n", str);
	printf("current->n: %u\ncurrent->words: %s\ncurrent->next: %p\n", current->n, current->words, current->next);
}

void debug_print_element(t_dict *current, char *str)
{
	printf("-------------%s--------------\n", str);
	printf("current->n: %u\ncurrent->words: %s\ncurrent->next: %p\n", current->n, current->words, current->next);
}


int main(void)
{
	unsigned int n0 = 10;
	unsigned int n1 = 11;
	unsigned int n2 = 12;
	char *str0 = malloc(sizeof("dix"));
	char *str1 = malloc(sizeof("onze"));
	char *str2 = malloc(sizeof("douze"));
	
	t_dict *dict;
	t_dict *next;

	if (!str1 || !str1 || !str2)
		return (0);

	str0 = strcpy(str0, "dix");
	str1 = strcpy(str1, "onze");
	str2 = strcpy(str2, "douze");
	printf("str0: %s\n", str0);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);

	dict = dict_create_elem(str0, n0);
	next = dict;
	printf("dict->n: %u\ndict->words: %s\ndict->next: %p\n", dict->n, dict->words, dict->next);

	next = dict_append_elem(dict, str2, n2);
	next = dict_append_elem(next, str1, n1);
	debug_print_dict(dict, "Appened");

	dict_sort(dict);
	debug_print_dict(dict, "Sorted");

	debug_print_element(dict_find_nbr(dict, 12), "find");
	
	dict_free(dict);
	return (0);
}