#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	Engine REngine; // Создание объекта класса Engine
	while (REngine.isRunning()) // Если движок работает
	{
		REngine.time_count(); // Подсчет времени
		REngine.handleEvents(); // Распределение ивентов
		REngine.render(); // Рендер всего содержимого
	}
	system("pause");
	return 0;
}