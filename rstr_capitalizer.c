/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdecaux <hdecaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:43:16 by hdecaux           #+#    #+#             */
/*   Updated: 2015/11/10 09:35:09 by hdecaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int			ft_ispace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

void		rstr_capitalizer(char *str)
{
	int		i;
	char	*t;
	char	*s;

	i = 0;
	s = str;
	t = str;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90 && ft_ispace(s[i + 1]) == 0)
		{
			t[i] = s[i] + 32;
			i++;
		}
		else if (ft_ispace(s[i]) == 1 && s[i - 1] >= 97 && s[i - 1] <= 122)
		{
			t[i - 1] = s[i - 1] - 32;
			t[i] = s[i];
			i++;
		}
		else
		{
			t[i] = s[i];
			i++;
		}
	}
	if (t[i -1] >= 97 && t[i - 1] <= 122)
	{
		t[i - 1] = t[i - 1] - 32;
	} 
	ft_putstr(t);
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_putchar('\n');
	while (argc != 1)
	{
		rstr_capitalizer(argv[i]);
		i++;
	}
	return (0);
}
