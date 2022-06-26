/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:01:50 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 13:55:54 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/********************** DEBUG ***********************/
#include "header.h"
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

t_dict *hardcoded_dict(void)
{
	t_dict *dict;
	t_dict *next;
	char **str = malloc(sizeof(char *) * 32);
	unsigned int n[32];

	str[0] = malloc(sizeof("zero"));
	str[1] = malloc(sizeof("one"));
	str[2] = malloc(sizeof("two"));
	str[3] = malloc(sizeof("three"));
	str[4] = malloc(sizeof("four"));
	str[5] = malloc(sizeof("five"));
	str[6] = malloc(sizeof("six"));
	str[7] = malloc(sizeof("seven"));
	str[8] = malloc(sizeof("eight"));
	str[9] = malloc(sizeof("nine"));
	str[10] = malloc(sizeof("ten"));
	str[11] = malloc(sizeof("eleven"));
	str[12] = malloc(sizeof("twelve"));
	str[13] = malloc(sizeof("thirteen"));
	str[14] = malloc(sizeof("fourteen"));
	str[15] = malloc(sizeof("fifteen"));
	str[16] = malloc(sizeof("sixteen"));
	str[17] = malloc(sizeof("seventeen"));
	str[18] = malloc(sizeof("eighteen"));
	str[19] = malloc(sizeof("nineteen"));
	str[20] = malloc(sizeof("twenty"));
	str[21] = malloc(sizeof("thirty"));
	str[22] = malloc(sizeof("forty"));
	str[23] = malloc(sizeof("fifty"));
	str[24] = malloc(sizeof("sixty"));
	str[24] = malloc(sizeof("seventy"));
	str[26] = malloc(sizeof("eighty"));
	str[27] = malloc(sizeof("ninety"));
	str[28] = malloc(sizeof("hundred"));
	str[29] = malloc(sizeof("thousand"));
	str[30] = malloc(sizeof("million"));
	str[31] = malloc(sizeof("billion"));

	str[0] =  strcpy(str[0],"zero");
	str[1] =  strcpy(str[1],"one");
	str[2] =  strcpy(str[2],"two");
	str[3] =  strcpy(str[3],"three");
	str[4] =  strcpy(str[4],"four");
	str[5] =  strcpy(str[5],"five");
	str[6] =  strcpy(str[6],"six");
	str[7] =  strcpy(str[7],"seven");
	str[8] =  strcpy(str[8],"eight");
	str[9] =  strcpy(str[9],"nine");
	str[10] =  strcpy(str[10],"ten");
	str[11] =  strcpy(str[11],"eleven");
	str[12] =  strcpy(str[12],"twelve");
	str[13] =  strcpy(str[13],"thirteen");
	str[14] =  strcpy(str[14],"fourteen");
	str[15] =  strcpy(str[15],"fifteen");
	str[16] =  strcpy(str[16],"sixteen");
	str[17] =  strcpy(str[17],"seventeen");
	str[18] =  strcpy(str[18],"eighteen");
	str[19] =  strcpy(str[19],"nineteen");
	str[20] =  strcpy(str[20],"twenty");
	str[21] =  strcpy(str[21],"thirty");
	str[22] =  strcpy(str[22],"forty");
	str[23] =  strcpy(str[23],"fifty");
	str[24] =  strcpy(str[24],"sixty");
	str[24] =  strcpy(str[24],"seventy");
	str[26] =  strcpy(str[26],"eighty");
	str[27] =  strcpy(str[27],"ninety");
	str[28] =  strcpy(str[28],"hundred");
	str[29] =  strcpy(str[29],"thousand");
	str[30] =  strcpy(str[30],"million");
	str[31] =  strcpy(str[31],"billion");

	n[0] = 0;
	n[1] = 1;
	n[2] = 2;
	n[3] = 3;
	n[4] = 4;
	n[5] = 5;
	n[6] = 6;
	n[7] = 7;
	n[8] = 8;
	n[9] = 9;
	n[10] = 10;
	n[11] = 11;
	n[12] = 12;
	n[13] = 13;
	n[14] = 14;
	n[15] = 15;
	n[16] = 16;
	n[17] = 17;
	n[18] = 18;
	n[19] = 19;
	n[20] = 20;
	n[21] = 30;
	n[22] = 40;
	n[23] = 50;
	n[24] = 60;
	n[24] = 70;
	n[26] = 80;
	n[27] = 90;
	n[28] = 100;
	n[29] = 1000;
	n[30] = 1000000;
	n[31] = 1000000000;

	dict = dict_create_elem(str[0], n[0]);

	next = dict;
	for (int i = 1; i < 32; i++)
	{
		next = dict_append_elem(next, str[i], n[i]);
	}
	return (dict);
}

#if 0
int main(void)
{
	t_dict *dict;
	dict = hardcoded_dict();
	debug_print_dict(dict, "full");
	return (0);
}
#endif


#if 0
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
#endif