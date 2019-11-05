/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:09:55 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:14:18 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define NUM_FD 1024

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

int get_next_line(const int fd, char **line);

#endif
