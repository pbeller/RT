#include "object.h"
#include <stdlib.h>

void				object_del(t_object *object)
{
	free(object->type);
	free(object->texture.file);
	free(object);
}
