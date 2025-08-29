///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   canva_to_ppm.c                                     :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2025/08/22 12:17:26 by kporceil          #+#    #+#             */
///*   Updated: 2025/08/22 14:33:19 by kporceil         ###   ########lyon.fr   */
///*                                                                            */
///* ************************************************************************** */
//
//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#include "canvas.h"
//#include "libft.h"
//
//static char	*get_ppm_header(t_canva c)
//{
//	const char	*strings[] = {ft_itoa(c.width), " ", ft_itoa(c.height),
//		"\n255\n", NULL};
//	size_t		i;
//	char		*ppm;
//	char		*old_ppm;
//
//	ppm = ft_strdup("P3\n");
//	old_ppm = ppm;
//	i = 0;
//	while (strings[i])
//	{
//		if (!ppm)
//		{
//			free((char *)strings[0]);
//			free((char *)strings[2]);
//			return (NULL);
//		}
//		ppm = ft_strjoin(ppm, strings[i]);
//		free(old_ppm);
//		old_ppm = ppm;
//		++i;
//	}
//	free((char *)strings[0]);
//	free((char *)strings[2]);
//	return (ppm);
//}
//
//static void	get_actual_color(char *color[3], t_canva c, size_t i)
//{
//	if (c.canva[i].red <= 0)
//		color[0] = ft_itoa(0);
//	else if (c.canva[i].red >= 1)
//		color[0] = ft_itoa(255);
//	else
//		color[0] = ft_itoa(round(c.canva[i].red * 255));
//	if (c.canva[i].green <= 0)
//		color[1] = ft_itoa(0);
//	else if (c.canva[i].green >= 1)
//		color[1] = ft_itoa(255);
//	else
//		color[1] = ft_itoa(round(c.canva[i].green * 255));
//	if (c.canva[i].blue <= 0)
//		color[2] = ft_itoa(0);
//	else if (c.canva[i].blue >= 1)
//		color[2] = ft_itoa(255);
//	else
//		color[2] = ft_itoa(round(c.canva[i].blue * 255));
//}
//
//static char	*ppm_write_color(char *ppm, t_canva c, size_t i, size_t *line_size)
//{
//	char	*color[3];
//	char	*old_ppm;
//	size_t	j;
//
//	get_actual_color(color, c, i);
//	old_ppm = ppm;
//	if (color[0] && color[1] && color[2])
//	{
//		j = 0;
//		while (j < 3)
//		{
//			if (!ppm)
//				break ;
//			if (i == 0 && j == 0)
//				--*line_size;
//			else if (!(c.width - 1) || (i && !(i % c.width) && j == 0) || (*line_size + ft_strlen(color[j]) + 1) > 70)
//			{
//				ppm = ft_strjoin(ppm, "\n");
//				free(old_ppm);
//				*line_size = -1;
//			}
//			else
//			{
//				ppm = ft_strjoin(ppm, " ");
//				free(old_ppm);
//			}
//			++*line_size;
//			old_ppm = ppm;
//			ppm = ft_strjoin(ppm, color[j]);
//			free(old_ppm);
//			old_ppm = ppm;
//			*line_size += ft_strlen(color[j]);
//			++j;
//		}
//	}
//	free(color[0]);
//	free(color[1]);
//	free(color[2]);
//	if (!color[0] || !color[1] || !color[2] || !ppm)
//		return (NULL);
//	return (ppm);
//}
//
//static char	*get_ppm_file(char *ppm, t_canva c)
//{
//	size_t			i;
//	size_t			canva_size;
//	size_t			line_size;
//	char			*old_ppm;
//
//	canva_size = c.width * c.height;
//	i = 0;
//	line_size = 0;
//	while (i < canva_size)
//	{
//		ppm = ppm_write_color(ppm, c, i, &line_size);
//		if (!ppm)
//			return (NULL);
//		++i;
//	}
//	old_ppm = ppm;
//	ppm = ft_strjoin(ppm, "\n");
//	free(old_ppm);
//	return (ppm);
//}
//
//char	*canva_to_ppm(t_canva c)
//{
//	char	*ppm;
//
//	ppm = get_ppm_header(c);
//	if (!ppm)
//		return (NULL);
//	ppm = get_ppm_file(ppm, c);
//	return (ppm);
//}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva_to_ppm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:17:26 by kporceil          #+#    #+#             */
/*   Updated: 2025/08/25 optimized by Claude         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "canvas.h"

// Fonction pour écrire un entier dans le buffer (plus rapide que ft_itoa)
static size_t write_int_to_buffer(char *buffer, size_t pos, int value)
{
    char temp[12]; // Assez pour un int 32-bit
    int len = 0;
    int temp_val = value;
    
    // Cas spécial pour 0
    if (value == 0)
    {
        buffer[pos] = '0';
        return pos + 1;
    }
    
    // Convertir en string (en reverse)
    while (temp_val > 0)
    {
        temp[len++] = '0' + (temp_val % 10);
        temp_val /= 10;
    }
    
    // Copier en ordre normal dans le buffer
    for (int i = len - 1; i >= 0; i--)
        buffer[pos++] = temp[i];
    
    return pos;
}

// Convertir une couleur float en int (0-255)
static inline int color_to_int(double color)
{
	if (color <= 0.0)
		return 0;
	if (color >= 1.0)
		return 255;
	return (round(color * 255.0));
}

// Estimer la taille du fichier PPM final
static size_t estimate_ppm_size(t_canva c)
{
    // Header: "P3\n" + width + " " + height + "\n255\n" 
    size_t header_size = 20 + 20; // estimation large pour les nombres
    
    // Chaque pixel: 3 couleurs max 3 digits + espaces/newlines
    // Estimation large: chaque pixel = 12 caractères en moyenne
    size_t data_size = c.width * c.height * 12;
    
    return header_size + data_size + 100; // +100 pour la sécurité
}

char *canva_to_ppm(t_canva c)
{
    size_t estimated_size = estimate_ppm_size(c);
    char *ppm = malloc(estimated_size);
    if (!ppm)
        return NULL;
    
    size_t pos = 0;
    
    // Écrire le header directement
    ppm[pos++] = 'P'; ppm[pos++] = '3'; ppm[pos++] = '\n';
    pos = write_int_to_buffer(ppm, pos, c.width);
    ppm[pos++] = ' ';
    pos = write_int_to_buffer(ppm, pos, c.height);
    ppm[pos++] = '\n'; ppm[pos++] = '2'; ppm[pos++] = '5'; ppm[pos++] = '5'; ppm[pos++] = '\n';
    
    // Écrire les pixels
    size_t line_length = 0;
    size_t canva_size = c.width * c.height;
    
    for (size_t i = 0; i < canva_size; i++)
    {
        int colors[3] = {
            color_to_int(c.canva[i].red),
            color_to_int(c.canva[i].green),
            color_to_int(c.canva[i].blue)
        };
        
        for (int j = 0; j < 3; j++)
        {
            // Calculer la longueur que prendrait ce nombre
            int color_len = (colors[j] == 0) ? 1 : 
                           (colors[j] < 10) ? 1 :
                           (colors[j] < 100) ? 2 : 3;
            
            // Vérifier si on dépasse 70 caractères par ligne
            int need_space = (i != 0 || j != 0) ? 1 : 0;
            bool new_line_needed = (line_length + need_space + color_len) > 70;
            bool start_of_row = (i > 0 && i % c.width == 0 && j == 0);
            
            if (new_line_needed || start_of_row)
            {
                ppm[pos++] = '\n';
                line_length = 0;
                need_space = 0;
            }
            else if (need_space)
            {
                ppm[pos++] = ' ';
                line_length++;
            }
            
            // Écrire le nombre
            pos = write_int_to_buffer(ppm, pos, colors[j]);
            line_length += color_len;
        }
    }
    
    ppm[pos++] = '\n';
    ppm[pos] = '\0';
    
    // Réduire la taille du buffer à la taille réelle utilisée
    char *final_ppm = realloc(ppm, pos + 1);
    return final_ppm ? final_ppm : ppm;
}
