#include "object.h"

void				objects_del(t_lst *objects)
{
	twl_lst_del(objects, object_del);
}
