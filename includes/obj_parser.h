/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:09 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/18 19:20:11 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

typedef enum e_parsing_status	t_parsing_status;
typedef struct s_obj_parsing	t_obj_parsing;

enum e_parsing_status
{
	NO_ERROR,
	OPEN_ERROR,
	MALLOC_ERROR
}

struct s_obj_parsing
{
	t_group				default_group;
	t_tuple				*vertices;
	size_t				vertices_nb;
	size_t				faces_nb;
	t_parsing_status	status;
}

#endif
