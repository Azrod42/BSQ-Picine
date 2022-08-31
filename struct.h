/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:18:59 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 20:35:47 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define BUF_SIZE 5000000

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_max_sqr
{
	int		x;
	int		y;
	int		lgt;
	char	*start;
}t_max_sqr;

#endif
