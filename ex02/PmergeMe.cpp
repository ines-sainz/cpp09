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
			{
				std::cout << "Duplicated numbers" << std::endl;
				return (1);
			}
			it++;
		}
		vector->push_back(num);
		i++;
	}
	return (0);
}

int	ordered_vector(std::vector<int> *vector)
{
	std::vector<int>::iterator	it = vector->begin();
	std::vector<int>::iterator	it2 = vector->begin();

	it2++;
	while (it2 != vector->end())
	{
		if (*it > *it2)
			return (1);
		it++;
		it2++;
	}
	return (0);
}

void	recursive_sort_vector(std::vector<int> &small_pair_vector)
{
	if (small_pair_vector.size() <= 1)
		return ;
	
	std::vector<int>::iterator	half(small_pair_vector.begin());
	std::advance(half, (small_pair_vector.size() / 2));

	std::vector<int>			first_half(small_pair_vector.begin(), half);
	std::vector<int>			second_half(half, small_pair_vector.end());

	recursive_sort_vector(first_half);
	recursive_sort_vector(second_half);

	small_pair_vector.clear();

	while (!first_half.empty() && !second_half.empty())
	{
		if (first_half.front() <= second_half.front())
		{
			small_pair_vector.push_back(first_half.front());
			first_half.erase(first_half.begin());
		}
		else
		{
			small_pair_vector.push_back(second_half.front());
			second_half.erase(second_half.begin());
		}
	}
	while (!first_half.empty())
	{
		small_pair_vector.push_back(first_half.front());
		first_half.erase(first_half.begin());
	}
	while (!second_half.empty())
	{
		small_pair_vector.push_back(second_half.front());
		second_half.erase(second_half.begin());
	}
}

void	second_vector_step(std::vector<int> *vector, std::vector<int> *ordered_small_pair_vector, std::vector<int> *big_pair_vector)
{
	std::vector<int>::iterator	it = vector->begin();
	int							i = 0;

	while (it != vector->end())
	{
		if (i % 2 == 0)
			ordered_small_pair_vector->push_back(*it);
		else
			big_pair_vector->push_back(*it);
		i++;
		it++;
	}
	recursive_sort_vector(*ordered_small_pair_vector);
}

void	first_vector_step(std::vector<int> *vector)
{
	std::vector<int>::iterator	it1 = vector->begin();
	std::vector<int>::iterator	it2 = vector->begin();
	int							temp;
	int							i = 0;

	it2++;
	while (it2 != vector->end())
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

std::vector<int>::iterator	binary_search_vector(std::vector<int>::iterator start, std::vector<int>::iterator end, int number)
{
	if (start == end)
		return (start);

	std::vector<int>::iterator	half = start;
	int							dist = std::distance(start, end);

	if (dist == 1)
	{
		if (*start >= number)
			return (start);
		return (end);
	}

	std::advance(half, dist / 2);

	if (number < *half)
		return (binary_search_vector(start, half, number));
	return (binary_search_vector(half, end, number));
}

int	order_with_vector(char **argv, std::vector<int> *vector, std::vector<int> *ordered_small_pair_vector)
{
	if (parse_vector(argv, vector) == 1)
		return (1);

	first_vector_step(vector);
	std::vector<int>	big_pair_vector;
	second_vector_step(vector, ordered_small_pair_vector, &big_pair_vector);

//	ordered_small_pair_vector->insert(ordered_small_pair_vector->begin(), big_pair_vector.front());
//	big_pair_vector.erase(big_pair_vector.begin());

	for (std::vector<int>::iterator it = big_pair_vector.begin(); it != big_pair_vector.end(); it++)
	{
		std::vector<int>::iterator	pos = binary_search_vector(ordered_small_pair_vector->begin(), ordered_small_pair_vector->end(), *it);
		ordered_small_pair_vector->insert(pos, *it);
	}

//	int	first_number = *ordered_small_pair_vector->begin();
//	std::vector<int>::iterator		pos = binary_search_vector(ordered_small_pair_vector->begin(), ordered_small_pair_vector->end(), first_number);
//	ordered_small_pair_vector->erase(ordered_small_pair_vector->begin());
//	ordered_small_pair_vector->insert(pos, first_number);
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
			{
				std::cout << "Duplicated numbers" << std::endl;
				return (1);
			}
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
		if (*it > *it2)
			return (1);
		it++;
		it2++;
	}
	return (0);
}

void	recursive_sort_list(std::list<int> &small_pair_list)
{
	if (small_pair_list.size() <= 1)
		return ;

	std::list<int>::iterator	half(small_pair_list.begin());
	std::advance(half, (small_pair_list.size() / 2));

	std::list<int>				first_half(small_pair_list.begin(), half);
	std::list<int>				second_half(half, small_pair_list.end());

	recursive_sort_list(first_half);
	recursive_sort_list(second_half);

	small_pair_list.clear();

	while (!first_half.empty() && !second_half.empty())
	{
		if (first_half.front() <= second_half.front())
		{
			small_pair_list.push_back(first_half.front());
			first_half.pop_front();
		}
		else
		{
			small_pair_list.push_back(second_half.front());
			second_half.pop_front();
		}
	}
	while (!first_half.empty())
	{
		small_pair_list.push_back(first_half.front());
		first_half.pop_front();
	}
	while (!second_half.empty())
	{
		small_pair_list.push_back(second_half.front());
		second_half.pop_front();
	}
}

void	second_list_step(std::list<int> *list, std::list<int> *ordered_small_pair_list, std::list<int> *big_pair_list)
{
	std::list<int>::iterator	it = list->begin();
	int							i = 0;

	while (it != list->end())
	{
		if (i % 2 == 0)
			ordered_small_pair_list->push_back(*it);
		else
			big_pair_list->push_back(*it);
		i++;
		it++;
	}
	recursive_sort_list(*ordered_small_pair_list);
}

void	first_list_step(std::list<int> *list)
{
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

std::list<int>::iterator	binary_search_list(std::list<int>::iterator start, std::list<int>::iterator end, int number)
{
	if (start == end)
		return (start);

	std::list<int>::iterator	half = start;
	int							dist = std::distance(start, end);

	if (dist == 1)
	{
		if (*start >= number)
			return (start);
		return (end);
	}

	std::advance(half, dist / 2);

	if (number < *half)
		return (binary_search_list(start, half, number));
	return (binary_search_list(half, end, number));
}

int	order_with_list(std::list<int> *list, std::list<int> *ordered_small_pair_list)
{
	first_list_step(list);
	std::list<int> big_pair_list;
	second_list_step(list, ordered_small_pair_list, &big_pair_list);

//	ordered_small_pair_list->push_front(big_pair_list.front());
//	big_pair_list.pop_front();

	for (std::list<int>::iterator it = big_pair_list.begin(); it != big_pair_list.end(); it++)
	{
	    std::list<int>::iterator	pos = binary_search_list(ordered_small_pair_list->begin(), ordered_small_pair_list->end(), *it);
	    ordered_small_pair_list->insert(pos, *it);
	}

//	int first_number = *ordered_small_pair_list->begin();
//	std::list<int>::iterator		pos = binary_search_list(ordered_small_pair_list->begin(), ordered_small_pair_list->end(), first_number);
//	ordered_small_pair_list->pop_front();
//	ordered_small_pair_list->insert(pos, first_number);

	return (0);
}

int	pmerge_me(char **argv)
{
	std::list<int>		list;
	std::list<int>		list_ordered;
	clock_t	time_list = clock();

	if (parse_list(argv, &list) == 1)
		return (1);
	std::list<int>		temp = list;
	if (order_with_list(&list, &list_ordered) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_list = static_cast<double>(clock() - time_list) / CLOCKS_PER_SEC * 1000;

	std::vector<int>	vector;
	std::vector<int>	vector_ordered;
	clock_t	time_vector = clock();
	if (order_with_vector(argv, &vector, &vector_ordered) == 1)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	double	end_vector = static_cast<double>(clock() - time_vector) / CLOCKS_PER_SEC * 1000;

	std::cout << "Before: ";
	std::list<int>::iterator	it = temp.begin();
	int							breaker = 0;
	int							i = 0;
	if (temp.size() > 5)
		breaker = 1;
	while (it != temp.end())
	{
		if (breaker == 1 && i == 4)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		it++;
		i++;
	}
	std::cout << std::endl;
	std::cout << "After: ";
	it = list_ordered.begin();
	breaker = 0;
	i = 0;
	if (list_ordered.size() > 5)
		breaker = 1;
	while (it != list_ordered.end())
	{
		if (breaker == 1 && i == 4)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
		it++;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << end_list << std::endl;
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << end_vector << std::endl;

	return (0);
}
