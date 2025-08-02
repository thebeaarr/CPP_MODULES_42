#include "phonebook.hpp"

void Contact::set_first_name(std::string value) { first_name = value; }
void Contact::set_last_name(std::string value) { last_name = value; }

void Contact::set_nick_name(std::string value) { nick_name = value; }

void Contact::set_dark_secret(std::string value) { dark_secret = value; }

void Contact::set_phone_number(std::string value) { phone_number = value; }

std::string Contact::get_first_name() const { return first_name; }

std::string Contact::get_dark_secret() const { return dark_secret; }

std::string Contact::get_last_name() const { return last_name; }

std::string Contact::get_nick_name() const { return nick_name; }

std::string Contact::get_phone_number() const { return phone_number; }

PhoneBook::PhoneBook() : index(0), oindex(0) {}

void PhoneBook::add_contact(Contact var)
{
    if (var.get_dark_secret().empty() || var.get_first_name().empty() ||
        var.get_last_name().empty() || var.get_nick_name().empty() ||
        var.get_phone_number().empty())
        {
            std::cerr << "INPUT EMPTY!" << std::endl;
            return ;
        }

    if (index > 7)
    {
        contact[oindex].set_index(oindex);
        contact[oindex].set_dark_secret(var.get_dark_secret());
        contact[oindex].set_first_name(var.get_first_name());
        contact[oindex].set_last_name(var.get_last_name());
        contact[oindex].set_nick_name(var.get_nick_name());
        contact[oindex].set_phone_number(var.get_phone_number());
        oindex++;
        if (oindex > 7) oindex = 0;
    } else
    {
        contact[index].set_index(index);
        contact[index].set_dark_secret(var.get_dark_secret());
        contact[index].set_first_name(var.get_first_name());
        contact[index].set_last_name(var.get_last_name());
        contact[index].set_nick_name(var.get_nick_name());
        contact[index].set_phone_number(var.get_phone_number());
        index++;
    }
}

void Contact::set_index(int i) { index = i; }

int Contact::get_index() const { return index; }
void Contact::print_contact_content() const
{

    std::cout << index << " | " << first_name << " | " << last_name << " | " << nick_name << " | "
              << phone_number << " | " << dark_secret << std::endl;
}

void PhoneBook::search_contact() const {
        if(index == 0)
    {
        std::cerr << "PHONEBOOK is empy!!" << std::endl ;
        return ;
    }
    for (int i = 0; i < index; i++) {
        contact[i].print_contact_content();
    }
}
