/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:04:06 by kporceil          #+#    #+#             */
/*   Updated: 2025/12/10 15:51:14 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scenes_parsing.h"
#include "bounding_box.h"
#include "color.h"
#include "matrix.h"
#include "groups.h"
#include "patterns.h"
#include "shape.h"
#include "tuples.h"
#include "canvas.h"
#include "libft.h"
#include "light.h"
#include "obj_parser.h"
#include "world.h"
#include "camera.h"
#include "display_mlx.h"
#include "visual_settings.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

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

#include <stdio.h>

size_t	g_test = 0;

typedef struct s_bvh_stats
{
	size_t	total_nodes;
	size_t	total_groups;
	size_t	total_primitives;
	size_t	max_depth;
	size_t	total_depth_sum;
	size_t	leaf_count;
	size_t	empty_groups;
	size_t	single_child_groups;
	size_t	two_child_groups;
	size_t	many_child_groups;
	size_t	min_children;
	size_t	max_children;
	double	total_bbox_volume;
	size_t	*depth_distribution;
	size_t	depth_dist_size;
}	t_bvh_stats;

static void	update_depth_distribution(t_bvh_stats *stats, size_t depth)
{
	size_t	i;
	size_t	*new_dist;

	if (depth >= stats->depth_dist_size)
	{
		new_dist = malloc(sizeof(size_t) * (depth + 1));
		if (!new_dist)
			return ;
		i = 0;
		while (i < stats->depth_dist_size)
		{
			new_dist[i] = stats->depth_distribution[i];
			i++;
		}
		while (i <= depth)
		{
			new_dist[i] = 0;
			i++;
		}
		free(stats->depth_distribution);
		stats->depth_distribution = new_dist;
		stats->depth_dist_size = depth + 1;
	}
	stats->depth_distribution[depth]++;
}

static double	calculate_bbox_volume(t_bounding_box bbox)
{
	double	dx;
	double	dy;
	double	dz;

	dx = bbox.max.x - bbox.min.x;
	dy = bbox.max.y - bbox.min.y;
	dz = bbox.max.z - bbox.min.z;
	return (dx * dy * dz);
}

static void	analyze_group_recursive(t_shape *shape, t_bvh_stats *stats, size_t depth)
{
	size_t	i;
	size_t	primitive_count;

	stats->total_nodes++;
	stats->total_depth_sum += depth;
	update_depth_distribution(stats, depth);

	if (depth > stats->max_depth)
		stats->max_depth = depth;

	if (shape->type == GROUP)
	{
		stats->total_groups++;
		stats->total_bbox_volume += calculate_bbox_volume(shape->group_bbox);

		if (shape->nb_members == 0)
			stats->empty_groups++;
		else if (shape->nb_members == 1)
			stats->single_child_groups++;
		else if (shape->nb_members == 2)
			stats->two_child_groups++;
		else
			stats->many_child_groups++;

		if (shape->nb_members < stats->min_children)
			stats->min_children = shape->nb_members;
		if (shape->nb_members > stats->max_children)
			stats->max_children = shape->nb_members;

		primitive_count = 0;
		i = 0;
		while (i < shape->nb_members)
		{
			analyze_group_recursive(&shape->child[i], stats, depth + 1);
			if (shape->child[i].type != GROUP)
				primitive_count++;
			i++;
		}

		if (primitive_count == shape->nb_members && shape->nb_members > 0)
			stats->leaf_count++;
	}
	else
	{
		stats->total_primitives++;
	}
}

static void	init_bvh_stats(t_bvh_stats *stats)
{
	stats->total_nodes = 0;
	stats->total_groups = 0;
	stats->total_primitives = 0;
	stats->max_depth = 0;
	stats->total_depth_sum = 0;
	stats->leaf_count = 0;
	stats->empty_groups = 0;
	stats->single_child_groups = 0;
	stats->two_child_groups = 0;
	stats->many_child_groups = 0;
	stats->min_children = (size_t)-1;
	stats->max_children = 0;
	stats->total_bbox_volume = 0.0;
	stats->depth_distribution = malloc(sizeof(size_t) * 10);
	stats->depth_dist_size = 10;
	size_t i = 0;
	while (i < stats->depth_dist_size)
	{
		stats->depth_distribution[i] = 0;
		i++;
	}
}

void	print_bvh_stats(t_shape *root)
{
	t_bvh_stats	stats;
	size_t		i;

	init_bvh_stats(&stats);
	analyze_group_recursive(root, &stats, 0);

	printf("\n");
	printf("========================================\n");
	printf("        BVH STATISTICS REPORT\n");
	printf("========================================\n\n");

	printf("GENERAL STATISTICS:\n");
	printf("  Total nodes:              %zu\n", stats.total_nodes);
	printf("  Total groups:             %zu\n", stats.total_groups);
	printf("  Total primitives:         %zu\n", stats.total_primitives);
	printf("  Max depth:                %zu\n", stats.max_depth);
	printf("  Average depth:            %.2f\n",
		(double)stats.total_depth_sum / stats.total_nodes);
	printf("  Leaf groups:              %zu\n", stats.leaf_count);
	printf("\n");

	printf("GROUP DISTRIBUTION:\n");
	printf("  Empty groups (0 child):   %zu\n", stats.empty_groups);
	printf("  Single child groups:      %zu\n", stats.single_child_groups);
	printf("  Binary groups (2 child):  %zu\n", stats.two_child_groups);
	printf("  Multi-child groups (>2):  %zu\n", stats.many_child_groups);
	printf("  Min children per group:   %zu\n", stats.min_children);
	printf("  Max children per group:   %zu\n", stats.max_children);
	printf("  Avg children per group:   %.2f\n",
		stats.total_groups > 0 ?
		(double)(stats.total_nodes - 1) / stats.total_groups : 0.0);
	printf("\n");

	printf("BOUNDING BOX STATISTICS:\n");
	printf("  Total bbox volume:        %.2f\n", stats.total_bbox_volume);
	printf("  Average bbox volume:      %.2f\n",
		stats.total_groups > 0 ?
		stats.total_bbox_volume / stats.total_groups : 0.0);
	printf("\n");

	printf("DEPTH DISTRIBUTION:\n");
	i = 0;
	while (i < stats.depth_dist_size)
	{
		if (stats.depth_distribution[i] > 0)
			printf("  Depth %zu:                 %zu nodes (%.1f%%)\n",
				i, stats.depth_distribution[i],
				100.0 * stats.depth_distribution[i] / stats.total_nodes);
		i++;
	}
	printf("\n");

	printf("EFFICIENCY METRICS:\n");
	printf("  BVH branching factor:     %.2f\n",
		stats.total_groups > 0 ?
		(double)stats.total_nodes / stats.total_groups : 0.0);
	printf("  Primitives/Leaf ratio:    %.2f\n",
		stats.leaf_count > 0 ?
		(double)stats.total_primitives / stats.leaf_count : 0.0);
	printf("  Tree balance score:       %.2f%% (ideal: 100%%)\n",
		stats.max_depth > 0 ?
		100.0 * (log2(stats.total_nodes) / stats.max_depth) : 0.0);
	printf("\n");

	printf("========================================\n");

	free(stats.depth_distribution);
}

int	main(void)
{
	t_world	world = world_create();
	struct timeval	tv_a = (struct timeval){0};
	struct timeval	tv_b = (struct timeval){0};
	t_obj_parsing	p;
	t_shape	g;

	world.lights_count = 1;
	world.objs_count = 1;
	world.objs = malloc(sizeof(t_shape) * world.objs_count);
	world.lights = malloc(sizeof(t_plight) * world.lights_count);
	world.lights[0] = point_light(point(10, 0, 0), color(1, 1, 1));
	p = obj_parser("assets/teapot.obj");
	printf("obj parsing [X]\n");
	g = parsed_to_group(&p);
	printf("parsed to group [X]\n");

	printf("\n=== AVANT DIVIDE ===\n");
	print_bvh_stats(&g);

	divide(&g, 10);
	printf("divide [X]\n");

	printf("\n=== APRES DIVIDE (threshold=100) ===\n");
	print_bvh_stats(&g);

	t_camera	cam = camera(WIDTH, HEIGHT, 70 * (M_PI / 180), point(7, 0, 0));

	// Test 1: Render WITHOUT BVH
	printf("\n========================================\n");
	printf("   RENDERING WITHOUT BVH\n");
	printf("========================================\n");
	t_obj_parsing	p_no_bvh = obj_parser("assets/big_teapot.obj");
	t_shape	g_no_bvh = parsed_to_group(&p_no_bvh);
	world.objs[0] = g_no_bvh;
	world.buf_inter = malloc(sizeof(t_inter) * count_possible_intersections(&world));

	g_test = 0;
	gettimeofday(&tv_a, NULL);
	t_canva	image_no_bvh = render(cam, world, 1);
	gettimeofday(&tv_b, NULL);
	long ms_no_bvh = 1000 * (tv_b.tv_sec - tv_a.tv_sec) + (tv_b.tv_usec - tv_a.tv_usec) / 1000;
	size_t intersections_no_bvh = g_test;

	printf("  Triangle intersections: %zu\n", intersections_no_bvh);
	printf("  Render time: %ld ms\n", ms_no_bvh);
	printf("  Intersections per ms: %.2f\n", (double)intersections_no_bvh / ms_no_bvh);

	free(image_no_bvh.canva);
	free(world.buf_inter);

	// Test 2: Render WITH BVH
	printf("\n========================================\n");
	printf("   RENDERING WITH BVH\n");
	printf("========================================\n");
	world.objs[0] = g;
	world.buf_inter = malloc(sizeof(t_inter) * count_possible_intersections(&world));

	g_test = 0;
	gettimeofday(&tv_a, NULL);
	t_canva	image = render(cam, world, 1);
	gettimeofday(&tv_b, NULL);
	printf("render [X]\n");
	long ms_bvh = 1000 * (tv_b.tv_sec - tv_a.tv_sec) + (tv_b.tv_usec - tv_a.tv_usec) / 1000;
	size_t intersections_bvh = g_test;

	printf("  Triangle intersections: %zu\n", intersections_bvh);
	printf("  Render time: %ld ms\n", ms_bvh);
	printf("  Intersections per ms: %.2f\n", (double)intersections_bvh / ms_bvh);

	// Comparison
	printf("\n========================================\n");
	printf("   COMPARISON\n");
	printf("========================================\n");
	printf("  Speedup: %.2fx\n", (double)ms_no_bvh / ms_bvh);
	printf("  Intersection reduction: %.2f%%\n",
		100.0 * (1.0 - (double)intersections_bvh / intersections_no_bvh));
	printf("========================================\n\n");

	if (!image.canva)
		return (1);

	display_mlx(image, &cam, world, 1000 * (tv_b.tv_sec - tv_a.tv_sec)
			+ (tv_b.tv_usec - tv_a.tv_usec) / 1000);
	free(image.canva);
	free_world(&world);
}
