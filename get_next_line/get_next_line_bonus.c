/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:27:12 by srandria          #+#    #+#             */
/*   Updated: 2024/04/17 08:45:12 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

static void	*trim_up_to_bn(char ***next_l, char ***buff_e, int **bs_pos)
{
	char	*new;

	new = 0;
	free(**next_l);
	**next_l = 0;
	if (**bs_pos != -1)
	{
		**next_l = ft_substr(**buff_e, 0, **bs_pos + 1);
		new = strcpy_from_i(**buff_e, **bs_pos + 1);
		return (free(**buff_e), **buff_e = new, **bs_pos = -2, NULL);
	}
	else
	{
		**next_l = strcpy_from_i(**buff_e, 0);
		if (**next_l[0] == '\0')
		{
			free(**next_l);
			**next_l = 0;
		}
		return (free(**buff_e), **buff_e = NULL, NULL);
	}
	return (0);
}

static void	*hybrid(char **next_l, char **buff, char **buff_e, int *bs_pos)
{
	char	*next_with_buff_e;
	char	*new_next;
	char	*sub_value;

	*bs_pos = backslash_n_pos(*buff);
	if (*bs_pos == -1)
	{
		new_next = ft_strjoin(*next_l, *buff);
		return (free(*next_l), *next_l = new_next, NULL);
	}
	sub_value = ft_substr(*buff, 0, *bs_pos + 1);
	new_next = ft_strjoin(*buff_e, sub_value);
	free(*buff_e);
	free(sub_value);
	*buff_e = strcpy_from_i(*buff, *bs_pos + 1);
	*bs_pos = -2;
	if (*next_l)
	{
		next_with_buff_e = ft_strjoin(*next_l, new_next);
		free(*next_l);
		return (free(new_next), *next_l = next_with_buff_e, NULL);
	}
	else
		return (free(*next_l), *next_l = new_next, NULL);
}

static void	formatter(char **next_l, char *buff, char *buff_e, int *bs_pos)
{
	int	i;

	i = -1;
	*next_l = 0;
	if (!buff)
		*bs_pos = -2;
	else
	{
		while (++i < BUFFER_SIZE + 1)
			buff[i] = '\0';
		*bs_pos = backslash_n_pos(buff_e);
	}
}

int	trim_save(char **next_l, char **buff_e, char **buff, int *bs_pos)
{
	char	*new_buff_e;

	trim_up_to_bn(&next_l, &buff_e, &bs_pos);
	if (*bs_pos == -2)
	{
		new_buff_e = ft_strjoin(*buff_e, *buff);
		free(*buff_e);
		*buff_e = new_buff_e;
		return (1);
	}
	return (5);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*buff_e[1024];
	char		*next_l;
	int			bytes;
	int			bs_pos;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	formatter(&next_l, buff, buff_e[fd], &bs_pos);
	while (bs_pos != -2)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff_e[fd]), buff_e[fd] = NULL, free(buff), NULL);
		buff[bytes] = '\0';
		if (bs_pos > -1 || buff_e[fd])
			if (trim_save(&next_l, &buff_e[fd], &buff, &bs_pos) == 1)
				return (free(buff), buff = NULL, next_l);
		if (bytes == 0)
			break ;
		hybrid(&next_l, &buff, &buff_e[fd], &bs_pos);
	}
	return (free(buff), next_l);
}
