/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 06:11:46 by adespond          #+#    #+#             */
/*   Updated: 2015/09/14 17:44:49 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	else if (s1[0] == s2[0] && s1[0] != '*' && s2[0] != '*')
		return (match(&s1[1], &s2[1]));
	else if (s1[0] == '*' && s2[0] == '*')
		return (match(&s1[1], &s2[0]));
	else if (s1[0] == '\0' && s2[0] == '*')
		return (match(&s1[0], &s2[1]));
	else if (s2[0] == '*' && s1[0] != '\0')
		return (match(&s1[0], &s2[1]) || match(&s1[1], &s2[0]));
	return (0);
}
