#include "texture.h"

t_vector	get_constant_texture(const t_hit_rec *rec, t_vector ret)
{
	ret.x = rec->obj_ptr->red * ret.x;
	ret.y = rec->obj_ptr->green * ret.y;
	ret.z = rec->obj_ptr->blue * ret.z;
	return (ret);
}


t_vector	get_texture(const t_hit_rec *rec, t_vector ret)
{
	if (rec->obj_ptr->ambient == 0)
		return (get_constant_texture(rec, ret));
	else
		return (get_constant_texture(rec, ret));
}

void		set_texture(const t_env *env, t_img *img)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	t_object		*obj;


	elem = env->objects->head;
	while (elem)
	{
		next = elem->next;
		obj = ((t_object*)elem->data);
		obj->texture.ptr = mlx_xpm_file_to_image(img->mlx,
			obj->texture.file, &obj->texture.width, &obj->texture.height);
		if (obj->texture.ptr)
			obj->texture.buffer = (int*)mlx_get_data_addr(obj->texture.ptr,
				&(obj->texture.bpp), &(obj->texture.line_s),
				&(obj->texture.endian));
		elem = next;
	}
}