/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:02:49 by asanni            #+#    #+#             */
/*   Updated: 2025/01/07 19:14:17 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL
# define HARL

class Harl
{
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	
	public:
	void complain( std::string level);
};

#endif
