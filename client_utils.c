/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:36:55 by mmilicev          #+#    #+#             */
/*   Updated: 2025/04/05 20:37:06 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	check_pid(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
		{
			if (*pid == '-')
			{
				ft_putendl_fd("Error: Invalid PID.", 2);
				return (1);
			}
			ft_putendl_fd("Error: PID should contain just a numbers!", 2);
			return (1);
		}
		pid++;
	}
	return (0);
}

int	pid_exist_check(pid_t pid)
{
	if (kill(pid, 0) == -1)
	{
		ft_putendl_fd("Error: PID doesn't exist.", 2);
		return (1);
	}
	return (0);
}
