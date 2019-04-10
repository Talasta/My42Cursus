/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_store_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:22:03 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/07 10:26:30 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				**fdf_realloc(int **data, size_t size, size_t new_size)
{
	int	**new_data;

	new_data = (int**)ft_memalloc(new_size * sizeof(int*));
	if (data && new_data)
	{
		new_data = (int**)ft_memcpy(new_data, data, sizeof(int*) * size);
		ft_memdel((void*)&data);
	}
	return (new_data);
}

static void		free_buff(char **tab, char *line)
{
	int		i;

	i = 0;
	free(line);
	while (tab[i])
	{
		ft_strdel((void*)&tab[i]);
		i++;
	}
	ft_memdel((void*)&tab);
}

static int		*add_line(char **tab, size_t size)
{
	int		i;
	int		*new;

	if (!(new = (int*)ft_memalloc(size * sizeof(int))))
		return (new);
	i = 0;
	while (tab[i])
	{
		new[i] = ft_atoi(tab[i]);
		i++;
	}
	return (new);
}

static int		update_map(char **tab, t_map *map)
{
	size_t	size_tab;

	size_tab = 0;
	while (tab[size_tab])
		size_tab++;
	if (size_tab == 0)
		return (0);
	map->map = fdf_realloc(map->map, map->y, map->y + 1);
	if ((!(map->map)))
		return (0);
	if (map->x != 0 && map->x != size_tab)
		return (0);
	map->x = size_tab;
	if (!(map->map[map->y] = add_line(tab, size_tab)))
		return (0);
	return (1);
}

int				fdf_store_map(char *file_name, t_map *map)
{
	int		fd;
	int		error;
	char	*line;
	char	**tab;

	fd = open(file_name, O_RDONLY);
	while ((error = get_next_line(fd, &line)) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (update_map(tab, map) == 0)
		{
			free_buff(tab, line);
			return (term_bad_map());
		}
		map->y += 1;
		free_buff(tab, line);
	}
	close(fd);
	if (error == -1)
		return (term_prog_usage());
	if (map->x == 0 && map->y == 0)
		return (term_bad_map());
	free(line);
	return (1);
}
