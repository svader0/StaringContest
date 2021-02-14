#include "Game.hpp"
#include "ScoreLoader.hpp"

Game::Game() 
{
	m_logoTexture.loadFromFile("res\\logo.png");
	m_window.create(sf::VideoMode(800, 700), "Staring Contest");
	m_notoSans.loadFromFile("res\\NotoSansJP-Medium.otf");
	m_eyeCascade.load("res\\cascade_eye.xml");
	if (m_eyeCascade.empty())
	{
		std::cout << "ERROR: could not load cascade XML\n";
	}
	if (!m_cap.isOpened())
	{
		std::cout << "Could not detect a webcam :(\n";
	}
}

/*
		run update() every frame until window exits
*/
void Game::run()
{
	while (m_window.isOpen())
	{
		update();
	}
}

void Game::update()
{
	Score m_currentScore(difftime(time(0), m_startTime));

	/*
		handle close event and restart the time if you lose
	*/
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
	}

	if (m_eyes.size() < 2)
	{
		m_startTime = time(0); // reset time
	}

	/*
		set imgIn to the webcam input and then resize/convert it to RGBA
	*/
	m_cap >> m_imgIn;
	cv::resize(m_imgIn, m_imgIn, cv::Size(800, 600));
	cv::cvtColor(m_imgIn, m_imgRGBA, cv::COLOR_BGR2RGBA);

	// save all bound boxes to vector
	m_eyeCascade.detectMultiScale(m_imgRGBA, m_eyes, 1.1, 10);

	// draw rectangles
	for (cv::Rect i : m_eyes)
	{
		cv::Scalar color(255, 255, 255, 255);

		if (m_eyes.size() < 2) {
			color = cv::Scalar(255, 0, 0, 255); //red
		}
		rectangle(m_imgRGBA, i, color, 4);
		putText(m_imgRGBA, "eye", i.tl(), cv::FONT_HERSHEY_DUPLEX, 1, color, 2);
	}

	/*
		update highscore if you beat it
	*/
	if (m_sc.getHighScore().sec <= m_currentScore.sec &&
		m_sc.getHighScore().min <= m_currentScore.min)
	{
		m_sc.setHighScore(m_currentScore);
	}

	/*
		convert OpenCV image to SFML texture and add it to the sprite
	*/
	m_image.create(m_imgRGBA.cols, m_imgRGBA.rows, m_imgRGBA.ptr());
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);

	
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(sf::Vector2f(m_window.getSize().x - m_logoSprite.getGlobalBounds().width,0));
	m_logoSprite.setScale(sf::Vector2f(0.7f, 0.7f));

	/*
		set the score text to the current scores
	*/
	m_text_highScore.setString("High Score: " + std::to_string(m_sc.getHighScore().min)
		+ std::string(" min, ")
		+ std::to_string(m_sc.getHighScore().sec)
		+ std::string(" sec"));

	m_text_currentScore.setString("Score: " + std::to_string(m_currentScore.min)
		+ std::string(" min, ")
		+ std::to_string(m_currentScore.sec)
		+ std::string(" sec"));

	/*
		set the characteristics of the text (score + highscore)
	*/
	m_text_currentScore.setFont(m_notoSans);
	m_text_currentScore.setCharacterSize(24);
	m_text_currentScore.setFillColor(sf::Color::White);
	m_text_currentScore.setPosition(5, m_window.getSize().y - 90);

	m_text_highScore.setFont(m_notoSans);
	m_text_highScore.setCharacterSize(24);
	m_text_highScore.setFillColor(sf::Color::White);
	m_text_highScore.setPosition(5, m_window.getSize().y - 50);


	/*
		clear the window, draw the objects on there, and display them.
	*/
	m_window.clear();
	
	m_window.draw(m_sprite);
	m_window.draw(m_text_currentScore);
	m_window.draw(m_text_highScore);
	m_window.draw(m_logoSprite);

	m_window.display();

}