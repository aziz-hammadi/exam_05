#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>
class Warlock
{
private:
    Warlock();
    Warlock(const Warlock &src);
    Warlock & operator=(const Warlock &other);
    std::string name;
    std::string title;

public :
    std::string const & getName(void) const 
    {
        return name;
    }
    std::string const & getTitle(void) const {return title;}
    void setTitle(const std::string &newTitle) {this->title = newTitle;}
    Warlock(const std::string &name, const std::string &title) : name(name), title(title)
    {
        std::cout << name << ": This looks like another boring day."<<std::endl;
    }
    void introduce()const
    {
        std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl;
    }
    ~Warlock(void)
    {
        std::cout<<name<<": My job here is done!"<<std::endl;
    }
};
#endif