#pragma once

#include "Entity.h"
#include <cstdlib> // для функций rand() и srand()


class Ghost : public Entity
{
	float help_rand; // Счетчик для смены стороны движения раз в промежуток времени
	float time_of_fear; // Время испуга
	bool isfear; // Испуган ли он
	bool death_of_fear; // Умирал ли он в состоянии страха
public:
	Ghost();
	void init(int y); // инициализация
	void compute_side(float timex); // Решить в какую сторону идти призраку
	void ghostAnimation(float time, int state, int anim); // Все анимации призраков
	bool getFearState(); // Напуган ли призрак
	void setFearState(bool fear); // Назначить состояние страха
	void restart(int y); // При перезапуске игры
};

