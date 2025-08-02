/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <mlakhdar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:37:36 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/08/02 02:30:56 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
  PhoneBook phonebook;
  while(1)
  {
    int choice(0);
    std::cout << "PLEASE ENTER A VALID NUMBER:" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
      phonebook.add_contact(phonebook.get_contact());
      break;
    case 2:
      phonebook.search_contact();
      break;
    case 3:
      return 0;
      break;
    default:
      std::cout << "unvalid choice" << std::endl;
      break;
    }
  }
}