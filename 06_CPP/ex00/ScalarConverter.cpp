/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:58:47 by asanni            #+#    #+#             */
/*   Updated: 2025/10/19 19:28:15 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string &literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isIntLiteral(const std::string &literal) {
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.size(); i++) {
        if (!isdigit(literal[i]))
            return false;
    }
    return !literal.empty();
}

bool ScalarConverter::isFloatLiteral(const std::string &literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    bool hasDot = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.size(); i++) {
        if (literal[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (literal[i] == 'f' && i == literal.size() - 1) {
            return hasDot;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return false;
}

bool ScalarConverter::isDoubleLiteral(const std::string &literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    bool hasDot = false;
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.size(); i++) {
        if (literal[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!isdigit(literal[i])) {
            return false;
        }
    }
    return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

void ScalarConverter::convert(const std::string &literal) {
    std::cout << std::fixed << std::setprecision(1);

    // Pseudo-literals (nan, inf)
     if (isPseudoLiteral(literal)) {
        double d;
        float f;

        if (literal == "nan" || literal == "nanf") {
            d = 0.0 / 0.0;   // NaN
            f = 0.0f / 0.0f;
        } else if (literal == "+inf" || literal == "+inff") {
            d = 1.0 / 0.0;   // +inf
            f = 1.0f / 0.0f;
        } else { // "-inf" / "-inff"
            d = -1.0 / 0.0;  // -inf
            f = -1.0f / 0.0f;
        }

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    double value = 0.0;

    if (isCharLiteral(literal)) {
        value = static_cast<double>(literal[1]);
    } else if (isIntLiteral(literal)) {
        value = static_cast<double>(atoi(literal.c_str()));
    } else if (isFloatLiteral(literal)) {
        value = static_cast<double>(atof(literal.c_str()));
    } else if (isDoubleLiteral(literal)) {
        value = atof(literal.c_str());
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // int
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // float & double
    float f = static_cast<float>(value);
    double d = value;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
