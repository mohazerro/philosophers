/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 01:51:15 by mgamil            #+#    #+#             */
/*   Updated: 2022/12/24 02:09:02 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_threadserror(t_all *all, char *function, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		pthread_detach(all ->phil[i].phils);
	ft_error(all, function, -1, 3);
	return (1);
}

int	ft_error(t_all *all, char *function, int index, int value)
{
	int	i;

	i = -1;
	printf("failed in:%s\n", function);
	if (index == -1)
		index = all->nbphils;
	while (++i < index)
		pthread_mutex_destroy(&all->m_nbforks[i]);
	if (value > 0)
		pthread_mutex_destroy(&all->print);
	else if (value > 1)
		pthread_mutex_destroy(&all->shield);
	else if (value > 2)
		free(all->phil);
	return (1);
}

char	*color(char *what)
{
	if (ft_strnstr(what, "eating", ft_strlen(what)))
		return (GREEN);
	if (ft_strnstr(what, "left", ft_strlen(what)))
		return (YELLOW);
	if (ft_strnstr(what, "right", ft_strlen(what)))
		return (MAGENTA);
	if (ft_strnstr(what, "sleeping", ft_strlen(what)))
		return (RED);
	if (ft_strnstr(what, "thinking", ft_strlen(what)))
		return (BLUE);
	return (RESET);
}

char	*colorint(int n)
{
	if (n % 8 == 0)
		return (WHITE);
	else if (n % 7 == 0)
		return (RED);
	else if (n % 6 == 0)
		return (GREEN);
	else if (n % 5 == 0)
		return (YELLOW);
	else if (n % 4 == 0)
		return (BLUE);
	else if (n % 3 == 0)
		return (MAGENTA);
	else if (n % 2 == 0)
		return (CYAN);
	return (RESET);
}
