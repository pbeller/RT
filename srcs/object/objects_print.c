#include "object.h"

static void			print_fn(void *elem)
{
	object_print((t_object *)elem);
}

void				objects_print(t_lst *objects)
{
	twl_lst_iter0(objects, print_fn);
}
