#include "stdafx.h"
#include "PlayerState.h"

void PlayerState::ResetPlayerStats()
{
	playerLives = 3;
}

void PlayerState::AddLife()
{
	playerLives++;
}

void PlayerState::RemoveLife()
{
	playerLives--;
}

void PlayerState::AddScore(int amount)
{
	score += amount;
}

void PlayerState::SetPersonalBest(int amount)
{
	if (personalBest < amount) {
		personalBest = amount;
	}
}

int PlayerState::GetLives()
{
	return playerLives;
}

int PlayerState::GetScore()
{
	return score;
}
