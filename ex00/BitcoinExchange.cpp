/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:13:49 by isainz-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:13:51 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*int	check_line(std::string lines, std::string key, std::string value)
{
	int	pos1;
	int	pos2;
	std::string	year;
	std::string	month;
	std::string	day;

	pos1 = lines.find('-');
	year = lines.substr(0, pos1);
	if (lines.length() != 4 )
	{
	}
}*/

int	check_input_file(std::ifstream *fileTxt, std::map<std::string, std::string>& csv_map)
{
	std::string	key;
	std::string	value;
	int			separator;
	std::string	lines;
	long		value_long;
	float		csv_value = 0;
	std::map<std::string, std::string>::iterator it;

	std::getline(*fileTxt, lines);
	while (std::getline(*fileTxt, lines))
	{
		separator = lines.find(" | ");
		if (separator < 0)
		{
			std::cout << "Error: bad input => " << lines << std::endl;
			continue ;
		}
		key = lines.substr(0, separator);
		value = lines.substr(separator + 3);
		if (value.length() > 10)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		value_long = std::atol(value.c_str());
		if (value_long < 0 || value_long > INT_MAX)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		it = csv_map.find(key);
		csv_value = atol(it.f);
		std::cout << key << " => " << value << " = " << csv_value << std::endl;
	}
	(void)csv_map;
	return (0);
/*	std::map<std::string, std::string>::iterator it = csv_map.begin();

	while (it !=  csv_map.end())
	{
		std::cout << "" << it->first << "," << it->second << std::endl;
		++it;
	}*/
}

int	set_csv_file(std::map<std::string, std::string>& csv_map, std::ifstream *fileCsv)
{
	std::string	key;
	std::string	value;
	int			comma_pos;
	std::string	lines;

	std::getline(*fileCsv, lines);
	while (std::getline(*fileCsv, lines))
	{
		comma_pos = lines.find(',');
		if (comma_pos < 0)
			return (1);

		key = lines.substr(0, comma_pos);
		value = lines.substr(comma_pos + 1);
		csv_map[key] = value;
	}
	return (0);
}

int	BitcoinExchange(char **argv)
{
	std::ifstream	fileTxt;
	std::ifstream	fileCsv;
	std::map<std::string, std::string> csv_map;

	fileTxt.open(argv[1], std::ios::in);
	if (!fileTxt.is_open())
	{
		std::cout << "Can't open txt file" << std::endl;
		return (1);
	}
	fileCsv.open("data.csv", std::ios::in);
	if (!fileCsv.is_open())
	{
		fileTxt.close();
		std::cout << "Can't open csv file" << std::endl;
		return (1);
	}
	if (set_csv_file(csv_map, &fileCsv) == 1)
	{
		fileCsv.close();
		fileTxt.close();
		return (1);
	}
	if (check_input_file(&fileTxt, csv_map) == 1)
	{
		fileCsv.close();
		fileTxt.close();
		return (1);
	}
	return (0);
}
