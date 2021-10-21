#include "Game_window.h"


// Конструктор
Game_window::Game_window()
{
	// Загрузка шрифта и текстуры лабиринта
	if (!font.loadFromFile("20706.otf"))
		std::cout << "error loading font\n";
	if (!lab_texture.loadFromFile("my_labyrinth.png"))
		std::cout<< "error loading texture\n";
	// Монеток съеденных пакманом за раунд 0
	dots_count = 0;

	// Инициализация лабиринта на основании текстового шаблона
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			// отрисовка лабиринта
			LabyrinthPieces[i][j].setTexture(lab_texture);
			if ((TileMap[i]).substr(j, 1) == '0')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(0, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == ' ')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(16, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == '-')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(30, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == 's')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(45, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == 'b')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(61, 0, 15, 15));
			}
				
			LabyrinthPieces[i][j].setPosition(j*15*1.5, i*15*1.5+40);
			LabyrinthPieces[i][j].setScale(1.5, 1.5);
			// заполнене вспомагательного массива
			index[i][j] = 1;
		}
	}
}

// Деструктор
Game_window::~Game_window()
{
	delete[] text;
}

// Определить количество надписей в окне
void Game_window::set_quantity_of_text(int text_arr_size)
{
	this->text_arr_size = text_arr_size;
	text = new Text[text_arr_size];
}

// Взаимодействие существ и карты (чтобы не выходили за пределы лабиринта)
bool Game_window::interactWithMap(float time, Entity& pacman, int side)
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			if ((TileMap[i].substr(j, 1) == '0') || (TileMap[i].substr(j, 1) == 's')) // при встрече со стеной
			{
				if (pacman.get_global_bounds().intersects(LabyrinthPieces[i][j].getGlobalBounds()))
				{
					switch (side)
					{
					case 0: // Движение вверх
						pacman.move(1, pacman.getSpeed() * time);
						break;
					case 1: // Движение вниз
						pacman.move(0, pacman.getSpeed() * time);
						break;
					case 2: // Движение вправо
						pacman.move(3, pacman.getSpeed() * time);
						break;
					case 3: // Движение влево
						pacman.move(2, pacman.getSpeed() * time);
						break;
					}
					return true;
				}
			}
		}
	}
	return false;
}

// Остановить игру
void Game_window::stopGame(PacMan& pacman, Ghost* ghost)
{
	game_is_stop = true; // Игра остановлена

	// Направление движения 4 значит остановку движения персонажа
	pacman.chose_side(4);
	for (int i = 0; i < 4; i++)
	{
		ghost[i].chose_side(4);
	}

	// Строка для записи/чтения из файла
	std::string line;

	std::ifstream in("HighScore.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		getline(in, line);
	}
	in.close();// закрываем файл
	if (std::atoi(line.c_str()) < pacman.getDots()) // Если текущий счет больше рекорда 
	{
		line = "";
		std::ofstream out; // поток для записи
		out.open("HighScore.txt"); // окрываем файл для записи
		if (out.is_open())
		{
			// Запись в файл нового рекорда
			out << std::to_string(pacman.getDots()) << std::endl;
		}
		out.close();
	}
	// Вывести количество очков, заработанных игроком
	set_text(1, 40, 180, "      Game Over \n Your score: " + std::to_string(pacman.getDots()), 45);

}

// Перезапустить игру
void Game_window::restartGame(bool contin, PacMan& pacman, Ghost* ghost)
{
	// Отрисовка лабиринта
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			// отрисовка лабиринта
			LabyrinthPieces[i][j].setTexture(lab_texture);
			if ((TileMap[i]).substr(j, 1) == '0')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(0, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == ' ')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(16, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == '-')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(30, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == 's')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(45, 0, 15, 15));
			}
			else if ((TileMap[i]).substr(j, 1) == 'b')
			{
				LabyrinthPieces[i][j].setTextureRect(IntRect(61, 0, 15, 15));
			}

			LabyrinthPieces[i][j].setPosition(j * 15 * 1.5, i * 15 * 1.5 + 40);
			LabyrinthPieces[i][j].setScale(1.5, 1.5);
			// заполнене вспомагательного массива
			index[i][j] = 1;
		}
	}
	// Переинициализация призраков
	for (int i = 0; i < 4; i++)
	{
		ghost[i].restart(i + 1);
	}
	game_is_stop = false;

	if (contin == false) // Если игра не будет продолжаться после этого (если пакман столкнулся с призраком или из окна вышли)
	{
		set_text(0, 140, 5, "Score: " + '0', 25);
	}
	// Переинициализация пакмана
	pacman.restart(contin);

	std::string line;
	std::ifstream in("HighScore.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			//first_window.set_text(2, 115, 20, "High Score: " + line, 30);
			set_text(2, 20, 5, "High Score: " + line, 25);
		}
	}
	in.close();// закрываем файл
}

// Получить состояние игры
bool Game_window::getStopState()
{
	return game_is_stop;
}

void Game_window::set_text(int num, float posx, float posy, std::string s, int charsize, Color color)
{
	text[num].setFont(font); // Шрифт
	text[num].setCharacterSize(charsize); // Размер шрифта
	text[num].setString(s); // Строка
	text[num].setFillColor(color); // Цвет
	text[num].setPosition(posx, posy); // Позиция
}

// Прощитать все изменения в окне
int Game_window::update_window(float time, PacMan& pacman, Ghost* ghost)
{
	int state_fear; // Напуганы ли призраки
	///////////////////////// обработка столкновений пакмана и призраков /////////////
	if (game_is_stop == false)
	{
		for (int i = 0; i < 4; i++)
		{
			// Пакман столкнулся с призраком
			if ((ghost[i].getFearState() == false) && (pacman.get_global_bounds().intersects(ghost[i].get_global_bounds())))
			{
				stopGame(pacman, ghost);
			}
			// Пакман столкнулся с боящимся призраком
			else if ((ghost[i].getFearState() == true) && (pacman.get_global_bounds().intersects(ghost[i].get_global_bounds())))
			{
				ghost[i].teleport(true);
				ghost[i].setFearState(false);
			}
			// Пакман собрал все монетки
			else if (dots_count == 168)
			{
				dots_count = 0;
				restartGame(true, pacman, ghost);
			}
		}
	}
	else if (game_is_stop == true) // Если игра остановлена - дальше не идти
	{
		return 1;
	}

	///////////////////////// обработка движений пакмана ////////////////////////////
	pacman.move(pacman.getSide(), pacman.getSpeed() * time);
	// Если движение выше было направлено в стену
	if (interactWithMap(time, pacman, pacman.getSide()) == true)
	{
		// попробовать старое направление движения
		pacman.move(pacman.getPrevSide(), pacman.getSpeed() * time);
		interactWithMap(time, pacman, pacman.getPrevSide());
	}
	else
	{
		// Прировнять старое и актуальное направления движения
		pacman.setPrevSide(pacman.getSide());
	}
	pacman.animation(0,time);
	state_fear = pacman_eat_something(pacman);
	pacman.teleport(false);

	///////////////////////// обработка движений призраков ////////////////////////////
	for (int i = 0; i < 4; i++)
	{
		ghost[i].compute_side(time + i);
		ghost[i].move(ghost[i].getSide(), ghost[i].getSpeed() * time);
		if (interactWithMap(time, ghost[i], ghost[i].getSide()) == true)
		{
			ghost[i].move(ghost[i].getPrevSide(), ghost[i].getSpeed() * time);
			interactWithMap(time, ghost[i], ghost[i].getPrevSide());
		}
		else
		{
			ghost[i].setPrevSide(pacman.getSide());
		}
		ghost[i].ghostAnimation(time, state_fear, i+1);
		ghost[i].teleport(false);
	}
	return 0;
}

// Обработка поедания пакманом монеток и бонусов
int Game_window::pacman_eat_something(PacMan& pacman)
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			if ((TileMap[i].substr(j, 1) == ' ') && (index[i][j] == 1)) // при встрече с точкой
			{
				if (pacman.get_global_bounds().intersects(LabyrinthPieces[i][j].getGlobalBounds()))
				{
					LabyrinthPieces[i][j].setTextureRect(IntRect(30, 0, 15, 15));
					index[i][j] = 0;
					pacman.eatDot();
					dots_count++;
					set_text(0, 300, 5, "Score: " + std::to_string(pacman.getDots()), 25);
					return 1;
				}
			}
			else if ((TileMap[i].substr(j, 1) == 'b') && (index[i][j] == 1)) // при встрече с бонусом
			{
				if (pacman.get_global_bounds().intersects(LabyrinthPieces[i][j].getGlobalBounds()))
				{
					LabyrinthPieces[i][j].setTextureRect(IntRect(30, 0, 15, 15));
					index[i][j] = 0;
					return 2;
				}
			}
		}
	}
	return 0;
}

// Рендер содержимого окна
void Game_window::render(sf::RenderWindow& window, PacMan& pacman, Ghost* ghost)
{
	window.draw(text[0]);
	window.draw(text[2]);

	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			window.draw(LabyrinthPieces[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		ghost[i].render(window);
	}
	pacman.render(window);

	if (game_is_stop == true)
	{
		window.draw(text[1]);
	}
}
