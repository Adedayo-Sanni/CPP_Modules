/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:15:51 by asanni            #+#    #+#             */
/*   Updated: 2025/03/16 12:33:22 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

#include <iostream>

class Fixed{
	private:
		int num;
		static const int fractionalBits = 8;

	public:
		Fixed(); //construtor padrão
		Fixed(Fixed const &object);// copia o construtor e recebe como parametro um objeto da própria classe
		Fixed& operator=(Fixed const &object);// *
		~Fixed();
		int getRawBits() const;
		void setRawBits( int const raw );
};

/*Um operador de atribuição por cópia é uma função membro não estática
com o nome operator=, que pode ser chamado com um argumento do mesmo tipo de classe 
e copia o conteúdo do argumento sem modificar o argumento.*/

#endif
