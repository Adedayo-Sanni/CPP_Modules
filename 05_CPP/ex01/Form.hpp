/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:51:55 by asanni            #+#    #+#             */
/*   Updated: 2025/05/10 12:42:49 by asanni           ###   ########.fr       */
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

class Bureaucrat

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
	void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
}


#endif
