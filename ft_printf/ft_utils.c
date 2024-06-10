/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:36:15 by srandria          #+#    #+#             */
/*   Updated: 2024/04/11 11:47:53 by srandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_f_presence(char c, char *format_list)
{
	while (*format_list)
	{
		if (*format_list == c)
			return (0);
		++format_list;
	}
	return (1);
}

int	format_pos(char *flags)
{
	int	status;
	int	i;

	i = 0;
	status = 1;
	while (status == 1)
	{
		if (check_f_presence(flags[i], "cspdiuxX%") == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	fill_flags(char *format, char *flags, int format_p)
{
	int	status;
	int	i;

	i = 1;
	status = 1;
	flags[format_p] = '\0';
	while (status == 1)
	{
		if (check_f_presence(format[i], "cspdiuxX%") == 1)
		{
			*flags = format[i];
			flags++;
		}
		else
			status = 0;
		i++;
	}
}

int	ft_abs(int value)
{
	if (value < 0)
		return (value * (-1));
	else
		return (value);
}
