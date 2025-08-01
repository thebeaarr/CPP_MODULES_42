/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_func.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:45:59 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/08/01 23:51:33 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::set_first_name(std::string value)
{
    first_name = value;
}
void Contact::set_last_name(std::string value)
{
    last_name = value;
}

void Contact::set_nick_name(std::string value)
{
    nick_name = value;
}

void Contact::set_dark_secret(std::string value)
{
    dark_secret = value;
}

std::string Contact::get_first_name() const
{
    return first_name;
}

std::string Contact::get_dark_secret() const
{
    return dark_secret;
}

std::string Contact::get_last_name() const
{
    return last_name;
}

std::string Contact::get_nick_name() const
{
    return nick_name;
}

