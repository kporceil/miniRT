/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:20:54 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/21 19:12:22 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

t_tuple	vector(double x, double y, double z);
t_tuple	point(double x, double y, double z);
t_tuple	tuple_add(t_tuple t1, t_tuple t2);
t_tuple	tuple_substract(t_tuple t1, t_tuple t2);
t_tuple	tuple_negate(t_tuple t);
t_tuple	tuple_scalar_mult(t_tuple t, double scalar);
t_tuple	tuple_scalar_div(t_tuple t, double scalar);
t_tuple	normalize(t_tuple v);
t_tuple	cross(t_tuple v1, t_tuple v2);
double	magnitude(t_tuple v);
double	dot(t_tuple v1, t_tuple v2);

#endif
