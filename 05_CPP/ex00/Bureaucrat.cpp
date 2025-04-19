/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:07:00 by asanni            #+#    #+#             */
/*   Updated: 2025/04/19 16:17:25 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj ){
	os << obj.getName() << "bureaucrat grade" << obj.getGrade();
	return os;
}

