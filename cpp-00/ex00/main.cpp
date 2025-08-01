/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar < mlakhdar@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:00:11 by mlakhdar          #+#    #+#             */
/*   Updated: 2025/08/01 20:24:14 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc , char **argv)
{
  if(argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
    for (int i = 1; i < argc; i++)
    {
      for (int j = 0; argv[i][j]; j++)
      {
        argv[i][j] = std::toupper(argv[i][j]);
        std::cout << argv[i][j];
      }
    }
  }
}
