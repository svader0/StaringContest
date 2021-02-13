#pragma once
#include <string>
#include "Score.hpp"

class ScoreLoader
{
private:
	Score m_highScore{ 0, 0 };
	const char * filePath = "res\\highscore.dat";
public:

	void loadHighScore();
	void saveHighScore(Score &score);

	void setHighScore(Score &newHS);
	Score getHighScore();

	ScoreLoader();
	~ScoreLoader();
};