#include "Entity.h"

// Получить позицию по х
float Entity::getScreenPosX()
{
    return screenPosX;
}

// Получить позицию по у
float Entity::getScreenPosY()
{
    return screenPosY;
}

// Анимация существа
void Entity::animation(int y, float time)
{
    // Расчет текущего кадра
    currentframe += 0.02 * time;
    if (currentframe > num_of_frames)
    {
    	currentframe -= num_of_frames;
    }

    switch (side) // Выбор анимации
    {
    case 0: // Движение вверх
        // В зависимости от номера кадра и поданного отступа выбирается кадр анимации
        //у - отступ
        //15 - размер каждой одиночной текстуры персонажа на общей текстуре
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15, y * 15, 15, 15));
        break;
    case 1: // Движение вниз
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames,  y * 15, 15, 15));
        break;
    case 2: // Движение вправо
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames * 3, y * 15, 15, 15));
        break;
    case 3: // Движение влево
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames * 2, y * 15, 15, 15));
        break;
    }
}

// Отрисовка спрайта
void Entity::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

//Движение персонажа
//side - направление
//speed - скорость
void Entity::move(int side, float speed)
{
    switch (side)
    {
    case 0: // Движение вверх
        sprite.move(0, -speed);
        screenPosY -= speed;
        break;
    case 1: // Движение вниз
        sprite.move(0, speed);
        screenPosY += speed;
        break;
    case 2:  // Движение вправо
        sprite.move(speed, 0);
        screenPosX += speed;
        break;
    case 3:  // Движение влево
        sprite.move(-speed, 0);
        screenPosX -= speed;
        break;
    }
}

// Телепортация персонажа
void Entity::teleport(bool mode)
{
    // Если он зашел в левый тоннель
    if (screenPosX < 15)
    {
        screenPosX = 420;
        screenPosY = 266.415588;
        sprite.setPosition(screenPosX, screenPosY);
    }
    // Если он зашел в правый тоннель
    else if (screenPosX > 430)
    {
        screenPosX = 20;
        screenPosY = 266.415588;
        sprite.setPosition(screenPosX, screenPosY);
    }
    // Если это испуганный призрак, встретившийся с пакманом
    else if (mode == true)
    {
        screenPosX = 180;
        screenPosY = 228;
        sprite.setPosition(screenPosX, screenPosY);
    }
}

void Entity::chose_side(int side) // Посылаем запрос на изменение стороны движения
{
    prev_side = this->side;
    this->side = side;
}   

// Получить направление движения персонажа
int Entity::getSide()
{
    return side;
}

// Получить предыдущее направление движения персонажа
int Entity::getPrevSide()
{
    return prev_side;
}

// Получить скорость персонажа
float Entity::getSpeed()
{
    return speed;
}

// Определить предыдущее направление движения персонажа
void Entity::setPrevSide(int prev_side)
{
    this->prev_side = prev_side;
}

// Получить глобальные координаты персонажа
sf::FloatRect Entity::get_global_bounds()
{
    return sprite.getGlobalBounds();
}
