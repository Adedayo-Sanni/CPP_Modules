/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:42:49 by asanni            #+#    #+#             */
/*   Updated: 2025/04/19 16:39:09 by asanni           ###   ########.fr       */
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

class Bureaucrat{
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string getName() const;
	int getGrade();
	void incrementGrade();
	void decrementGrade();
	
};
std::ostream & operator<<(std::ostream &os, const Bureaucrat &obj);

#endif

