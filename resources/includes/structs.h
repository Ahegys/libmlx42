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

typedef struct s_btn
{
	char	*name;
	int		x;
	int		y;
	int 	color;
	int		background;
	int		width;
	int		height;
}			t_btn;

#endif // !STRUCTS_H
