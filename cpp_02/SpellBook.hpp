#pragma once

#include "SpellBook.hpp"
#include <map>
#include <string>
#include "ASpell.hpp"
class SpellBook
{
    public :
    SpellBook(){}
    ~SpellBook(){}
    private :
    SpellBook(const SpellBook &src);
    SpellBook &operator=(const SpellBook &other);

    public:
    void learnSpell(ASpell* ls)
    {
        b.insert(std::make_pair(ls->getName(), ls));
    }
    void forgetSpell(std::string const & fg)
    {
        std::map<std::string, ASpell*> ::iterator it = b.find(fg);
        if (it == b.end())
            return;
        else
            b.erase(it);
    }
    ASpell* createSpell(std::string const &cs)
    {
        std::map<std::string, ASpell *> ::iterator it = b.find(cs);
        if (it == b.end())
            return NULL;
        else
            return (*(*it).second).clone();
    }

    private : 
    std::map<std::string, ASpell *> b;
};