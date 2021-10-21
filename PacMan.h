#pragma once

#include "Entity.h"

class PacMan : public Entity
{
	int eated_dots; // Кол-во съеденных монеток
	bool frame_is_null; // нулевой ли кадр
public:
	PacMan();
	void eatDot(); // Съесть точку
	int getDots(); // Получить кол-во съеденых точке
	void restart(bool contin); // При рестарте игры
};

