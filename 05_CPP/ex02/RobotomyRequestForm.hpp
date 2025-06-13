/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:48:45 by asanni            #+#    #+#             */
/*   Updated: 2025/06/08 17:58:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

//Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"


class AForm;

class RobotomyRequestForm : public AForm {
	
	private:
		std::string target;
		RobotomyRequestForm();
	
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(RobotomyRequestForm const &obj);
		~RobotomyRequestForm();

		//Methods
		void execute(Bureaucrat const & executor) const;
};

#endif
