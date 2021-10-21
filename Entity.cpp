#include "Entity.h"

// �������� ������� �� �
float Entity::getScreenPosX()
{
    return screenPosX;
}

// �������� ������� �� �
float Entity::getScreenPosY()
{
    return screenPosY;
}

// �������� ��������
void Entity::animation(int y, float time)
{
    // ������ �������� �����
    currentframe += 0.02 * time;
    if (currentframe > num_of_frames)
    {
    	currentframe -= num_of_frames;
    }

    switch (side) // ����� ��������
    {
    case 0: // �������� �����
        // � ����������� �� ������ ����� � ��������� ������� ���������� ���� ��������
        //� - ������
        //15 - ������ ������ ��������� �������� ��������� �� ����� ��������
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15, y * 15, 15, 15));
        break;
    case 1: // �������� ����
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames,  y * 15, 15, 15));
        break;
    case 2: // �������� ������
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames * 3, y * 15, 15, 15));
        break;
    case 3: // �������� �����
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 15 * num_of_frames * 2, y * 15, 15, 15));
        break;
    }
}

// ��������� �������
void Entity::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

//�������� ���������
//side - �����������
//speed - ��������
void Entity::move(int side, float speed)
{
    switch (side)
    {
    case 0: // �������� �����
        sprite.move(0, -speed);
        screenPosY -= speed;
        break;
    case 1: // �������� ����
        sprite.move(0, speed);
        screenPosY += speed;
        break;
    case 2:  // �������� ������
        sprite.move(speed, 0);
        screenPosX += speed;
        break;
    case 3:  // �������� �����
        sprite.move(-speed, 0);
        screenPosX -= speed;
        break;
    }
}

// ������������ ���������
void Entity::teleport(bool mode)
{
    // ���� �� ����� � ����� �������
    if (screenPosX < 15)
    {
        screenPosX = 420;
        screenPosY = 266.415588;
        sprite.setPosition(screenPosX, screenPosY);
    }
    // ���� �� ����� � ������ �������
    else if (screenPosX > 430)
    {
        screenPosX = 20;
        screenPosY = 266.415588;
        sprite.setPosition(screenPosX, screenPosY);
    }
    // ���� ��� ���������� �������, ������������� � ��������
    else if (mode == true)
    {
        screenPosX = 180;
        screenPosY = 228;
        sprite.setPosition(screenPosX, screenPosY);
    }
}

void Entity::chose_side(int side) // �������� ������ �� ��������� ������� ��������
{
    prev_side = this->side;
    this->side = side;
}   

// �������� ����������� �������� ���������
int Entity::getSide()
{
    return side;
}

// �������� ���������� ����������� �������� ���������
int Entity::getPrevSide()
{
    return prev_side;
}

// �������� �������� ���������
float Entity::getSpeed()
{
    return speed;
}

// ���������� ���������� ����������� �������� ���������
void Entity::setPrevSide(int prev_side)
{
    this->prev_side = prev_side;
}

// �������� ���������� ���������� ���������
sf::FloatRect Entity::get_global_bounds()
{
    return sprite.getGlobalBounds();
}
