/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:08:08 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 18:15:09 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_name_error(void)
{
	printf("Error: Карта должна иметь формат .ber\n");
	exit (1);
	return (1);
}

int	mlx_error(void)
{
	printf("Error: Ошибка инициализации mlx.\n");
	exit (1);
	return (1);
}

t_file	*file_error(void)
{
	printf("Error: Проверьте имя карты.\n");
	exit (1);
	return (NULL);
}
