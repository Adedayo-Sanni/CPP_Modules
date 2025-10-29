/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:25:06 by asanni            #+#    #+#             */
/*   Updated: 2025/10/29 20:06:23 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#include <iostream>
#include <exception>

template <typename T>
class Array
{

public:
    // ======== Std Constructor ========
    Array() : _size(0), _data(NULL) {}

    // ======== Constructor w/ size ========
    Array(unsigned int n) : _size(n)
    {
        if (n == 0)
        {
            _data = NULL;
        }
        else
        {
            _data = new T[n]();
        }
    }

    // ======== Copy Constructor ========
    Array(const Array &other) : _size(other._size)
    {
        if (_size == 0)
        {
            _data = NULL;
        }
        else
        {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
    }
    // ======== Attribution operator ========
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] _data;

            _size = other._size;
            if (_size == 0)
            {
                _data = NULL;
            }
            else
            {
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // ======== override of [] operator ========
    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
    // ======== override of [] operator (const) ========
    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
    // ======== Destructor ========
    ~Array()
    {
        delete[] _data;
    }
    // ======== size function ========
    unsigned int size() const
    {
        return _size;
    }

    private:
    unsigned int _size;
    T *_data;
};

#endif
