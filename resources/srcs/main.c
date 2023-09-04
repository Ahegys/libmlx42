#include "../includes/structs.h"
#include "../includes/engine.h"

void	button(t_mlx *src, void	*get)
{
	int		i;
	int		j;
	t_props	*props;
	mlx_image_t		*img;
	int			color;

	props = (t_props *)get;
	color = props->color;
	i = 0;
	if (props->is_hover == TRUE)
		color = props->hover.color;	
	while (i <= props->width)
	{
		j = -1;
		while (++j <= props->height)
			mlx_put_pixel(src->img, props->x + i, props->y + j, color);	
		i++;
	}
	img = mlx_put_string(src->mlx, props->name, props->x + props->width / 2, props->y + props->height / 2);
}

void	mouse_event_listener(t_mlx *mlx, t_event *event)
{
	int		pos_x;
	int		pos_y;

	pos_x = 0;
	pos_y = 0;
	mlx_get_mouse_pos(mlx->mlx, &pos_x, &pos_y);
   	if (pos_x >= event->props->x && pos_x <= event->props->x + event->props->width &&
        pos_y >= event->props->y && pos_y <= event->props->y + event->props->height)
        event->props->is_hover = TRUE;
    else
        event->props->is_hover = FALSE;

    if (event->props->is_hover)
    {
    	if (mlx_is_mouse_down(mlx->mlx, MLX_MOUSE_BUTTON_LEFT))
    		printf("Mouse click in area button!\n");
    	printf("mouse in button area!\n");
    }
    else
	{
        printf("pos_x: %i | pos_y: %i \n", pos_x, pos_y);
    }
    event->callback(mlx, event->props);
}

void	render(void *data)
{
	t_mlx	*mlx;
	mlx = (t_mlx *)data;
	t_event	event;
	t_effects effect;

	effect.color = 0xaaaaaa;
	event.props = &(t_props){"Hello Btn", HEIGHT / 2, WIDTH / 2, 0xffffff, 60, 45, 0, effect,1};
	event.callback = &button;
	mouse_event_listener(mlx, &event);
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
