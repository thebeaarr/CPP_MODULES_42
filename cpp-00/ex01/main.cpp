/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:37:36 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/08/02 12:00:49 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
  PhoneBook phonebook;
  Contact contact;
  for (; 1;)
  {
    std::string choice;
    std::cout << "ADD, SEARCH, EXIT:" << std::endl;
    std::cin >> choice;
    if(choice.compare("ADD") == 0)
      phonebook.add_contact(phonebook.get_contact());
    else if(choice.compare("SEARCH") == 0)
      phonebook.search_contact();
    else if(choice.compare("EXIT") == 0)
      break;
    else
      std::cout << "** INVALID CHOICE" << std::endl;
  }
}