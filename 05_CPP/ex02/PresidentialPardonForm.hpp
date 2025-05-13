/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:48:41 by asanni            #+#    #+#             */
/*   Updated: 2025/05/13 18:16:20 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

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
#include "AForm.hpp"


class AForm;

class PresidentialPardonForm : public AForm {
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(AForm& form);
		PresidentialPardonForm& operator=(PresidentialPardonForm const &obj);
		~PresidentialPardonForm();

		//Methods
		void execute(Bureaucrat const & executor) const;
};

#endif
