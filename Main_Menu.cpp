#include "Main_Menu.h"

int Main_Menu::twoPlayerMenu()
{
	window.create(VideoMode(900, 700), "TETRIS");
	Cursor cursor = FIRST;

	Text local, host, join;

	local.setFont(font);
	host.setFont(font);
	join.setFont(font);

	local.setString("Local Game");
	host.setString("Host Game");
	join.setString("Join Game");

	local.setCharacterSize(25);
	host.setCharacterSize(25);
	join.setCharacterSize(25);

	local.setFillColor(Color::Black);
	host.setFillColor(Color::Black);
	join.setFillColor(Color::Black);

	local.setPosition(Vector2f(385, 440));
	host.setPosition(Vector2f(390, 490));
	join.setPosition(Vector2f(390, 540));


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

		window.draw(local);
		window.draw(host);
		window.draw(join);

		window.display();
	}

	return menu_sel;
}

void Main_Menu::hostMenu()
{
	window.create(VideoMode(900, 700), "TETRIS");
	Cursor cursor = FIRST;

	Text host_address, port_num, enteredH, enteredP;
	string S_host, S_port;


	host_address.setFont(font);
	port_num.setFont(font);
	enteredH.setFont(font);
	enteredP.setFont(font);

	host_address.setString("Enter Host Adress");
	port_num.setString("Enter Port");
	enteredH.setString(" ");
	enteredP.setString(" ");

	host_address.setCharacterSize(25);
	port_num.setCharacterSize(25);
	enteredH.setCharacterSize(25);
	enteredP.setCharacterSize(25);

	host_address.setFillColor(Color::White);
	port_num.setFillColor(Color::White);
	enteredH.setFillColor(Color::Green);
	enteredP.setFillColor(Color::Green);

	host_address.setPosition(Vector2f(300, 460));
	port_num.setPosition(Vector2f(300, 560));
	enteredH.setPosition(Vector2f(305, 500));
	enteredP.setPosition(Vector2f(305, 600));


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
					if (c >= 2)
						c = 2 - 1;
					break;
				case Keyboard::BackSpace:
					if (c == 0)
					{
						S_host.erase(S_host.size() - 1);
						enteredH.setString(S_host);
					}
					else
					{
						S_port.erase(S_port.size() - 1);
						enteredP.setString(S_port);
					}
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
			if (menu.type == Event::TextEntered)
			{
				if (menu.text.unicode < 128 && menu.text.unicode != 8)
				{
					if (cursor == 0)
					{
						S_host += static_cast<char>(menu.text.unicode);
						enteredH.setString(S_host);
					}
					else if (cursor == 1)
					{
						S_port += static_cast<char>(menu.text.unicode);
						enteredP.setString(S_port);
					}
				}
			}
		}

		window.clear(Color::White);

		window.draw(S1);

		for (int i = 0; i < 2; i++)
		{
			option[i].setFillColor(Color(250, 150, 100, 50));
			if (cursor == static_cast<Cursor>(i))
			{
				option[i].setSize(Vector2f(300, 40));
				option[i].setPosition(Vector2f(300, i * 100 + 500));
				option[i].setFillColor(Color(255, 255, 255, 50));
			}
			window.draw(option[i]);
		}

		window.draw(host_address);
		window.draw(port_num);
		window.draw(enteredH);
		window.draw(enteredP);


		window.display();
	}

	host_ad = S_host;
	port = stoi(S_port);
}

void Main_Menu::joinMenu()
{
	window.create(VideoMode(900, 700), "TETRIS");
	Cursor cursor = FIRST;

	Text host_address, port_num, enteredH, enteredP;
	string S_host, S_port;


	host_address.setFont(font);
	port_num.setFont(font);
	enteredH.setFont(font);
	enteredP.setFont(font);

	host_address.setString("Enter Host Address to Join");
	port_num.setString("Enter Port");
	enteredH.setString("");
	enteredP.setString("");

	host_address.setCharacterSize(25);
	port_num.setCharacterSize(25);
	enteredH.setCharacterSize(25);
	enteredP.setCharacterSize(25);

	host_address.setFillColor(Color::White);
	port_num.setFillColor(Color::White);
	enteredH.setFillColor(Color::Green);
	enteredP.setFillColor(Color::Green);

	host_address.setPosition(Vector2f(300, 460));
	port_num.setPosition(Vector2f(300, 560));
	enteredH.setPosition(Vector2f(305, 500));
	enteredP.setPosition(Vector2f(305, 600));


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
					if (c >= 2)
						c = 2 - 1;
					break;
				case Keyboard::BackSpace:
					if (c == 0)
					{
						S_host.erase(S_host.size() - 1);
						enteredH.setString(S_host);
					}
					else
					{
						S_port.erase(S_port.size() - 1);
						enteredP.setString(S_port);
					}
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
			if (menu.type == Event::TextEntered)
			{
				if (menu.text.unicode < 128 && menu.text.unicode != 8)
				{
					if (cursor == 0)
					{
						S_host += static_cast<char>(menu.text.unicode);
						enteredH.setString(S_host);
					}
					else if (cursor == 1)
					{
						S_port += static_cast<char>(menu.text.unicode);
						enteredP.setString(S_port);
					}
				}
			}
		}

		window.clear(Color::White);

		window.draw(S1);

		for (int i = 0; i < 2; i++)
		{
			option[i].setFillColor(Color(250, 150, 100, 50));
			if (cursor == static_cast<Cursor>(i))
			{
				option[i].setSize(Vector2f(300, 40));
				option[i].setPosition(Vector2f(300, i * 100 + 500));
				option[i].setFillColor(Color(255, 255, 255, 50));
			}
			window.draw(option[i]);
		}

		window.draw(host_address);
		window.draw(port_num);
		window.draw(enteredH);
		window.draw(enteredP);


		window.display();
	}

	client_ad = S_host;
	port = stoi(S_port);
}

int Main_Menu::MainMenu()
{
	window.create(VideoMode(900, 700), "TETRIS");
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

int Main_Menu::menuLoop()
{
	int main = MainMenu();
	int sel = 0, two_play;

	switch (main)
	{
	case 1:
		sel = 1;
		break;
	case 2:
		two_play = twoPlayerMenu();
		sel = 2;

		switch (two_play)
		{
		case 1:
			break;
		case 2:
			hostMenu();
			break;
		case 3:
			joinMenu();
			break;
		}

		break;
	}



	return sel;
}