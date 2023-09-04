#include "../includes/structs.h"
#include "../includes/engine.h"

void	button(t_mlx *src, t_btn *props)
{
	int		i;
	int		j;

	i = 0;
	while (i <= props->width)
	{
		j = -1;
		while (++j <= props->height)
			mlx_put_pixel(src->img, props->x + i, props->y + j, props->color);	
		i++;
	}
}

void	mouse_event_listener(t_mlx *mlx, void (*hover_map)(t_mlx *, void *),void *props)
{
	int		pos_x;
	int		pos_y;
	
	pos_x = 0;
	pos_y = 0;
	mlx_get_mouse_pos(mlx->mlx, &pos_x, &pos_y);
	hover_map(mlx, props);
	printf("pos_x: %i | pos_y: %i \n", pos_x, pos_y);
}

void	render(void *data)
{
	t_mlx	*mlx;
	mlx = (t_mlx *)data;
	mouse_event_listener(mlx, &button,  &(t_btn){"Hello Btn", HEIGHT / 2, WIDTH / 2, 0xffffff, 0, 25, 45});
}

int main(int ac, char *av[])
{
	(void)av;
	t_mlx	engine;

	engine.height = HEIGHT;
	engine.width = WIDTH;
	if (ac < 2)
	{
		printf("No map found in args pls!\n");
		return (EXIT_FAILURE);
	}
	engine.mlx = mlx_init(engine.width, engine.height, TITLE, true);
	if (!engine.mlx)
		exit(EXIT_FAILURE);
	engine.img = mlx_new_image(engine.mlx, engine.width, engine.height);
	if (!engine.img || (mlx_image_to_window(engine.mlx, engine.img, 0, 0)) < 0)
		exit(EXIT_FAILURE);
	mlx_loop_hook(engine.mlx, &render, &engine);
	mlx_loop(engine.mlx);
	mlx_terminate(engine.mlx);
	return (EXIT_SUCCESS);
}
