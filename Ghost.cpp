#include "Ghost.h"

// �����������
Ghost::Ghost()
{
    speed = 0.15;
    side = 4; // ����� �� �����
    currentframe = 0;
    num_of_frames = 2;
    time_of_fear = 0;
    isfear = false; // ������� �� ��

    // �������� ��������
    if (!texture.loadFromFile("things.png")) 
        std::cout << "Error loading mobs texture\n";
}

// �������������
void Ghost::init(int y)
{
    screenPosX = 180 + 20 * (y-1);
    screenPosY = 224;
    sprite.setPosition(screenPosX, screenPosY);

    sprite.setTexture(texture);
    // ���������� ������������ ����� ��������
    sprite.setTextureRect(sf::IntRect(0, y * 15, 15, 15));
    sprite.setScale(1.3, 1.3);

    help_rand = 0;
}

// ��������� ��������� ������� ��������
void Ghost::compute_side(float timex)
{
    int x;
    srand(timex); // ����� ��������� ����� ���� ������
    help_rand += (rand() % 3) * timex / 120 + timex/40; // ������ ������� ��� ����� ����������� ��������
    if (help_rand > 15)
    {
        x = rand() % 4; // ����� ���������� �����������
        chose_side(x);
        help_rand -= 15; // ��������� ��������
    }
}

// �������� ���������
void Ghost::ghostAnimation(float time, int state, int anim)
{
    // ���������� ������ �������� �����
    currentframe += 0.02 * time;
    if (currentframe > num_of_frames)
    {
        currentframe -= num_of_frames;
    }

    // ���� �� ���������� � �������� � ��������� ������
    if ((state == 2) && (time_of_fear < 10))
    {
        isfear = true;
        time_of_fear = 0;
    }
    // ����������� �������� ������ �� �������� time_of_fear
    else if ((isfear == true) && (time_of_fear < 10))
    {
        sprite.setTextureRect(sf::IntRect(int(currentframe) * 15 + 120, 15, 15, 15));
        time_of_fear += 0.002 * time;
    }
    // ��������� � �������� ���������
    else
    {
        isfear = false;
        animation(anim, time);
        time_of_fear = 0;
    }
}

// ������ ������� �� �������
bool Ghost::getFearState()
{
    return isfear;
}

// ���������� ������� �� �������
void Ghost::setFearState(bool fear)
{
    isfear = fear;
}

// �������������������� ��������
void Ghost::restart(int y)
{
    side = 4; // ����� �� �����
    currentframe = 0;
    time_of_fear = 0;
    isfear = false;
    sprite.setTextureRect(sf::IntRect(int(currentframe) * 15, y * 15, 15, 15));
    screenPosX = 180 + 20 * (y - 1);
    screenPosY = 224;
    sprite.setPosition(screenPosX, screenPosY);
    
}
