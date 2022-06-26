# RUSH02

## To Do
- move `line_to_num_check` somewhere appropriated (currently in [dict_from_file.c](functions/dict_from_file.c))
- use `free_dict(dict)` everytime we leave the main.c
- free str returned by read_file
- fix overflow issue when arg is negative
- check validity of the dict given
- return correct error message
- norme the fuck out of this
- free them all 

#MALLOC FREE LIST
DONE : get_value_from_entry(void)
in the same funciton.

DONE : dict_create_elem(char *str, unsigned int n) 
in the dict freeing func. 

NO ? : ft_strjoin(int size, char **strs, char *sep)
we can just remove this file? i dont think it's used

NO ? : humanize(unsigned int    *array, t_dict *dict_start)
idk where this is used. 

DONE : line_to_words(char *str)
yes in the dict freeing func.

NO ? : read_file(char *filename)
not sure

## Issues ?
Never heard of
