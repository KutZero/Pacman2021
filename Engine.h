#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game_window.h"
#include "PacMan.h"
#include "Ghost.h"
#include <fstream>

class Engine
{
private:
	static sf::RenderWindow window; // Переменная с окном в котом будет отображаться весь контент
	static sf::Event event; // Переменная с ивентами
	Game_window game_window; // Экземпляр классса окна игровой карты
	PacMan pacman;
	Ghost ghost[4];
	Clock clock; // Для времени
	float time; // Переменная для подсчета времени
public:
	Engine();
	bool isRunning(); // Работает ли игра
	void handleEvents(); // Распределение событий
	void render(); // Рендер окна
	void handleKey(); // Обработка нажатий клавиш
	void handleMouse(); // Обработка событий мыши
	void time_count(); // Вести подсчет времени
};