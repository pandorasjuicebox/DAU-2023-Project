#include "stdafx.h"
#include "Encylopedia.h"

Encyclopedia::Encyclopedia()
{
	for (int i = 0; i < 40; i++) {
		articles[i] = Article(i, "This is article:" + i, 1, 0);
	}
}

Article Encyclopedia::GetArticle(int index)
{
	return articles[index];
}

void Encyclopedia::UnlockArticle(int index)
{
	articles[index].setArticleLock(false);
	std::cout << "Article unlocked"; //comment this out later
}

void Encyclopedia::PrintArticles()
{
	//go through array and print all unlocked
}
