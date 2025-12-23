#include <string>
#include <exception>

class Bureaucrat : public std::exception
{
private:
    const std::string _name;
    int _grade; // 1 = highest, 150 = lowest
public:
    Bureaucrat() : _name("Unnamed"), _grade(150) {}
    Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {}
    ~Bureaucrat() noexcept {}
    const std::string& get_name() const { return _name; }
    int get_grade() const { return _grade; }

    void set_grade(int grade) { _grade = grade; }

    const char* what() const noexcept override {
        return "Bureaucrat exception";
    }
};
