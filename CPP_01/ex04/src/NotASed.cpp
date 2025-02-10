/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NotASed.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:16:59 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/10 13:34:18 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/NotASed.hpp"

static std::string replaceSubstring(std::string str, const std::string& target, const std::string& replacement)
{	
	size_t pos;
	size_t prevPos;
	std::string result;
	
	if (target.empty())
		return (str);

	pos = 0;
	prevPos = 0;
	while ((pos = str.find(target, pos)) != std::string::npos)
	{
		result += str.substr(0, pos);
		result += replacement;
		pos += target.length(); 
		str = str.substr(pos);
	}
	result += str;
	return (result);
}
	
NotASed::NotASed( const std::string& input_file, const std::string& s1, const std::string& s2)
{
	std::string out_name;

	_input.open(input_file.c_str(), std::fstream::in);
	if (_input.fail())
	{
		std::cerr	<< "\033[1;31m" << "Error: cannot open the input file.\n" << "\033[0m" 
					<< "> Ensure the file exists. and try again.\n" << std::endl;
		return ;
	}
	out_name = input_file + ".replace";
	_output.open(out_name.c_str(), std::fstream::out | std::fstream::trunc);
	if (_output.fail())
	{
		std::cerr	<< "\033[1;31m" << "Error: cannot open the output file.\n" << "\033[0m"
					<< "> Ensure you have write permissions.\n" << std::endl;
		_input.close();
		return ;
	}
	_replacing(s1, s2);
	_output.close();
	_input.close();
}

NotASed::~NotASed( void )
{
}

void	NotASed::_replacing( const std::string& s1, const std::string& s2 )
{
	std::string	line;
	std::string new_line;
	bool		firstLine;

	firstLine = true;
	while (std::getline(this->_input, line))
	{
		if (!firstLine)
			this->_output << '\n';
		firstLine = false;
		new_line = replaceSubstring(line, s1, s2);
		this->_output << new_line;
	}
}