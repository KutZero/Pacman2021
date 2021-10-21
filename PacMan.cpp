#include "PacMan.h"

// �����������
PacMan::PacMan()
{
    screenPosX = 50; 
    screenPosY = 64;
    num_of_frames = 3;
    currentframe = 0;
	speed = 0.2;
    side = 4; // ����� �� �����
    eated_dots = 0;
    frame_is_null = false;

    // �������� ��������
    if (!texture.loadFromFile("things.png"))
        std::cout << "Error loading mobs texture\n";

    // ��������� �������
	sprite.setTexture(texture);
	sprite.setPosition(screenPosX, screenPosY);
	sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
    sprite.setScale(1.2,1.2);
}

// ������ �������
void PacMan::eatDot()
{
    eated_dots++;
}

// �������� ���-�� ��������� �������
int PacMan::getDots()
{
    return eated_dots;
}

// �������������������� �������
void PacMan::restart(bool contin) // ������������ ������� � ���������� (�� ������� ��������� ����� � ���)
{
    screenPosX = 50;
    screenPosY = 64;
    currentframe = 0;
    speed = 0.2;
    side = 4; // ����� �� �����
    if (contin == false) // ���� ���� �� ����� ������������ - �������� �������
    {
        eated_dots = 0;
    }
    frame_is_null = false;

    sprite.setPosition(screenPosX, screenPosY);
    sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
}
