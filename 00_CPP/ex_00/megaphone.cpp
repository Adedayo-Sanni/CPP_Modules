/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:19:52 by asanni            #+#    #+#             */
/*   Updated: 2024/11/02 17:05:05 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main (int argc, char **argv)
{

	int	i = 1;
	if (argc == 1)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
	else
	{
		while (i < argc)
		{
			int	j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}

//A toupper retorna o int ascii então casto para char para imprimir
//as letras no terminal
