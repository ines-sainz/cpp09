/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:08 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:16:10 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdint.h>


#ifndef _COLORS
# define _COLORS
# define BLACK    "\033[1;30m"
# define RED      "\033[1;31m"
# define GREEN    "\033[1;32m"
# define YELLOW   "\033[1;33m"
# define BLUE     "\033[1;34m"
# define MAGENTA  "\033[1;35m"
# define CYAN     "\033[1;36m"
# define WHITE    "\033[1;37m"
# define BOLD	  "\033[1m"
# define BOLD_OFF "\033[22m"
# define ITALIC   "\033[3m"
# define NC       "\033[0m"
#endif // !_COLORS


template <typename T>
void print_array(const T &arr, const std::string &color, std::string text)
{
	typedef typename T::const_iterator iterator;
	std::cout << color << text;
	iterator it = arr.begin();
	for (size_t i = 0; it != arr.end(); i++)
	{
		std::cout << *it << " ";
		it++;
	}

	std::cout << NC << std::endl;
}


int	pmerge_me(char **argv);
