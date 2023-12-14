#include "stdafx.h"
#include "Encylopedia.h"

Encyclopedia::Encyclopedia(int type)
{
	//for (int i = 0; i < 40; i++) {
	//	articles[i] = Article(i, "This is article:" + i, 1, 0);
	//}
	//int input = type;
	
	if (type == 1) { //Player
		int counter = 0;
		for (auto& i : articles) {
			i = Article(counter, "This is article:" + counter, 1, 0, 0, false, false);;
			counter++;
		}
	}
	else if (type == 2) { //Enemy Type 1
		articles.at(0) = Article(0, "Stab [ ] once per round.", 0, 0, 0, false, false);
		articles.at(1) = Article(1, "Inflict [ ] even-numbered damage.", 0, 0, 0, true, false);

	}
	else if (type == 3) { //Enemy Type 2

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
