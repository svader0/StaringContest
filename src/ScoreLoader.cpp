#include "ScoreLoader.hpp"
#include <fstream>
#include <iostream>

void ScoreLoader::loadHighScore() 
{
	std::ifstream file;
	file.open(filePath, std::ios::in);
	int scoreBuffer;
	file >> scoreBuffer;
	file.close();

	// convert seconds into Time object (min, sec)
	m_highScore.min = scoreBuffer / 60;
	scoreBuffer = scoreBuffer % 60;
	m_highScore.sec = scoreBuffer;

};

void ScoreLoader::saveHighScore(Score &score)
{
	// convert min and seconds to just seconds
	int scoreBuffer{ (60 * score.min) + score.sec};

	// open file and save the seconds value to it
	std::ofstream file;
	file.open(filePath, std::ofstream::out | std::ofstream::trunc);
	file << std::to_string(scoreBuffer);
	file.close();

	std::cout << "File saved!";
};

Score ScoreLoader::getHighScore() {
	return m_highScore;
}

void ScoreLoader::setHighScore(Score &newHS) {
	m_highScore.min = newHS.min;
	m_highScore.sec = newHS.sec;
}

// load high score on initialization
ScoreLoader::ScoreLoader()
{ loadHighScore(); }

// save high score on deinitialization
ScoreLoader::~ScoreLoader()
{ saveHighScore(m_highScore); }