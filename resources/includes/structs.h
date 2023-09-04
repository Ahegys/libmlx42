#ifndef STRUCTS_H
# define STRUCTS_H

#include "../../MLX42/include/MLX42/MLX42.h"

typedef struct s_mlx
{
	void		*win;
	void		*ctx;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
}				t_mlx;

typedef struct s_effects
{
	int	color;
	int	size;
	int	border;
}				t_effects;

typedef struct s_props
{
	const char	*name;
	int			x;
	int			y;
	int 		color;
	int			width;
	int			height;
	int			is_hover;
	t_effects	hover;
	int			active_hover;
}			t_props;

typedef struct	s_event
{
	void	(*callback)(t_mlx *, void *);
	t_props	*props;
}				t_event;

#endif // !STRUCTS_H
