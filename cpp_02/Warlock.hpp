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
	Warlock &operator=(const Warlock &other);
	std::string name;
	std::string title;

	public:
	std::string const &getName() const
	{
		return name;
	}
	std::string const &getTitle() const
	{
		return title;
	}
	void setTitle(std::string newtitle)
	{
		this->title=newtitle;
	}
	Warlock(std::string name, std::string title):name(name), title(title)
	{
		std::cout<<name<<": This looks like another boring day."<<std::endl;
	}
	void introduce() const
	{
		std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl;
	}
	~Warlock()
	{
		std::cout<<name<<": My job here is done!"<<std::endl;
	}

	void learnSpell(ASpell * ls)
	{
		book.SpellBook::learnSpell(ls);
	}
	void forgetSpell(std::string fg)
	{
		book.SpellBook::forgetSpell(fg);
	}
	void launchSpell(std::string ls, ATarget &at)
	{
		ASpell * tmp = 
		book.SpellBook::createSpell(ls);
		if (tmp)
			tmp->launch(at);
	}
private : 
    std::map<std::string, ASpell *> b;
    SpellBook book;
};