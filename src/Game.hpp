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
	
private:

	ScoreLoader m_sc;
	sf::Image m_icon;

	sf::RenderWindow m_window;
	sf::Event m_event;
	sf::Text m_text_currentScore, m_text_highScore;

	std::vector<cv::Rect> m_eyes;
	cv::CascadeClassifier m_eyeCascade;
	cv::Mat m_imgIn, m_imgRGBA;
	cv::VideoCapture m_cap = cv::VideoCapture(0);

	sf::Texture m_logoTexture;
	sf::Sprite m_logoSprite;
	sf::Image m_image;
	sf::Texture m_texture;
	
	sf::Sprite m_sprite;
	sf::Font m_notoSans;

	time_t m_startTime = time(0);
	Score m_currentScore;
	
public:

	Game();
	void update();
	void run();
};

#endif