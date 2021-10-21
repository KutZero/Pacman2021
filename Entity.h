#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Entity // ����� ��������
{
protected:
	float screenPosX; // ������� �� �
	float screenPosY; // ������� �� y
	int prev_side; // ��������� ����������� ��������
	float currentframe; // ������� ����
	float num_of_frames; // ���������� ������
	float speed; // ��������
	int side; // ����������� ��������
	sf::Texture texture; // �������� ��� �������
	sf::Sprite sprite; // ������
public:
	float getScreenPosX(); // �������� ������� �� ������ �� �
	float getScreenPosY(); // �������� ������� �� ������ �� y
	void animation(int y, float time); // �������� ��������, �������� ����� �� ������ ��� �������� �������
	void render(sf::RenderWindow& window);
	void move(int side, float speed);
	void teleport(bool mode); // ������������
	void chose_side(int side); // ������ �� ����� ����������� ��������
	void setPrevSide(int prev_side); // ���������� ������ ������� ��������
	int getSide(); // �������� ����������� ��������
	int getPrevSide(); // �������� ������ ����������� ��������
	float getSpeed(); // �������� ��������
	sf::FloatRect get_global_bounds(); // �������� ���������� ������� ��� ���������� �������
};

