/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:51:55 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 16:42:36 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

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
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	
	private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	public:
	Form();
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	//Getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//methods
	void beSigned(Bureaucrat& bureaucrat);

	//exceptions
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &form);

#endif
