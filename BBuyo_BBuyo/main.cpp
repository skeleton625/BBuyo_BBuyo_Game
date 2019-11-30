#include <iostream>
#include <Windows.h>
#include <random>
#include <conio.h>
#include "array_2d.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
using namespace std;

big_block generate_block(int types, int* bs)
{
	switch (types)
	{
		case 0:
			return fold_block(bs[0], bs[1], bs[2]);
		case 1:
			return tree_block(bs[0], bs[1], bs[2]);
		case 2:
			return cross_block(bs[0], bs[1], bs[2], bs[3], bs[4]);
	}
	return NULL;
}

int main()
{
	cin.tie(false);
	cout.tie(false);
	ios::sync_with_stdio(false);

	array_2d* bbuyo_obj = new array_2d();

	cout << "BBuyo BBuyo Start!!" << '\n';
	cout << "Waiting . . . ";

	//Sleep(3000);

	random_device random;
	mt19937 engine(random());
	uniform_int_distribution<int> BT(0, 2);
	uniform_int_distribution<int> BC(1, 4);
	
	int inp = 0, types = 0;
	int colors[5];
	bool down_flag = false;

	for (int i = 0; i < 5; i++)
		colors[i] = BC(engine);
	big_block bb = generate_block(BT(engine), colors);
	bbuyo_obj->print();

	while (true)
	{
		if (_kbhit())
		{
			inp = _getch();
			switch (inp)
			{
				case 'a':
					bb.move(0);
					break;
				case 'd': 
					bb.move(1);
					break;
				case 's':
					bb.move(2);
					down_flag = true;
					break;
				case 'x':
					bb.down_all();
					down_flag = true;
					break;
				case 'e':
					bb.rotate();
					break;
			}

			if (!bb.can_down() && down_flag)
			{
				bbuyo_obj->down_all();
				bbuyo_obj->print();
				Sleep(1000);
				while (bbuyo_obj->explosion())
				{
					bbuyo_obj->down_all();
					bbuyo_obj->print();
					Sleep(1000);
				}

				types = BT(engine);
				if(!bbuyo_obj->can_make(types))
					break;

				for (int i = 0; i < 5; i++)
					colors[i] = BC(engine);
				bb = generate_block(BT(engine), colors);
			}
			down_flag = false;
			bbuyo_obj->print();
		}
	}

	cout << "GAME OVER!!" << '\n';
	cout << "Your Final Score : " << bbuyo_obj->get_score();
	return 0;
}