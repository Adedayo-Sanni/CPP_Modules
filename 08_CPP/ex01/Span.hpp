/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:38:03 by asanni            #+#    #+#             */
/*   Updated: 2025/11/04 20:07:02 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span(void);
	Span(unsigned int n);
	Span(Span const &src);
	~Span(void);

	Span &operator=(Span const &rhs);

	void addNumber(int number);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

template <typename InputIterator>
void addNumber(InputIterator begin, InputIterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::runtime_error("Not possible to add: over the limit");
	_numbers.insert(_numbers.end(), begin, end);
}

};

#endif
