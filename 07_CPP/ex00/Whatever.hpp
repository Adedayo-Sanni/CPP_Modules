/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:38:19 by asanni            #+#    #+#             */
/*   Updated: 2025/10/25 11:39:33 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Template para swap: troca os valores dos dois parâmetros.
template <typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

// Template para min: retorna o menor dos dois valores.
// Se forem iguais, retorna o segundo.
template <typename T>
T const &min(T const &a, T const &b)
{
	return (b <= a ? b : a);
}

// Template para max: retorna o maior dos dois valores.
// Se forem iguais, retorna o segundo.
template <typename T>
T const &max(T const &a, T const &b)
{
	return (b >= a ? b : a);
}

#endif
