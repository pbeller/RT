#include "parser.h"
#include "twl_arr.h"
#include "twl_stdio.h"
#include "twl_xstdio.h"
#include "twl_xstdlib.h"
#include "twl_dict.h"
#include "twl_lst.h"
#include "twl_xstring.h"
#include <stdlib.h>


char				*clean_char(char *str, char *match_char)
{
	char 			*new_str;
	char			*ret_str;
	int				i;

	new_str = twl_malloc_x0(twl_strlen(str) + 1);
	i = 0;
	while (*str)
	{
		if (!twl_strchr(match_char, *str))
		{
			new_str[i] = *str;
			i++;
		}
		str++;
	}
	ret_str = twl_strdup(new_str);
	free(new_str);
	return (ret_str);
}


void				print_dict_fn(char *key, void *data, void *ctx)
{
	twl_printf("key: %s - value %s\n", key, (char *)data);
	(void)ctx;
}

void				print_fn(void *elem, void *ctx)
{
	twl_printf("%s\n", (char *)elem);
	twl_printf("==========\n");
	(void)ctx;
}

void				populate_env(void *elem, void *ctx)
{
	char			*type;
	type = twl_dict_get((t_dict *)elem, "type");
	if (twl_strcmp(type, "camera") == 0)
		build_camera_from_dict(((t_env *)ctx)->camera, (t_dict *)elem);
	else if (twl_strcmp(type, "light") == 0)
		add_light_to_list_from_dict(((t_env *)ctx)->lights, (t_dict *)elem);
	else
		add_object_to_list_from_dict(((t_env *)ctx)->objects, (t_dict *)elem);
}

void				create_dict_entry(void *elem, void *ctx)
{
	char *str = (char *)elem;
	char **split;
	t_dict *dict = (t_dict *)ctx;

	split = twl_strsplit(str, ':');
	twl_dict_add(dict, split[0], split[1]);
}

void				print_lst_fn(void *elem)
{
	twl_dict_iter((t_dict *)elem, print_dict_fn, NULL);
	twl_printf("======\n");
}

void				parse_fn(void *elem, void *ctx)
{
	char 			*str;
	char			**split;
	t_dict			*dict;

	dict = twl_dict_new();
	str = clean_char((char *)elem, "{}[] \t\n");
	split = twl_strsplit(str, ',');
	twl_arr_iter(split, create_dict_entry, dict);
	if (twl_dict_len(dict) < 1)
		return;
	twl_lst_push_back((t_lst *)ctx, dict);
}

void				fill_env_with_file_path(t_env *env, char *filepath)
{
	char			*json;
	char			**split;
	t_lst			*lst;

	lst = twl_lst_new();
	json = twl_file_to_str(filepath);
	split = twl_strsplit_mul_trim_chars(json, "{", "[]");
	twl_arr_iter(split, parse_fn, lst);
	twl_lst_iter(lst, populate_env, env);
}
