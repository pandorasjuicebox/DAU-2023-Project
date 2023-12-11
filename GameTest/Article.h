#pragma once


#include <string>

class Article {
	//For now: hardcoded Article data for encyclopedia
	//Future: Read it through a txt
	//Articles accessed by number

public: 
	Article();
	std::string GetDescription(int index);

private:
	std::string description; //flavour text
	int articleNumber = 0;
	int effectOnEnemy = 0;
	int effectOnPlayer = 0;
};