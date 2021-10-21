#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Entity // Класс существо
{
protected:
	float screenPosX; // позиция по х
	float screenPosY; // позиция по y
	int prev_side; // Слудующее направление движения
	float currentframe; // Текущий кадр
	float num_of_frames; // Количество кадров
	float speed; // Скорость
	int side; // Направление движения
	sf::Texture texture; // Текстура для спрайта
	sf::Sprite sprite; // Спрайт
public:
	float getScreenPosX(); // получить позицию на экране по х
	float getScreenPosY(); // получить позицию на экране по y
	void animation(int y, float time); // Анимация движения, получает сдвиг по игрику для загрузки текстур
	void render(sf::RenderWindow& window);
	void move(int side, float speed);
	void teleport(bool mode); // Телепортация
	void chose_side(int side); // Запрос на смену направления движения
	void setPrevSide(int prev_side); // Определить старую сторону движения
	int getSide(); // Получить направление движения
	int getPrevSide(); // Получить старое направление движения
	float getSpeed(); // Получить скорость
	sf::FloatRect get_global_bounds(); // Получить координаты спрайта для вычислений колюзий
};

