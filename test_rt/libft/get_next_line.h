/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:53:41 by pbeller           #+#    #+#             */
/*   Updated: 2017/01/19 17:53:47 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4096
# define MAX_FD 4096
# define NEWLINE '\n'

int		fill_buff(int fd, char **stock, char **line);
int		get_next_line(const int fd, char **line);
int		stock_gestion(int fd, char **stock, char **line);

#endif
