/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedayo <adedayo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:03:19 by adedayo           #+#    #+#             */
/*   Updated: 2025/06/13 13:05:42 by adedayo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

//Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


class Intern {
  private:
    static AForm* createShrubbery(std::string target);
    static AForm* createRobotomy(std::string target);
    static AForm* createPresidential(std::string target);
  
  public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();
  
  //methods
  AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
