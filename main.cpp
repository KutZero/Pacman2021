#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	Engine REngine; // �������� ������� ������ Engine
	while (REngine.isRunning()) // ���� ������ ��������
	{
		REngine.time_count(); // ������� �������
		REngine.handleEvents(); // ������������� �������
		REngine.render(); // ������ ����� �����������
	}
	system("pause");
	return 0;
}