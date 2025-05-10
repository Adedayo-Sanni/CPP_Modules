/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 18:21:36 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 18:28:57 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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



class ShrubberyCreationForm : public AForm {
	private:
	
	
	public:
	ShrubberyCreationForm()
	ShrubberyCreationForm() // passar as grades
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &obj)
	~ShrubberyCreationForm()
};

#endif
