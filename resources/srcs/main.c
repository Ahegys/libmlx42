// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------
#include "../includes/structs.h"
#include "../includes/engine.h"

void	button(t_mlx *src, t_btn *props)
{
	
}

void	render(void *data)
{
	t_mlx	*mlx;
	mlx = (t_mlx *)data;

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
