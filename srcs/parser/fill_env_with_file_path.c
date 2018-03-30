#include "parser.h"
#include "twl_arr.h"
#include "twl_stdio.h"
#include "twl_xstdio.h"
#include "twl_xstdlib.h"
#include "twl_dict.h"
#include "twl_lst.h"
#include "twl_xstring.h"
#include <stdlib.h>


void				free_dict_wrapper(void *elem_)
{
	t_dict			*elem;

	elem = (t_dict *)elem_;
	twl_dict_del(elem, free);
}

int					is_valid_type(char *type)
{
	char			**types;
	void			*find;

	types = twl_strsplit(VALIDE_TYPE, ',');
	find = twl_arr_find(types, twl_strequ_void, type);
	twl_arr_del(types, free);
	if (find)
		return (1);
	return (0);
}

char				*clean_char(char *str, char *match_chars)
{
	char 			*new_str;
	char			*ret_str;
	int				i;

	new_str = twl_malloc_x0(twl_strlen(str) + 1);
	i = 0;
	while (*str)
	{
		if (!twl_strchr(match_chars, *str))
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

void				populate_env(void *elem, void *ctx)
{
	char			*type;

	type = twl_dict_get((t_dict *)elem, "type");
	if (!is_valid_type(type))
		return ;
	if (twl_strcmp(type, "camera") == 0)
		build_camera_from_dict(((t_env *)ctx)->camera, (t_dict *)elem);
	else if (twl_strcmp(type, "light") == 0)
		add_light_to_list_from_dict(((t_env *)ctx)->lights, (t_dict *)elem);
	else
		add_object_to_list_from_dict(((t_env *)ctx)->objects, (t_dict *)elem);
}

void				create_dict_entry(void *elem, void *ctx)
{
	char 			*str;
	char 			**split;
	t_dict 			*dict;

	str = (char *)elem;
	dict = (t_dict *)ctx;
	split = twl_strsplit(str, ':');
	if (twl_arr_len(split) == 2)
		twl_dict_add(dict, split[0], twl_strdup(split[1]));
	twl_arr_del(split, free);
}

void				parse_fn(void *elem, void *ctx)
{
	char 			*str;
	char			**split;
	t_dict			*dict;

	dict = twl_dict_new();
	str = clean_char((char *)elem, "{}[] \t\n");
	split = twl_strsplit(str, ',');
	free(str);
	twl_arr_iter(split, create_dict_entry, dict);
	twl_arr_del(split, free);
	if (twl_dict_len(dict) < 1)
		return;
	twl_lst_push_back((t_lst *)ctx, dict);
}

void				fill_env_with_file_path(t_env *env, char *filepath)
{
	char			*json;
	char			**split;
	t_lst			*lst;

	json = twl_file_to_str(filepath);
	if (json == NULL)
	{
		twl_dprintf(2, "%s file does not exist\n", filepath);
		env_del(env);
		exit(1);
	}
	lst = twl_lst_new();
	split = twl_strsplit_mul_trim_chars(json, "{", "[]");
	free(json);
	twl_arr_iter(split, parse_fn, lst);
	twl_arr_del(split, free);
	twl_lst_iter(lst, populate_env, env);
	twl_lst_del(lst, free_dict_wrapper);
}
