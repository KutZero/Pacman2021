#include "PacMan.h"

// Конструктор
PacMan::PacMan()
{
    screenPosX = 50; 
    screenPosY = 64;
    num_of_frames = 3;
    currentframe = 0;
	speed = 0.2;
    side = 4; // Стоит на месте
    eated_dots = 0;
    frame_is_null = false;

    // Загрузка текстуры
    if (!texture.loadFromFile("things.png"))
        std::cout << "Error loading mobs texture\n";

    // Настройка спрайта
	sprite.setTexture(texture);
	sprite.setPosition(screenPosX, screenPosY);
	sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
    sprite.setScale(1.2,1.2);
}

// Съесть монетку
void PacMan::eatDot()
{
    eated_dots++;
}

// Получить кол-во съеденных монеток
int PacMan::getDots()
{
    return eated_dots;
}

// Переинициализировать пакмана
void PacMan::restart(bool contin) // Перезагрузка пакмана с параметром (со сбросом съеденных монет и без)
{
    screenPosX = 50;
    screenPosY = 64;
    currentframe = 0;
    speed = 0.2;
    side = 4; // Стоит на месте
    if (contin == false) // Если игра не будет продолжаться - обнулить монетки
    {
        eated_dots = 0;
    }
    frame_is_null = false;

    sprite.setPosition(screenPosX, screenPosY);
    sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
}
