/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:35:23 by asanni            #+#    #+#             */
/*   Updated: 2025/10/25 12:35:54 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// Template iter: percorre um array e aplica a função f a cada elemento.
// - T* array: endereço do primeiro elemento (pode ser T = const U).
// - length: comprimento do array (const unsigned int conforme enunciado).
// - Func f: qualquer callable (função, ponteiro para função, functor, função-template instanciada).
template <typename T, typename Func>
void iter(T* array, const unsigned int length, Func f)
{
    for (unsigned int i = 0; i < length; ++i)
    {
        f(array[i]);
    }
}

#endif
