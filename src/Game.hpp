#ifndef STARING_CONTEST
#define STARING_CONTEST

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ScoreLoader.hpp"

class Game
{
public:
	std::vector<cv::Rect> eyes;
	
private:

	ScoreLoader m_sc;

	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Text m_text_currentScore, m_text_highScore;
	cv::CascadeClassifier m_eyeCascade;
	cv::Mat m_imgIn, m_imgRGBA;
	cv::VideoCapture m_cap = cv::VideoCapture(0);

	sf::Image m_image;
	sf::Texture m_texture;
	
	sf::Sprite m_sprite;
	sf::Font m_notoSans;

	time_t m_startTime = time(0);
	Score m_currentScore;

	time_t startTime = time(0);
	
public:

	void update();
	Game();
	void run();
};

#endif