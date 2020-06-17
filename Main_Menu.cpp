#include "Main_Menu.h"


int Main_Menu::menuLoop()
{
	Cursor cursor = FIRST;
	while (window.isOpen())
	{
		while (window.pollEvent(menu))
		{
			if (menu.type == Event::Closed)
				window.close();

			if (menu.type == Event::KeyPressed)
			{
				int c = static_cast<int>(cursor);
				switch (menu.key.code)
				{
				case Keyboard::Up:
					c--;
					if (c < 0)
						c = 0;
					break;
				case Keyboard::Down:
					c++;
					if (c >= 3)
						c = 3 - 1;
					break;
				case Keyboard::Enter:
					menu_sel = c + 1;
					window.close();
					break;
				default:
					break;
				}
				cursor = static_cast<Cursor>(c);
			}
		}

		window.clear(Color::White);

		window.draw(S1);

		for (int i = 0; i < 3; i++)
		{
			option[i].setFillColor(Color::Green);
			if (cursor == static_cast<Cursor>(i))
			{
				option[i].setFillColor(Color::Red);
			}
			window.draw(option[i]);
		}

		window.draw(singlePlayer);
		window.draw(multiPlayer);
		window.draw(exit);

		window.display();
	}
	return menu_sel;
}