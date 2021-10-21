#pragma once

#include "SFML/Graphics.hpp"
#include "PacMan.h"
#include "Ghost.h"
#include <fstream>

using namespace sf;

class Game_window // ����� ���� ����
{
	sf::Texture lab_texture; // �������� ��� ����
	static const int NUM_ROWS = 22; // ���������� ����� � ������� �����
	static const int NUM_COLLS = 20; // ���������� �������� � ������� �����
	int index[NUM_ROWS][NUM_COLLS]; // ������ ����� �� ������� ���� ����� ��������� ���
	bool game_is_stop; // ���� ���������
	int dots_count; // ���������� �����, ��������� �������� �� �����
	Text* text; // ��� ������������� ������� text
	int text_arr_size; // ������ ������� ��������
	Font font; // ��� ������
public:
	Game_window(); // �����������
	~Game_window(); // ����������
	void render(sf::RenderWindow& window, PacMan& pacman, Ghost *ghost); // ������ ����� � ����
	void set_quantity_of_text(int text_arr_size); // ������ ���-�� �������� �� ��������
	void stopGame(PacMan& pacman, Ghost* ghost); // ���� �����������
	void restartGame(bool contin, PacMan& pacman, Ghost* ghost); // ������������ ���� ��������� ��� ����� �������� ���� �����
	int update_window(float time, PacMan& pacman, Ghost* ghost); // ���������� ��� �������� � ���� (�������� �������, ��������� � ��)
	int pacman_eat_something(PacMan& pacman);
	bool interactWithMap(float time, Entity& pacman, int side); // �� �������� �� ������� ���������
	bool getStopState(); // �������� ��������� ���� (��������/ �����������)
	void set_text(int num, float posx, float posy, std::string s, int charsize, Color color = Color::White);

	sf::Sprite LabyrinthPieces[NUM_ROWS][NUM_COLLS]; // ��������� ������ �������� ��� ��������� ���������
	std::string TileMap[NUM_ROWS] = { // ��������� ������ ���������
	"00000000000000000000",
	"0        00        0",
	"0b00 000 00 000 00b0",
	"0 00 000 00 000 00 0",
	"0                  0",
	"0 00 0 000000 0 00 0",
	"0    0   00   0    0",
	"0000 000 00 000 0000",
	"---0 0--------0 0---",
	"0000 0-00ss00-0 0000",
	"      -0----0-      ",
	"0000 0-000000-0 0000",
	"---0 0--------0 0---",
	"0000 0 000000 0 0000",
	"0      0 00 0      0",
	"0 00 000 00 000 00 0",
	"0b 0            0 b0",
	"00 0 0 000000 0 0 00",
	"0    0   00   0    0",
	"0 000000 00 000000 0",
	"0                  0",
	"00000000000000000000",
	};
};