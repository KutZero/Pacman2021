#pragma once

#include "Entity.h"
#include <cstdlib> // ��� ������� rand() � srand()


class Ghost : public Entity
{
	float help_rand; // ������� ��� ����� ������� �������� ��� � ���������� �������
	float time_of_fear; // ����� ������
	bool isfear; // ������� �� ��
	bool death_of_fear; // ������ �� �� � ��������� ������
public:
	Ghost();
	void init(int y); // �������������
	void compute_side(float timex); // ������ � ����� ������� ���� ��������
	void ghostAnimation(float time, int state, int anim); // ��� �������� ���������
	bool getFearState(); // ������� �� �������
	void setFearState(bool fear); // ��������� ��������� ������
	void restart(int y); // ��� ����������� ����
};

