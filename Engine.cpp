#include "Engine.h"

using namespace sf;

// Инициализация статических переменных 
Event Engine::event;
RenderWindow Engine::window;

// Конструктор
Engine::Engine()
{
	// Инициализация призраков
	for (int i = 0; i < 4; i++)
	{
		ghost[i].init(i+1); // Инициализация призраков
	}

	// Создание окна
	window.create(VideoMode(450, 600), "PacMan Game");
	window.setFramerateLimit(60);

	// Настройка игрового окна
	game_window.set_quantity_of_text(3);
	game_window.set_text(0, 300, 5, "Score: 0", 25);
	game_window.set_text(1, 40, 180, "      Game Over \n Your score: ", 45);
	// Получение значения прошлого рекорда из файла
	std::string line;
	std::ifstream in("HighScore.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			game_window.set_text(2, 20, 5, "High Score: " + line, 25);
		}
	}
	in.close();// закрываем файл
}

// Работает ли движок
bool Engine::isRunning()
{
	return window.isOpen();
}

// Распределение ивентов
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
			// при нажатой клавише переход в функцию обработки нажатий
			handleKey();
			break;

		case Event::MouseButtonPressed:
			// при нажатой кнопке мыши переход в функцию обработки нажатий кнопок мыши
			handleMouse();
			break;
		}
	}
}

// Обработка нажатий клавиатуры
void Engine::handleKey()
{

	if (game_window.getStopState() == true)
	{
		game_window.restartGame(false, pacman, ghost);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		// Движение пакмана вверх
		pacman.chose_side(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		// Движение пакмана вниз
		pacman.chose_side(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// Движение пакмана вправо
		pacman.chose_side(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// Движение пакмана влево
		pacman.chose_side(3);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		game_window.stopGame(pacman, ghost); // Остановить игру
		window.close();
	}
}

// Обработка действий мыши
void Engine::handleMouse()
{
	//Если игра остановлена
	if (game_window.getStopState() == true)
	{
		game_window.restartGame(false, pacman, ghost);
	}
}

// Подсчет времени
void Engine::time_count()
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 2000;
}

//Рендер окон
void Engine::render()
{
	window.clear(Color::Black); // Очистка окна
	game_window.update_window(time, pacman, ghost);
	game_window.render(window, pacman, ghost);
	window.display();
}