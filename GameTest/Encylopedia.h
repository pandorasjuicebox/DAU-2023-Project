#pragma once

#include "stdafx.h"
#include "Article.h"
#include <iostream>
#include <array>
using namespace std;

	//For now: hardcoded Article data for Encyclopedia
	//Future: Read it through a txt
class Encyclopedia {
public:
	Encyclopedia();
	Article GetArticle(int index);

	void UnlockArticle(int index);
	void PrintArticles(); //prints out all unlocked

private:
	//Article articles[40];
	array<Article, 40> articles;
};