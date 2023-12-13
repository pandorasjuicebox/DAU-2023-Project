#include "stdafx.h"
#include "Encylopedia.h"

Encyclopedia::Encyclopedia()
{
	//for (int i = 0; i < 40; i++) {
	//	articles[i] = Article(i, "This is article:" + i, 1, 0);
	//}

	int counter = 0;
	for (auto& i: articles) {
		i = Article(counter, "This is article:" + counter, 1, 0);
		counter++;
	}
}

Article Encyclopedia::GetArticle(int index)
{
	return articles.at(index);
}

void Encyclopedia::UnlockArticle(int index)
{
	//articles[index].setArticleLock(false);
	articles.at(index).setArticleLock(false);
	cout << "Article unlocked"; //comment this out later
}

void Encyclopedia::PrintArticles()
{
	//go through array and print all unlocked
}
