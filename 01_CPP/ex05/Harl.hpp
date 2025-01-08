/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:49 by asanni            #+#    #+#             */
/*   Updated: 2025/01/08 17:29:06 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public:
	Harl();
	~Harl();
 	void complain( std::string level);
};

#endif
