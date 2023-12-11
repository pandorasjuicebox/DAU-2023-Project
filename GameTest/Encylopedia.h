#pragma once
#include "Article.h"

	//For now: hardcoded Article data for encyclopedia
	//Future: Read it through a txt
class Encyclopedia {
public:
	Encyclopedia();

private:
	Article* articles;
};