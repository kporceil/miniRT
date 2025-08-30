/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/30 19:11:38 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "spheres.h"
#include "tuples.h"
#include "canvas.h"
#include "libft.h"
#include "ray.h"
#include "light.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	tick(t_tuple *env, t_tuple *proj);

void	write_file(char	*name, char	*ppm)
{
	int	fd;

	fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return ;
	ft_putstr_fd(ppm, fd);
	close(fd);
}

int	main(void)
{
	t_canva		can = canva(4000, 4000);
	t_sphere	s = sphere(0);
	t_plight	light = point_light(point(-10, 10, -10), color(1, 1, 1));

	s.material.color = color(1, 0.2, 1);
	for (size_t	y = 0; y < can.height; ++y) {
		double	world_y = 3.5 - (7.0 / 4000) * y;
		for (size_t x = 0; x < can.width; ++x) {
			double world_x = -3.5 + (7.0 / 4000) * x;
			t_tuple pos = point(world_x, world_y, 1);
			t_ray r = ray(point(0, 0, -5), normalize(tuple_substract(pos, point(0, 0, -5))));
			t_intersect xs = ray_intersect(&s, r);
			t_inter *hit = inter_hit(&xs, 1);
			if (hit != NULL)
			{
				t_tuple point = ray_position(r, hit->point);
				t_tuple normal = normal_at(*(hit->s), point);
				t_tuple eye = tuple_negate(r.direction);
				t_color clr = lighting(hit->s->material, light, point, (t_tuple[2]){eye, normal});
				write_pixel(&can, x, y, clr);
			}
		}
	}
	char	*ppm = canva_to_ppm(can);
	free(can.canva);
	write_file("render/first_spheres.ppm", ppm);
	free(ppm);
	return (0);
}
