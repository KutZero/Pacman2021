#include "Ghost.h"

// Конструктор
Ghost::Ghost()
{
    speed = 0.15;
    side = 4; // Стоит на месте
    currentframe = 0;
    num_of_frames = 2;
    time_of_fear = 0;
    isfear = false; // Напуган ли он

    // Загрузка текстуры
    if (!texture.loadFromFile("things.png")) 
        std::cout << "Error loading mobs texture\n";
}

// Инициализация
void Ghost::init(int y)
{
    screenPosX = 180 + 20 * (y-1);
    screenPosY = 224;
    sprite.setPosition(screenPosX, screenPosY);

    sprite.setTexture(texture);
    // Определить отображаемую часть текстуры
    sprite.setTextureRect(sf::IntRect(0, y * 15, 15, 15));
    sprite.setScale(1.3, 1.3);

    help_rand = 0;
}

// Вычислить следующую сторону движения
void Ghost::compute_side(float timex)
{
    int x;
    srand(timex); // Чтобы рандомные числа были разные
    help_rand += (rand() % 3) * timex / 120 + timex/40; // Расчет времени без смены направления движения
    if (help_rand > 15)
    {
        x = rand() % 4; // Выбор следующего направления
        chose_side(x);
        help_rand -= 15; // Обнуление счетчика
    }
}

// Анимации призраков
void Ghost::ghostAnimation(float time, int state, int anim)
{
    // Вычисление номера текущего кадра
    currentframe += 0.02 * time;
    if (currentframe > num_of_frames)
    {
        currentframe -= num_of_frames;
    }

    // Если он столкнулся с пакманом в состоянии страха
    if ((state == 2) && (time_of_fear < 10))
    {
        isfear = true;
        time_of_fear = 0;
    }
    // Проигрывать анимацию страха по счетчику time_of_fear
    else if ((isfear == true) && (time_of_fear < 10))
    {
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 120, 15, 15, 15));
        time_of_fear += 0.002 * time;
    }
    // Вернуться к обычному состоянию
    else
    {
        isfear = false;
        animation(anim, time);
        time_of_fear = 0;
    }
}

// Узнать напуган ли призрак
bool Ghost::getFearState()
{
    return isfear;
}

// Определить напуган ли призрак
void Ghost::setFearState(bool fear)
{
    isfear = fear;
}

// Переинициализировать призрака
void Ghost::restart(int y)
{
    side = 4; // Стоит на месте
    currentframe = 0;
    time_of_fear = 0;
    isfear = false;
    sprite.setTextureRect(sf::IntRect(int(currentframe) * 15, y * 15, 15, 15));
    screenPosX = 180 + 20 * (y - 1);
    screenPosY = 224;
    sprite.setPosition(screenPosX, screenPosY);
    
}
