#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <array>

int w = 200;
int gridView[3][3];
std::array<int, 9> board;
bool zvet;
bool hod;
int l;
int ll;
bool player = 0;
bool comp = 0;
bool di = 1;
float rot = 0.f;
float move = 1000;
float mov = 0;

using namespace sf;

void cDi()
	{
		di = 0;
		if (gridView[0][0] == gridView[0][1])
		{
			if (gridView[0][1] == gridView[0][2])
				if (gridView[0][0] != 2)
				{
					rot = 90.f;
					move = 100;//
					mov = 25;
				}
		}

		if (gridView[1][0] == gridView[1][1])
		{
			if (gridView[1][1] == gridView[1][2])
				if (gridView[1][0] != 2)
				{
					rot = 90.f;
					move = 300;//
					mov = 25;
				}
		}

		if (gridView[2][0] == gridView[2][1])
		{
			if (gridView[2][1] == gridView[2][2])
				if (gridView[2][0] != 2)
				{
					rot = 90.f;
					move = 500;//
					mov = 25;
				}
		}

		if (gridView[0][0] == gridView[1][0])
		{
			if (gridView[1][0] == gridView[2][0])
				if (gridView[0][0] != 2)
				{
					rot = 0.f;
					move = 25;//
					mov = 100;
				}
		}


		if (gridView[0][1] == gridView[1][1])
		{
			if (gridView[1][1] == gridView[2][1])
				if (gridView[0][1] != 2)
				{
					rot = 0.f;
					move = 25;//
					mov = 300;
				}
		}

		if (gridView[0][2] == gridView[1][2])
		{
			if (gridView[1][2] == gridView[2][2])
				if (gridView[0][2] != 2)
				{
					rot = 0.f;
					move = 25;//
					mov = 500;
				}
		}

		if (gridView[0][0] == gridView[1][1])
		{
			if (gridView[1][1] == gridView[2][2])
				if (gridView[0][0] != 2)
				{
					rot = 45.f;
					move = 100;//
					mov = 100;
				}
		}

		if (gridView[0][2] == gridView[1][1])
		{
			if (gridView[1][1] == gridView[2][0])
				if (gridView[0][2] != 2)
				{
					rot = -45.f;
					move = 100;//
					mov = 500;
				}
		}
	}

void give()
{
	board[0] = gridView[0][0];
	board[1] = gridView[0][1];
	board[2] = gridView[0][2];
	board[3] = gridView[1][0];
	board[4] = gridView[1][1];
	board[5] = gridView[1][2];
	board[6] = gridView[2][0];
	board[7] = gridView[2][1];
	board[8] = gridView[2][2];
}

void cWin()
{

	if (gridView[0][0] == gridView[0][1] && gridView[0][1] == gridView[0][2])
		if (gridView[0][0] != 2)
		{
			cDi();
			return;
		}
						

	if (gridView[1][0] == gridView[1][1] && gridView[1][1] == gridView[1][2])
			if (gridView[1][0] != 2)
			{
				cDi();
				return;
			}

	if (gridView[2][0] == gridView[2][1] && gridView[2][1] == gridView[2][2])
			if (gridView[2][0] != 2)
			{
				cDi();
				return;
			}

	if (gridView[0][0] == gridView[1][0] && gridView[1][0] == gridView[2][0])
			if (gridView[0][0] != 2)
			{
				cDi();
				return;
			}

	if (gridView[0][1] == gridView[1][1] && gridView[1][1] == gridView[2][1])
			if (gridView[0][1] != 2)
			{
				cDi();
				return;
			}

	if (gridView[0][2] == gridView[1][2] && gridView[1][2] == gridView[2][2])
			if (gridView[0][2] != 2)
			{
				cDi();
				return;
			}

	if (gridView[0][0] == gridView[1][1] && gridView[1][1] == gridView[2][2])
			if (gridView[0][0] != 2)
			{
				cDi();
				return;
			}

	if (gridView[0][2] == gridView[1][1] && gridView[1][1] == gridView[2][0])
			if (gridView[0][2] != 2)
			{
				cDi();
				return;
			}
}

int get()
{

	if (board[0] == board[1] && board[0] == ll)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[1] == board[2] && board[1] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[3] == board[4] && board[3] == ll)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[4] == board[5] && board[4] == ll)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[6] == board[7] && board[6] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[7] == board[8] && board[7] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[4] && board[0] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[2] == board[4] && board[2] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[3] && board[0] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[3] == board[6] && board[3] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[1] == board[4] && board[1] == ll)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[4] == board[7] && board[4] == ll)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[2] == board[5] && board[2] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[5] == board[8] && board[5] == ll)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[4] == board[8] && board[4] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[0] == board[2] && board[0] == ll)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[3] == board[5] && board[3] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[6] == board[8] && board[6] == ll)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[0] == board[6] && board[0] == ll)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[1] == board[7] && board[1] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[8] && board[2] == ll)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[0] == board[8] && board[0] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[6] && board[2] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[0] == board[1] && board[0] == ll)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[1] == board[2] && board[1] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[3] == board[4] && board[3] == ll)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[4] == board[5] && board[4] == ll)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[6] == board[7] && board[6] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[7] == board[8] && board[7] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[4] && board[0] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[2] == board[4] && board[2] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[3] && board[0] == ll)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[3] == board[6] && board[3] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[1] == board[4] && board[1] == ll)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[4] == board[7] && board[4] == ll)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[2] == board[5] && board[2] == ll)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[5] == board[8] && board[5] == ll)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[4] == board[8] && board[4] == ll)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[0] == board[2] && board[0] == ll)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[3] == board[5] && board[3] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[6] == board[8] && board[6] == ll)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[0] == board[6] && board[0] == ll)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[1] == board[7] && board[1] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[8] && board[2] == ll)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[0] == board[8] && board[0] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[6] && board[2] == ll)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}

	if (board[0] == board[1] && board[0] == l)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[1] == board[2] && board[1] == l)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[3] == board[4] && board[3] == l)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[4] == board[5] && board[4] == l)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[6] == board[7] && board[6] == l)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[7] == board[8] && board[7] == l)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[4] && board[0] == l)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[2] == board[4] && board[2] == l)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[0] == board[3] && board[0] == l)
	{
		if (board[6] != l && board[6] != ll)
			return 6;
	}
	if (board[3] == board[6] && board[3] == l)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[1] == board[4] && board[1] == l)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[4] == board[7] && board[4] == l)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[2] == board[5] && board[2] == l)
	{
		if (board[8] != l && board[8] != ll)
			return 8;
	}
	if (board[5] == board[8] && board[5] == l)
	{
		if (board[2] != l && board[2] != ll)
			return 2;
	}
	if (board[4] == board[8] && board[4] == l)
	{
		if (board[0] != l && board[0] != ll)
			return 0;
	}
	if (board[0] == board[2] && board[0] == l)
	{
		if (board[1] != l && board[1] != ll)
			return 1;
	}
	if (board[3] == board[5] && board[3] == l)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[6] == board[8] && board[6] == l)
	{
		if (board[7] != l && board[7] != ll)
			return 7;
	}
	if (board[0] == board[6] && board[0] == l)
	{
		if (board[3] != l && board[3] != ll)
			return 3;
	}
	if (board[1] == board[7] && board[1] == l)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[8] && board[2] == l)
	{
		if (board[5] != l && board[5] != ll)
			return 5;
	}
	if (board[0] == board[8] && board[0] == l)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}
	if (board[2] == board[6] && board[2] == l)
	{
		if (board[4] != l && board[4] != ll)
			return 4;
	}

	int nomber = -1;
	if (board[0] == board[8] && board[0] == l && board[4] == ll)
	{
		int i = 1;
		while (i < 8)
		{
			if (board[i] != l && board[i] != ll)
				return i;

			i = i + 2;
		}
	}
	if (board[2] == board[6] && board[2] == l && board[4] == ll)
	{
		int i = 1;
		while (i < 8)
		{
			if (board[i] != l && board[i] != ll)
				return i;

			i = i + 2;
		}
	}

	int index = 0;
	int count = -1;
	int desck[9] = { 2, 1, 2, 1, 3, 1, 2, 1, 2 };

	while (index <= 8)
	{
		if (board[index] == ll)
			goto q;
		if (board[index] == l)
			goto q;

		if (desck[index] > count)
		{
			count = desck[index];
			nomber = index;
		}
	q:

		++index;
	}
	return nomber;
}

void set()
{
	int r = get();

	if (r == 0)
	{
		gridView[0][0] = ll;
	}
	if (r == 1)
	{
		gridView[0][1] = ll;
	}
	if (r == 2)
	{
		gridView[0][2] = ll;
	}
	if (r == 3)
	{
		gridView[1][0] = ll;
	}
	if (r == 4)
	{
		gridView[1][1] = ll;
	}
	if (r == 5)
	{
		gridView[1][2] = ll;
	}
	if (r == 6)
	{
		gridView[2][0] = ll;
	}
	if (r == 7)
	{
		gridView[2][1] = ll;
	}
	if (r == 8)
	{
		gridView[2][2] = ll;
	}
}

int main()
{

	RenderWindow window(VideoMode(600, 600), "Tic-tac-toe");

	std::cout << "cross(1) or toe(0): ";
	std::cin >> zvet;
	std::cout << "first(1) or second(0): ";
	std::cin >> hod;

	if (zvet == true) { l = 1; ll = 0; }
	else { l = 0; ll = 1; }

	Texture tr;
	tr.loadFromFile("data/image.png");
	Sprite se(tr);

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			gridView[i][j] = 2;
		}

	while (window.isOpen())
	{
                
		RectangleShape line(Vector2f(550.f, 10.f));

		line.setFillColor(Color(254, 0, 0));

		Vector2i pos = Mouse::getPosition(window);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;

		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (hod == 0)
			{
				give();
				set();

				cWin();

				player = 0;
				comp = 1;
				hod = 1;
			}

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
					if (di == 1)
					{
						if (player == 0)
						{
							if (gridView[x][y] == 0 || gridView[x][y] == 1)
								goto yu;

							gridView[x][y] = l;
							 
							cWin();

							comp = 0;
							player = 1;
						}

						if (comp == 0)
						{
							give();
							set();

							cWin();
							
							player = 0;
							comp = 1;
						}
					}

				}
		}
	yu:

		window.clear(Color::White);
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
			{
				se.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
				se.setPosition(static_cast<float>(i * w), static_cast<float>(j * w));
				window.draw(se);
			}

		if (di == 0)
		{
			line.rotate(rot);
			line.move(move, mov);
			window.draw(line);
		}

		window.display();
	}

	return 0;
}
