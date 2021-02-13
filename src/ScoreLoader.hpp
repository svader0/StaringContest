#pragma once
#include <string>


// a simple struct to hold our min and sec values
struct Score 
{
	int min{ 0 }, sec{ 0 };
	Score(int m, int s)
	{
		min = m;
		sec = s;
	}
	Score(int s)
	{
		min = s / 60;
		s = s % 60;
		sec = s;
	}
	Score() = default;
};

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