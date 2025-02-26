/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:15:06 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:08 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	reverse_polish_notation(char *argv)
{
	std::stack<int>	num_stack;
	int				i = 0;
	int				total;
	int				num1;
	int				num2;

	while (argv[i])
	{
		if (isdigit(argv[i]) && isdigit(argv[i + 1]))
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		if (isdigit(argv[i]))
		{
			num_stack.push(argv[i] + '0');
		}
		if (argv[i] == '+' && num_stack.size() > 2)
		{
			num1 = num_stack.top();
			num_stack.pop();
			num2 = num_stack.top();
			num_stack.pop();
			total = num1 + num2;
			num_stack.push(total);
		}
		if (argv[i] == '-' && num_stack.size() > 2)
		{
			num1 = num_stack.top();
			num_stack.pop();
			num2 = num_stack.top();
			num_stack.pop();
			total = num1 - num2;
			num_stack.push(total);
		}
		if (argv[i] == '*' && num_stack.size() > 2)
		{
			num1 = num_stack.top();
			num_stack.pop();
			num2 = num_stack.top();
			num_stack.pop();
			total = num1 * num2;
			num_stack.push(total);
		}
		if (argv[i] == '/' && num_stack.size() > 2)
		{
			num1 = num_stack.top();
			num_stack.pop();
			num2 = num_stack.top();
			num_stack.pop();
			total = num1 / num2;
			num_stack.push(total);
		}
		i++;
	}
	if (num_stack.size() > 0)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	return (0);
}