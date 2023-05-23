#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
class Warlock
{
    Warlock();
    Warlock(const Warlock &src);
    Warlock & operator=(const Warlock &other);

    std::string name;
    std::string title;

public :
    std::string getName(void) const {return name;}
    std::string getTitle(void) const {return title;}
    void setTitle(const std::string &newTitle) {this->title = newTitle;}
    Warlock(std::string name, std::string title) : name(name), title(title)
    {
        std::cout << name << ": This looks like another boring day."<<std::endl;
    }
    void introduce()const
    {
        std::cout<<name<<": I am "<<name<<","<<title<<"!"<<std::endl;
    }
    ~Warlock(void)
    {
        std::cout<<name<<": My job here is done!"<<std::endl;
    }

    void learnSpell(ASpell *as)
    {
        b.insert(std::make_pair(as->getName(), as));
    }
    void forgetSpell(const std::string fs)
    {
        std::map<std::string, ASpell*> ::iterator it(b.find(fs));
        if (it == b.end())
            return;
        else
            b.erase(it);
    }
    void launchSpell(std::string ls, ATarget const & target)
    {
        std::map<std::string, ASpell*> ::iterator it(b.find(ls));
        if (it == b.end())
            return;
        else
            (*it).second->launch(target);
    }
private : 
    std::map<std::string, ASpell *> b;

};
