#pragma once

#include "Entity.h"

class PacMan : public Entity
{
	int eated_dots; // ���-�� ��������� �������
	bool frame_is_null; // ������� �� ����
public:
	PacMan();
	void eatDot(); // ������ �����
	int getDots(); // �������� ���-�� �������� �����
	void restart(bool contin); // ��� �������� ����
};

