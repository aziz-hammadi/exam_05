#pragma once

# include <map>
# include "ASpell.hpp"

class SpellBook 
{
	public :
	SpellBook(){}
	~SpellBook(){}

	private :
	SpellBook(const SpellBook &src);
	SpellBook &operator=(const SpellBook &other);

	public :
	void learnSpell(ASpell*spell)
	{
		book.insert(std::make_pair(spell->getName(), spell));
	}
	void forgetSpell(std::string const &spell)
	{
		std::map<std::string, ASpell *>::iterator it(book.find(spell));
		if (it == book.end())
			return;
		else
			book.erase(it);
	}
	ASpell* createSpell(std::string const &spell)
	{
		std::map<std::string, ASpell *>::iterator it(book.find(spell));
		if (it == book.end())
			return NULL;
		else
			return (*(*it).second).clone();
	}
	std::map<std::string, ASpell *> book;
};
