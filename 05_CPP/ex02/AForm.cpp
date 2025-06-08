/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:03:21 by asanni            #+#    #+#             */
/*   Updated: 2025/06/08 18:16:11 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default form"), gradeToSign(50), gradeToExecute(100){}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (gradeToSign < 1|| gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150|| gradeToExecute > 150)
		throw GradeTooLowException();
	this->isSigned= false;
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

AForm& AForm::operator=(const AForm &other){
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "AForm destructor called" << std::endl;
}

//Getters
const std::string &AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

//Methods
void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign) {
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}

//Exception
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}

std::ostream & operator<<(std::ostream &os, const AForm &obj ){
	os << "========================"
	<<"\nForm name: " <<obj.getName()
	<< "\nIs Form signed?: " << (obj.getIsSigned() ? "Yes" : "No") 
	<< "\nGrade to sign: " << obj.getGradeToSign()
	<<"\nGrade to execute: " << obj.getGradeToExecute()
	<< "\n========================";
	return os;
}
