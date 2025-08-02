#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>


class Contact
{
  private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string dark_secret;
    std::string phone_number;
    int index ;

  public:
    void set_first_name(std::string);
    void set_last_name(std::string);
    void set_nick_name(std::string);
    void set_dark_secret(std::string);
    void set_phone_number(std::string);
    void set_index(int );

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nick_name() const;
    std::string get_dark_secret() const;
    std::string get_phone_number() const;
    int get_index() const;

    // others tools for validation or printing contents
    void print_contact_content() const;
    void valid_phone_number();
};

class PhoneBook
{
private:
  Contact contact[8];
  int index;
  int oindex;

public:
  PhoneBook();
  void add_contact(Contact var);
  void search_contact() const;
};

#endif
