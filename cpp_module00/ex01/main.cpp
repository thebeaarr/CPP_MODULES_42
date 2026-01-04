#include <string>
int main() {
    PhoneBook phonebook;

    while (true) {
        std::string choice;
        std::cout << std::endl << "ADD, SEARCH, EXIT:" << std::endl;

        if(!std::getline(std::cin, choice))
          break;

        if (choice == "ADD") {
            Contact var;
            std::string str;
            // first name
            std::cout << "first name: ";
            if(!std::getline(std::cin, str))
              break;
            var.set_first_name(str);
            // last name
            std::cout << "last name: ";
            if(!std::getline(std::cin, str))
              break;
            var.set_last_name(str);

            // nick name
            std::cout << "nick name: ";
            if(!std::getline(std::cin, str))
              break;
            var.set_nick_name(str);

            // phone number
            std::cout << "phone number: ";
            if(!std::getline(std::cin, str))
              break;
            var.set_phone_number(str);

            // dark secret
            std::cout << "dark secret: ";
            if(!std::getline(std::cin, str))
              break;
            var.set_dark_secret(str);
            phonebook.add_contact(var);
        } else if (choice == "SEARCH")
            phonebook.search_contact();
        else if (choice == "EXIT")
            break;
        else
            std::cerr << "** INVALID CHOICE" << std::endl;
        }
    
    std::cout << std::endl << "goodbye!" << std::endl;
}
