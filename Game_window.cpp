#include "Game_window.h"


// �����������
Game_window::Game_window()
{
	// �������� ������ � �������� ���������
	if (!font.loadFromFile("20706.otf"))
		std::cout << "error loading font\n";
	if (!lab_texture.loadFromFile("my_labyrinth.png"))
		std::cout<< "error loading texture\n";
	// ������� ��������� �������� �� ����� 0
	dots_count = 0;

	// ������������� ��������� �� ��������� ���������� �������
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			// ��������� ���������
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
			// ��������� ���������������� �������
			index[i][j] = 1;
		}
	}
}

// ����������
Game_window::~Game_window()
{
	delete[] text;
}

// ���������� ���������� �������� � ����
void Game_window::set_quantity_of_text(int text_arr_size)
{
	this->text_arr_size = text_arr_size;
	text = new Text[text_arr_size];
}

// �������������� ������� � ����� (����� �� �������� �� ������� ���������)
bool Game_window::interactWithMap(float time, Entity& pacman, int side)
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			if ((TileMap[i].substr(j, 1) == '0') || (TileMap[i].substr(j, 1) == 's')) // ��� ������� �� ������
			{
				if (pacman.get_global_bounds().intersects(LabyrinthPieces[i][j].getGlobalBounds()))
				{
					switch (side)
					{
					case 0: // �������� �����
						pacman.move(1, pacman.getSpeed() * time);
						break;
					case 1: // �������� ����
						pacman.move(0, pacman.getSpeed() * time);
						break;
					case 2: // �������� ������
						pacman.move(3, pacman.getSpeed() * time);
						break;
					case 3: // �������� �����
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

// ���������� ����
void Game_window::stopGame(PacMan& pacman, Ghost* ghost)
{
	game_is_stop = true; // ���� �����������

	// ����������� �������� 4 ������ ��������� �������� ���������
	pacman.chose_side(4);
	for (int i = 0; i < 4; i++)
	{
		ghost[i].chose_side(4);
	}

	// ������ ��� ������/������ �� �����
	std::string line;

	std::ifstream in("HighScore.txt"); // �������� ���� ��� ������
	if (in.is_open())
	{
		getline(in, line);
	}
	in.close();// ��������� ����
	if (std::atoi(line.c_str()) < pacman.getDots()) // ���� ������� ���� ������ ������� 
	{
		line = "";
		std::ofstream out; // ����� ��� ������
		out.open("HighScore.txt"); // �������� ���� ��� ������
		if (out.is_open())
		{
			// ������ � ���� ������ �������
			out << std::to_string(pacman.getDots()) << std::endl;
		}
		out.close();
	}
	// ������� ���������� �����, ������������ �������
	set_text(1, 40, 180, "      Game Over \n Your score: " + std::to_string(pacman.getDots()), 45);

}

// ������������� ����
void Game_window::restartGame(bool contin, PacMan& pacman, Ghost* ghost)
{
	// ��������� ���������
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			// ��������� ���������
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
			// ��������� ���������������� �������
			index[i][j] = 1;
		}
	}
	// ����������������� ���������
	for (int i = 0; i < 4; i++)
	{
		ghost[i].restart(i + 1);
	}
	game_is_stop = false;

	if (contin == false) // ���� ���� �� ����� ������������ ����� ����� (���� ������ ���������� � ��������� ��� �� ���� �����)
	{
		set_text(0, 140, 5, "Score: " + '0', 25);
	}
	// ����������������� �������
	pacman.restart(contin);

	std::string line;
	std::ifstream in("HighScore.txt"); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (getline(in, line))
		{
			//first_window.set_text(2, 115, 20, "High Score: " + line, 30);
			set_text(2, 20, 5, "High Score: " + line, 25);
		}
	}
	in.close();// ��������� ����
}

// �������� ��������� ����
bool Game_window::getStopState()
{
	return game_is_stop;
}

void Game_window::set_text(int num, float posx, float posy, std::string s, int charsize, Color color)
{
	text[num].setFont(font); // �����
	text[num].setCharacterSize(charsize); // ������ ������
	text[num].setString(s); // ������
	text[num].setFillColor(color); // ����
	text[num].setPosition(posx, posy); // �������
}

// ��������� ��� ��������� � ����
int Game_window::update_window(float time, PacMan& pacman, Ghost* ghost)
{
	int state_fear; // �������� �� ��������
	///////////////////////// ��������� ������������ ������� � ��������� /////////////
	if (game_is_stop == false)
	{
		for (int i = 0; i < 4; i++)
		{
			// ������ ���������� � ���������
			if ((ghost[i].getFearState() == false) && (pacman.get_global_bounds().intersects(ghost[i].get_global_bounds())))
			{
				stopGame(pacman, ghost);
			}
			// ������ ���������� � �������� ���������
			else if ((ghost[i].getFearState() == true) && (pacman.get_global_bounds().intersects(ghost[i].get_global_bounds())))
			{
				ghost[i].teleport(true);
				ghost[i].setFearState(false);
			}
			// ������ ������ ��� �������
			else if (dots_count == 168)
			{
				dots_count = 0;
				restartGame(true, pacman, ghost);
			}
		}
	}
	else if (game_is_stop == true) // ���� ���� ����������� - ������ �� ����
	{
		return 1;
	}

	///////////////////////// ��������� �������� ������� ////////////////////////////
	pacman.move(pacman.getSide(), pacman.getSpeed() * time);
	// ���� �������� ���� ���� ���������� � �����
	if (interactWithMap(time, pacman, pacman.getSide()) == true)
	{
		// ����������� ������ ����������� ��������
		pacman.move(pacman.getPrevSide(), pacman.getSpeed() * time);
		interactWithMap(time, pacman, pacman.getPrevSide());
	}
	else
	{
		// ���������� ������ � ���������� ����������� ��������
		pacman.setPrevSide(pacman.getSide());
	}
	pacman.animation(0,time);
	state_fear = pacman_eat_something(pacman);
	pacman.teleport(false);

	///////////////////////// ��������� �������� ��������� ////////////////////////////
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

// ��������� �������� �������� ������� � �������
int Game_window::pacman_eat_something(PacMan& pacman)
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLLS; j++)
		{
			if ((TileMap[i].substr(j, 1) == ' ') && (index[i][j] == 1)) // ��� ������� � ������
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
			else if ((TileMap[i].substr(j, 1) == 'b') && (index[i][j] == 1)) // ��� ������� � �������
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

// ������ ����������� ����
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
