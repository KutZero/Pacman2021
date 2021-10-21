#include "Engine.h"

using namespace sf;

// ������������� ����������� ���������� 
Event Engine::event;
RenderWindow Engine::window;

// �����������
Engine::Engine()
{
	// ������������� ���������
	for (int i = 0; i < 4; i++)
	{
		ghost[i].init(i+1); // ������������� ���������
	}

	// �������� ����
	window.create(VideoMode(450, 600), "PacMan Game");
	window.setFramerateLimit(60);

	// ��������� �������� ����
	game_window.set_quantity_of_text(3);
	game_window.set_text(0, 300, 5, "Score: 0", 25);
	game_window.set_text(1, 40, 180, "      Game Over \n Your score: ", 45);
	// ��������� �������� �������� ������� �� �����
	std::string line;
	std::ifstream in("HighScore.txt"); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (getline(in, line))
		{
			game_window.set_text(2, 20, 5, "High Score: " + line, 25);
		}
	}
	in.close();// ��������� ����
}

// �������� �� ������
bool Engine::isRunning()
{
	return window.isOpen();
}

// ������������� �������
void Engine::handleEvents()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;

		case Event::KeyPressed:
			// ��� ������� ������� ������� � ������� ��������� �������
			handleKey();
			break;

		case Event::MouseButtonPressed:
			// ��� ������� ������ ���� ������� � ������� ��������� ������� ������ ����
			handleMouse();
			break;
		}
	}
}

// ��������� ������� ����������
void Engine::handleKey()
{

	if (game_window.getStopState() == true)
	{
		game_window.restartGame(false, pacman, ghost);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// �������� ������� �����
		pacman.chose_side(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// �������� ������� ����
		pacman.chose_side(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// �������� ������� ������
		pacman.chose_side(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// �������� ������� �����
		pacman.chose_side(3);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game_window.stopGame(pacman, ghost); // ���������� ����
		window.close();
	}
}

// ��������� �������� ����
void Engine::handleMouse()
{
	//���� ���� �����������
	if (game_window.getStopState() == true)
	{
		game_window.restartGame(false, pacman, ghost);
	}
}

// ������� �������
void Engine::time_count()
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 2000;
}

//������ ����
void Engine::render()
{
	window.clear(Color::Black); // ������� ����
	game_window.update_window(time, pacman, ghost);
	game_window.render(window, pacman, ghost);
	window.display();
}