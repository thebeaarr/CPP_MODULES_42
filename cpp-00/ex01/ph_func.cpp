#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>


void Contact::set_first_name(const std::string &value) { first_name = value; }
void Contact::set_last_name(const std::string &value) { last_name = value; }
void Contact::set_nick_name(const std::string &value) { nick_name = value; }
void Contact::set_dark_secret(const std::string &value) { dark_secret = value; }
void Contact::set_phone_number(const std::string &value) { phone_number = value; }
void Contact::set_index(int i) { index = i; }

std::string Contact::get_first_name() const { return first_name; }
std::string Contact::get_last_name() const { return last_name; }
std::string Contact::get_nick_name() const { return nick_name; }
std::string Contact::get_dark_secret() const { return dark_secret; }
std::string Contact::get_phone_number() const { return phone_number; }
int Contact::get_index() const { return index; }

std::string Contact::truncate(const std::string &str) const {
    return (str.length() > 10) ? str.substr(0, 9) + '.' : str;
}

void Contact::print_contact_content() const {
    std::cout << std::setw(10) << index << " | "
              << std::setw(10) << truncate(first_name) << " | "
              << std::setw(10) << truncate(last_name) << " | "
              << std::setw(10) << truncate(nick_name) << std::endl;
}


PhoneBook::PhoneBook() : index(0), oindex(0) {}

void PhoneBook::assign_contact(Contact &dst, const Contact &src, int idx) {
    dst.set_index(idx);
    dst.set_dark_secret(src.get_dark_secret());
    dst.set_first_name(src.get_first_name());
    dst.set_last_name(src.get_last_name());
    dst.set_nick_name(src.get_nick_name());
    dst.set_phone_number(src.get_phone_number());
}

void PhoneBook::add_contact(const Contact &var) {
    if (var.get_dark_secret().empty() || var.get_first_name().empty() ||
        var.get_last_name().empty() || var.get_nick_name().empty() ||
        var.get_phone_number().empty()) {
        std::cerr << "Error: One or more fields are empty. Contact not saved.\n";
        return;
    }

    if (index > 7) { // overwrite oldest
        assign_contact(contact[oindex], var, oindex);
        oindex = (oindex + 1) % 8;
    } else {
        assign_contact(contact[index], var, index);
        index++;
    }
}

void PhoneBook::search_contact() const {
    if (index == 0) {
        std::cerr << "📭 No contacts stored.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First Name" << " | "
              << std::setw(10) << "Last Name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < ((index > 8) ? 8 : index); i++)
        contact[i].print_contact_content();

    print_user_detail();
}

void PhoneBook::print_user_detail() const {
    std::cout << "Enter contact index: ";
    std::string input;
    if (!std::getline(std::cin, input)) {
        std::cout << "Input error." << std::endl;
        return;
    }

    std::stringstream str(input);
    int index_user;
    if (!(str >> index_user) || !str.eof()) {
        std::cout << "Invalid number format." << std::endl ;
        return;
    }

    if (index_user < 0 || index_user >= ((index > 8) ? 8 : index)) {
        std::cout << "No contact found at this index." << std::endl;
        return;
    }

    const Contact &c = contact[index_user];
    std::cout << "\nContact Details:" << std::endl; 
    std::cout << "First Name: " << c.get_first_name() << std::endl ;
    std::cout << "Last Name: " << c.get_last_name() << std::endl;
    std::cout << "Nickname: " << c.get_nick_name() << std::endl;
    std::cout << "Phone Number: " << c.get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << c.get_dark_secret() << std::endl;
}
