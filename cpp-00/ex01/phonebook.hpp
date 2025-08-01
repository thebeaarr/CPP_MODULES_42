#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>


class Contact
{
  private :
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string dark_secret; 
  public:
    void set_first_name(std::string);
    void set_last_name(std::string);
    void set_nick_name(std::string);
    void set_dark_secret(std::string);
    
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nick_name() const;
    std::string get_dark_secret() const;
    void show() const;
};
class PhoneBook
{
private:
  Contact contact[8];
  int index;

public:
  PhoneBook();
  void add_contact(Contact var);
  void search_contact();
};

#endif