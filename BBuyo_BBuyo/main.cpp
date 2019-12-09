#include <random>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "sound.h"
#include "array_2d.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
using namespace std;

int inp = 0;
int types = 0;
int colors[5];
bool down_flag = false;
random_device random;
mt19937 engine(random());
uniform_int_distribution<int> BT(0, 2);
uniform_int_distribution<int> BC(1, 4);

big_block generate_next_block()
{
	types = BT(engine);
	int colors[5];
	for (int i = 0; i < 5; i++)
		colors[i] = BC(engine);

	switch (types)
	{
	case 0:
		return fold_block(colors[0], colors[1], colors[2]);
	case 1:
		return tree_block(colors[0], colors[1], colors[2]);
	case 2:
		return cross_block(colors[0], colors[1], colors[2], colors[3], colors[4]);
	}
	return NULL;
}

int main()
{
	cin.tie(false);
	cout.tie(false);
	ios::sync_with_stdio(false);

	// 음성 파일 제목 변수들
	string break_files[5] = 
		{
			"sound\\break_1.wav",
			"sound\\break_2.wav",
			"sound\\break_3.wav",
			"sound\\break_4.wav",
			"sound\\break_5.wav"
		};
	string cast_files[5] =
		{
			"sound\\cast_1.wav",
			"sound\\cast_2.wav",
			"sound\\cast_3.wav",
			"sound\\cast_4.wav",
			"sound\\cast_5.wav"
		};
	string move_file = "sound\\move.wav";

	// 뿌요뿌요 메인 객체
	array_2d* bbuyo_obj = new array_2d();

	vector<thread> workers;
	sound sound_effect(break_files, cast_files, move_file, 5);

	bbuyo_obj->set_next_block(generate_next_block());
	big_block bb = bbuyo_obj->set_next_block();
	bbuyo_obj->print();
	bbuyo_obj->set_next_block(generate_next_block());
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
					workers.push_back(thread(sound_effect.play_move_sound));
					break;
				case 'd': 
					bb.move(1);
					workers.push_back(thread(sound_effect.play_move_sound));
					break;
				case 's':
					bb.move(2);
					workers.push_back(thread(sound_effect.play_move_sound));
					down_flag = true;
					break;
				case 'x':
					bb.down_all();
					workers.push_back(thread(sound_effect.play_move_sound));
					down_flag = true;
					break;
				case 'e':
					bb.rotate();
					workers.push_back(thread(sound_effect.play_move_sound));
					break;
			}

			if (!bb.can_down() && down_flag)
			{
				bbuyo_obj->down_all();
				bbuyo_obj->print();
				Sleep(1200);

				int explo = 0;
				while (bbuyo_obj->explosion(explo))
				{
					// ??
					workers.push_back(thread(sound_effect.play_break_sound, explo-1));
					bbuyo_obj->down_all();
					bbuyo_obj->print();
					Sleep(1200);
				}

				if (!bbuyo_obj->can_make(types))
					break;

				bb = bbuyo_obj->set_next_block();
				bbuyo_obj->set_next_block(generate_next_block());
			}
			down_flag = false;
			bbuyo_obj->print();
		}
	}

	for (int i = 0; i < workers.size(); i++)
		workers[i].join();

	cout << "GAME OVER!!" << '\n';
	cout << "Your Final Score : " << bbuyo_obj->get_score();
	return 0;
}