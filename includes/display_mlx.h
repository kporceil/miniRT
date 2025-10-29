/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:28:14 by lcesbron          #+#    #+#             */
/*   Updated: 2025/10/29 16:40:36 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_MLX_H
# define DISPLAY_MLX_H

# include "camera.h"
# include <stdbool.h>

# define WINDOW_TITLE "miniRT"

typedef struct s_display		t_display;
typedef struct s_loop_params	t_loop_params;

struct s_display
{
	void	*mlx_ptr;
	void	*window;
	void	*image;
	char	*data_addr;
	int		bpp;
	int		opp;
	int		size_line;
	int		endian;
};

struct s_loop_params
{
	t_canva		canva;
	t_world		world;
	t_camera	*camera;
	t_display	display;
	_Bool		moving;
	_Bool		should_render;
};

t_display	init_mlx_display(size_t width, size_t height);
void		exit_mlx(t_display display);
int			display_mlx(t_canva canva, t_camera *camera, t_world world);
int			render_loop(t_loop_params *p);
int			key_hooks(int keycode, t_loop_params *p);

#endif
