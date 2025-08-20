#pragma once
#include <iostream>
#include <string>
#include <sstream>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string dark_secret;
    std::string phone_number;
    int index;

public:
    void set_first_name(const std::string &);
    void set_last_name(const std::string &);
    void set_nick_name(const std::string &);
    void set_dark_secret(const std::string &);
    void set_phone_number(const std::string &);
    void set_index(int);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nick_name() const;
    std::string get_dark_secret() const;
    std::string get_phone_number() const;
    int get_index() const;

    std::string truncate(const std::string &) const;
    void print_contact_content() const;
};

class PhoneBook
{
private:
    Contact contact[8];
    int index;
    int oindex;

    void assign_contact(Contact &dst, const Contact &src, int idx);

public:
    PhoneBook();

    void add_contact(const Contact &);
    void search_contact() const;
    void print_user_detail() const;
};
