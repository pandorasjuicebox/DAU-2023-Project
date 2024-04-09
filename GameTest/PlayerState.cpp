#include "stdafx.h"
#include "PlayerState.h"

void PlayerState::ResetPlayerStats()
{
	playerLives = PLAYER_LIVES_DEFAULT;
	score = 0;
}

void PlayerState::AddLife()
{
	if (playerLives < PLAYER_LIVES_DEFAULT) {
		playerLives++;
	}
}

void PlayerState::RemoveLife()
{
	if (playerLives > 0) {
		playerLives--;
	}
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

int PlayerState::GetPesonalBest()
{
	return personalBest;
}

