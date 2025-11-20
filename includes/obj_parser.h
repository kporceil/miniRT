/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcesbron <lcesbron@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:09 by lcesbron          #+#    #+#             */
/*   Updated: 2025/11/20 16:53:32 by lcesbron         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# include "groups.h"
# include "tuples.h"

# define DEFAULT_GROUP_SIZE 1
# define DEFAULT_GROUP_MEMBER_SIZE 100
# define DEFAULT_VERTICES_SIZE 1000

typedef enum e_parsing_status	t_parsing_status;
typedef struct s_obj_parsing	t_obj_parsing;

enum e_parsing_status
{
	NO_ERROR,
	OPEN_ERROR,
	MALLOC_ERROR,
	FILE_NEGATIVE_VERTICE,
	FILE_NONEXISTANT_VERTICE,
	FILE_INVALID_VERTICE,
};

struct s_obj_parsing
{
	t_shape				*groups;
	t_shape				*current_group;
	t_tuple				*vertices;
	t_parsing_status	status;
	size_t				ignored;
};

t_obj_parsing	obj_parser(char *path);
void			parse_obj_line(char *line, t_obj_parsing *p);
void			free_obj_parsing(t_obj_parsing *p);
void			add_vertice(char **args, t_obj_parsing *p);
void			add_face(char **args, t_obj_parsing *p);

#endif
