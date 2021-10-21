#pragma once

#include "SFML/Graphics.hpp"
#include "PacMan.h"
#include "Ghost.h"
#include <fstream>

using namespace sf;

class Game_window // Класс окна игры
{
	sf::Texture lab_texture; // Текстура для фона
	static const int NUM_ROWS = 22; // Количество строк в шаблоне карты
	static const int NUM_COLLS = 20; // Количество столбцов в шаблоне карты
	int index[NUM_ROWS][NUM_COLLS]; // Массив чтобы не считать одну точку несколько раз
	bool game_is_stop; // игра закончена
	int dots_count; // количество точек, съеденных пакманом за раунд
	Text* text; // для динамического массива text
	int text_arr_size; // Размер массива надписей
	Font font; // Для шрифта
public:
	Game_window(); // Конструктор
	~Game_window(); // Деструктор
	void render(sf::RenderWindow& window, PacMan& pacman, Ghost *ghost); // Рендер всего в окне
	void set_quantity_of_text(int text_arr_size); // Задать кол-во надписей на странице
	void stopGame(PacMan& pacman, Ghost* ghost); // Игра завершилась
	void restartGame(bool contin, PacMan& pacman, Ghost* ghost); // Перезагрузка игры полностью или после съедения всех точек
	int update_window(float time, PacMan& pacman, Ghost* ghost); // Просчитать все действия в окне (движения пакмана, призраков и тд)
	int pacman_eat_something(PacMan& pacman);
	bool interactWithMap(float time, Entity& pacman, int side); // Не выезжать за границы лабиринта
	bool getStopState(); // Получить состояние игры (работает/ остановлена)
	void set_text(int num, float posx, float posy, std::string s, int charsize, Color color = Color::White);

	sf::Sprite LabyrinthPieces[NUM_ROWS][NUM_COLLS]; // Двумерный массив спрайтов для отрисовки лабиринта
	std::string TileMap[NUM_ROWS] = { // Текстовый шаблон лабиринта
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