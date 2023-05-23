#pragma once

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "SpellBook.hpp"
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
    Warlock(std::string n, std::string t) : name(n), title(t)
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
        book.SpellBook::learnSpell(as);
    }
    void forgetSpell(const std::string fs)
    {
        book.SpellBook::forgetSpell(fs);
    }
    void launchSpell(std::string ls, ATarget const & target)
    {
        ASpell * tmp =
        book.SpellBook::createSpell(ls);
        tmp->launch(target);
    }

private : 
    std::map<std::string, ASpell *> b;
    SpellBook book;

};
