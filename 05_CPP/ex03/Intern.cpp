/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedayo <adedayo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:41:40 by adedayo           #+#    #+#             */
/*   Updated: 2025/06/13 13:14:08 by adedayo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

  Intern::Intern(void) {}
  
  Intern::Intern(const Intern &other) { (void)other; }
  
  Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
  
  Intern::~Intern() {}
  
  AForm* Intern::createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
  }

AForm* Intern::createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
  }

AForm* Intern::createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
  }
  
AForm* Intern::makeForm(std::string formName, std::string formTarget){
    std::string formNames[3] = {
      "Shruberry creation",
      "Robotomy request",
      "Presidential pardon"
    };

    AForm* (*formCreator[3])(std::string target) = {
      &Intern::createShrubbery,
      &Intern::createRobotomy,
      &Intern::createPresidential
    };

    for (int i = 0; i<3; i++){
      if (formName == formNames[i]){
        std::cout << "Intern created " << formName << " form" << std::endl;
        return formCreator[i](formTarget);
      }
    }
    std:: cerr << "ERROR: Form " << formName << " does not exist" << std::endl;

    return NULL;
  };