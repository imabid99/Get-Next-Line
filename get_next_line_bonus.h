/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:22:28 by imabid            #+#    #+#             */
/*   Updated: 2021/11/22 12:14:15 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> 
# include <stdlib.h>

char	*ft_strjoin_bonus(char *s1, char *s2);
char	*get_next_line_bonus(int fd);
char	*ft_strchr_bonus(const char *s, int c);
size_t	ft_strlen_bonus(const	char *s);

#endif