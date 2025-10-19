/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:15:40 by asanni            #+#    #+#             */
/*   Updated: 2025/10/19 19:41:23 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.name = "Test Subject";
    data.age = 30;
    data.score = 70.5;

    std::cout << GREEN << "=== Original Data ===" << std::endl;
    std::cout << "Address: " << &data << std::endl;
    std::cout << "Name: " << data.name << ", Age: " << data.age << ", Score: " << data.score << RESET << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << MAGENTA <<"\n=== After Serialization / Deserialization ===" << std::endl;
    std::cout << "Raw integer: " << raw << std::endl;
    std::cout << "Deserialized address: " << ptr << RESET << std::endl;

    if (ptr == &data)
        std::cout << BLUE << "✅ Success: same pointer!" << RESET << std::endl;
    else
        std::cout << RED << "❌ Error: pointers differ!" << RESET << std::endl;

    std::cout << "Name: " << ptr->name << ", Age: " << ptr->age << ", Score: " << ptr->score << std::endl;

    return 0;
}
