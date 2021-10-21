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
	static sf::RenderWindow window; // ���������� � ����� � ����� ����� ������������ ���� �������
	static sf::Event event; // ���������� � ��������
	Game_window game_window; // ��������� ������� ���� ������� �����
	PacMan pacman;
	Ghost ghost[4];
	Clock clock; // ��� �������
	float time; // ���������� ��� �������� �������
public:
	Engine();
	bool isRunning(); // �������� �� ����
	void handleEvents(); // ������������� �������
	void render(); // ������ ����
	void handleKey(); // ��������� ������� ������
	void handleMouse(); // ��������� ������� ����
	void time_count(); // ����� ������� �������
};