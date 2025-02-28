/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:16:01 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:16:03 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	parse_vector(char **argv, std::vector<int> *vector)
{
	std::vector<int>::iterator	it = vector->begin();
	int							i = 1;
	int							j = 0;
	long						num;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (j > 10)
			return (1);
		num = atol(argv[i]);
		if (num > INT_MAX)
			return (1);
		it = vector->begin();
		while (it != vector->end())
		{
			if (*it == num)
				return (1);
			it++;
		}
		vector->push_back(num);
		i++;
	}
	return (0);
}

int	order_with_vector(char **argv, std::vector<int> *vector)
{
	if (parse_vector(argv, vector) == 1)
		return (1);

	return (0);
}

int	parse_list(char **argv, std::list<int> *list)
{
	std::list<int>::iterator	it = list->begin();
	int							i = 1;
	int							j = 0;
	long						num;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		if (j > 10)
			return (1);
		num = atol(argv[i]);
		if (num > INT_MAX)
			return (1);
		it = list->begin();
		while (it != list->end())
		{
			if (*it == num)
				return (1);
			it++;
		}
		list->push_back(num);
		i++;
	}
	return (0);
}

int	ordered_list(std::list<int> *list)
{
	std::list<int>::iterator	it = list->begin();
	std::list<int>::iterator	it2 = list->begin();
	it2++;
	while (it2 != list->end())
	{
		if (*it > *(it2))
			return (1);
		it++;
		it2++;
	}
	return (0);
}

void	second_list_step(std::list<int> *list, std::list<int> *ordered_small_pair_list, std::list<int> *big_pair_list)
{
	std::list<int>::iterator	it = list->begin();
	int							i = 0;
	std::list<int>::iterator	it1;
	std::list<int>::iterator	it2;
	int							temp;

	while (it != list->end())
	{
		if (i % 2 == 0)
		{
			std::cout << "add " << *it << " small\n";
			ordered_small_pair_list->push_back(*it);
		}
		else
		{
			std::cout << "add " << *it << " big\n";
			big_pair_list->push_back(*it);
		}
		i++;
		it++;
	}
	// it = ordered_small_pair_list->begin();
	// std::cout << "111Small orddered: ";
	// while (it != ordered_small_pair_list->end())
	// {
	// 	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << std::endl;
	
	// it = big_pair_list->begin();
	// std::cout << "111Big orddered: ";
	// while (it != big_pair_list->end())
	// {
	// 	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << std::endl;
	
	//THIS IS NOT WORKING -> DUPLICATING THINGS AND STUFF
	it1 = ordered_small_pair_list->begin();
	it2 = ordered_small_pair_list->begin();
	it2++;
	while (ordered_list(ordered_small_pair_list) != 0)
	{
		if (*it1 > *it2)
		{
			temp = *it1;
			*it1 = *it2;
			*it2 = temp;
		}
		if (it2 == ordered_small_pair_list->end())
		{
			it1 = ordered_small_pair_list->begin();
			it2 = ordered_small_pair_list->begin();
			it2++;
			continue ;
		}
		it1++;
		it2++;
	}
}

void	first_list_step(std::list<int> *list)
{
	std::list<int>				pairs;
	std::list<int>::iterator	it1 = list->begin();
	std::list<int>::iterator	it2 = list->begin();
	int							temp;
	int							i = 0;

	it2++;
	while (it2 != list->end())
	{
		if (i % 2 == 0)
		{
			if (*it1 >= *it2)
			{
				temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}
		}
		i++;
		it1++;
		it2++;
	}
}

int	order_with_list(std::list<int> *list)
{
	first_list_step(list);
	std::list<int> ordered_small_pair_list;
	std::list<int> big_pair_list;
	second_list_step(list, &ordered_small_pair_list, &big_pair_list);

	// std::list<int>::iterator	it = ordered_small_pair_list.begin();
	// while (it != ordered_small_pair_list.end())
	// {
	// 	while (it_list != list->end())
	// 	{
	// 		if (*it_list < *it)
	// 		{
	// 			ordered_small_pair.insert();
	// 		}
	// 	}
	// 	it++;
	// }

	std::list<int>::iterator	it = ordered_small_pair_list.begin();
	std::cout << "Small orddered: ";
	while (it != ordered_small_pair_list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	
	it = big_pair_list.begin();
	std::cout << "Big orddered: ";
	while (it != big_pair_list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	// ordered_small_pair.insert(it, 99);
	// it = ordered_small_pair.begin();
	// std::cout << "2222Small orddered: ";
	// while (it != ordered_small_pair.end())
	// {
	// 	std::cout << *it << " ";
	// 	it++;
	// }
	// std::cout << std::endl;
	return (0);
}

int	pmerge_me(char **argv)
{
	std::list<int>		list;
	clock_t	time_list = clock();

	if (parse_list(argv, &list) == 1)
		return (1);
	std::list<int>		temp = list;
	if (order_with_list(&list) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_list = static_cast<double>(clock() - time_list) / CLOCKS_PER_SEC * 1000;

	std::vector<int>	vector;
	clock_t	time_vector = clock();
	
	if (order_with_vector(argv, &vector) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_vector = static_cast<double>(clock() - time_vector) / CLOCKS_PER_SEC * 1000;

	std::cout << "Before: ";
	std::list<int>::iterator	it = temp.begin();
	while (it != temp.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "After: ";
	it = list.begin();
	while (it != list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << end_list << std::endl;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << end_vector << std::endl;

	return (0);
}
