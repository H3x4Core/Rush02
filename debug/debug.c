dict_from_file.c

#if 0
/*
int	main(void)
{
	t_dict	*dict;
	char	*filename;

	filename = "../dictionaries/wrong.dict";
	dict = dict_from_file(filename);
	dict_sort(dict);
	debug_print_dict(dict, "file to dict sorted");
	return (0);
}
*/
#endif

ft_atoi.c

/*
//gcc ft_atoi.c && ./a.out -234 13 +0 +123 -0 123.4 ++123 -+123 +-12 -13b23 -b12
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	ac -= 1;
	av += 1;
	for (int i = 0; i < ac; i++)
		printf("atoi:%d		ft_atoi:%lld\n", atoi(av[i]), ft_atoi(av[i]));
	// printf("%s:	%d", av[ac], ft_atoi("-1112wq32"));
	return (0);
}
*/

ft_strjoin.c

/*
int main(int argc, char **argv)
{
	// argc = 1;
	// char *foo = "some wierd string";
	char *foo = ft_strjoin(argc-1, argv+1, "/");
	printf("%s\n %d\n", foo, ft_strlen(foo));
	free (foo);
}
*/