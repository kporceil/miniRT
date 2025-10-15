/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:08:19 by kporceil          #+#    #+#             */
/*   Updated: 2025/10/15 19:38:46 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERNS_H
# define PATTERNS_H

# include "color.h"
# include "tuples.h"
# include "matrix.h"
# include "canvas.h"
# include <stddef.h>
# include <math.h>

# ifndef FRONTF
#  define FRONTF 0
# endif

# ifndef BACKF
#  define BACKF 1
# endif

# ifndef RIGHTF
#  define RIGHTF 2
# endif

# ifndef LEFTF
#  define LEFTF 3
# endif

# ifndef UPF
#  define UPF 4
# endif

# ifndef DOWNF
#  define DOWNF 5
# endif

typedef struct s_shape	t_shape;

typedef enum e_uvpatype
{
	CHECKERS,
	ALIGN,
	IMAGE,
}				t_uvpatype;

typedef union u_uvcol
{
	struct
	{
		t_color	a;
		t_color	b;
	};
	struct
	{
		t_color	main;
		t_color	ul;
		t_color	ur;
		t_color	bl;
		t_color	br;
	};
}				t_uvcol;

typedef struct s_uvpat
{
	t_uvpatype	type;
	size_t		height;
	size_t		width;
	t_uvcol		colors;
	t_canva		file;
}				t_uvpat;

typedef enum e_patype
{
	NO,
	STRIPED,
	GRADIENT,
	RING,
	CHECKER,
	UV,
	CUBE_UV,
}				t_patype;

typedef struct s_pattern
{
	t_patype	type;
	t_color		a;
	t_color		b;
	t_matrix	transform;
	t_matrix	inverted;
	t_uvpat		uvpat;
	t_uvpat		faces[6];
	void		(*uvmapper)(t_tuple, double *, double *);
}				t_pattern;

static inline t_uvpat	uv_image(t_canva c)
{
	return ((t_uvpat){.type = IMAGE, .file = c});
}

static inline t_pattern	cube_pattern(t_uvpat face[6])
{
	return ((t_pattern){.type = CUBE_UV, .transform = identity_matrix(4),
		.inverted = identity_matrix(4),
		.faces = {face[0], face[1], face[2], face[3], face[4], face[5]}});
}

static inline t_uvpat	uv_checkers(size_t width, size_t height,
		t_color a, t_color b)
{
	return ((t_uvpat){.type = CHECKERS, .width = width,
		.height = height, .colors.a = a, .colors.b = b});
}

static inline t_uvpat	uv_align_check(t_color colors[5])
{
	return ((t_uvpat){.type = ALIGN, .colors.main = colors[0],
		.colors.ul = colors[1], .colors.ur = colors[2],
		.colors.bl = colors[3], .colors.br = colors[4]});
}

static inline t_pattern	texture_map(t_uvpat pat, void (*uvmapper)
		(t_tuple, double *, double *))
{
	return ((t_pattern){.type = UV, .uvpat = pat, .uvmapper = uvmapper,
		.transform = identity_matrix(4), .inverted = identity_matrix(4)});
}

static inline t_pattern	pattern(t_patype type, t_color a, t_color b)
{
	return ((t_pattern){.type = type, .a = a, .b = b,
		.transform = identity_matrix(4), .inverted = identity_matrix(4)});
}

static inline void	pattern_set_transform(t_pattern *pat, t_matrix transform)
{
	pat->transform = transform;
	pat->inverted = matrix_invert(transform);
}

static inline t_color	stripe_at(t_pattern pat, t_tuple p)
{
	int	x;

	x = floor(p.x + 0.0001);
	if (x % 2)
		return (pat.b);
	return (pat.a);
}

static inline t_color	ring_at(t_pattern pat, t_tuple p)
{
	if ((int)(floor(sqrt(p.x * p.x + p.z * p.z) + 0.0001)) % 2)
		return (pat.b);
	return (pat.a);
}

static inline t_color	gradient_at(t_pattern pat, t_tuple p)
{
	int	x;

	x = floor(p.x + 0.0001);
	return (color_add(pat.a, color_scalar_mult(color_substract(pat.b, pat.a),
				p.x - x)));
}

static inline t_color	checker_at(t_pattern pat, t_tuple p)
{
	int	x;
	int	y;
	int	z;

	x = floor(p.x + 0.0001);
	y = floor(p.y + 0.0001);
	z = floor(p.z + 0.0001);
	if ((x + y + z) % 2)
		return (pat.b);
	return (pat.a);
}

t_color	uv_pattern_at(t_uvpat pat, double u, double v);

static inline t_color	uv_pattern_at_point(t_pattern pat, t_tuple p)
{
	double	u;
	double	v;

	pat.uvmapper(p, &u, &v);
	return (uv_pattern_at(pat.uvpat, u, v));
}

t_color	pattern_at(t_pattern pat, t_tuple p);
t_color	pattern_at_object(t_pattern pat, t_shape obj, t_tuple p);
void	spherical_map(t_tuple p, double *u, double *v);
void	planar_map(t_tuple p, double *u, double *v);
void	cylindrical_map(t_tuple p, double *u, double *v);
int		face_from_point(t_tuple p);
void	cubic_map_front(t_tuple p, double *u, double *v);
void	cubic_map_back(t_tuple p, double *u, double *v);
void	cubic_map_up(t_tuple p, double *u, double *v);
void	cubic_map_down(t_tuple p, double *u, double *v);
void	cubic_map_left(t_tuple p, double *u, double *v);
void	cubic_map_right(t_tuple p, double *u, double *v);

#endif
