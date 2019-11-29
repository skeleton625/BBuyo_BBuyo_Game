#include <cmath>
#include <iostream>
#include <windows.h> 
#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

int array_2d::explo_cnt = 0;
int array_2d::score = 0;
block *array_2d::block_array[H][W];
set<color_block*> array_2d::explosion_s;

// 뿌요뿌요 생성자
array_2d::array_2d()
{
	for (int i = 1; i < H - 1; i++)
	{
		for (int j = 1; j < W - 1; j++)
			block_array[i][j] = NULL;
	}
	
	explo_cnt = 0;
	score = 0;
	explosion_s = set<color_block*>();

	for (int i = 0; i < H; i++)
	{
		block_array[i][0] = new block(0);
		block_array[i][0]->set_fixed(true);
		block_array[i][0]->set_location(i, 0);
		block_array[i][W - 1] = new block(0);
		block_array[i][W - 1]->set_fixed(true);
		block_array[i][W - 1]->set_location(i, W - 1);
	}

	for (int i = 0; i < W; i++)
	{
		block_array[0][i] = new block(0);
		block_array[0][i]->set_fixed(true);
		block_array[0][i]->set_location(0, i);
		block_array[H - 1][i] = new block(0);
		block_array[H - 1][i]->set_fixed(true);
		block_array[H - 1][i]->set_location(H - 1, i);
	}
}

// 뿌요뿌요 게임에서 새 블록 생성 여부 파악 함수
bool array_2d::can_make(int types)
{
	switch (types)
	{
	case 0:
		if (block_array[1][3] != NULL ||
			block_array[2][3] != NULL ||
			block_array[2][2] != NULL)
			return false;
	case 1:
		if (block_array[1][3] != NULL ||
			block_array[2][3] != NULL ||
			block_array[3][3] != NULL)
			return false;
	case 2:
		if (block_array[1][3] != NULL ||
			block_array[2][2] != NULL ||
			block_array[2][3] != NULL ||
			block_array[2][4] != NULL ||
			block_array[3][3] != NULL)
			return false;
	}
	return true;
}

// 블록 폭파 관련 함수들
bool array_2d::explosion()
{
	bool flag = false;
	for (color_block* blocks : explosion_s)
	{
		for (block* b : blocks->get_set())
		{
			block_array[b->get_x()][b->get_y()] = NULL;
			delete(b);
		}
		flag = true;
		explo_cnt++;
	}
	if (flag)
	{
		remove_explosion();
		return true;
	}
		
	else
		return false;
}
void array_2d::insert_explosion(color_block* group)
{
	auto it = explosion_s.find(group);

	if(it == explosion_s.end())
		explosion_s.insert(group);
}

void array_2d::remove_explosion()
{
	for (color_block* group : explosion_s)
		delete(group);

	explosion_s = set<color_block*>();
}

// 뿌요뿌요 게임 데이터 출력 함수들
void array_2d::print()
{
	system("cls");
	cout << "Score : " << score << '\n';
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (block_array[i][j] == NULL)
				cout << "  ";
			else
			{
				int col = block_array[i][j]->get_color();
				set_color(color[col]);
				if (col == 0)
					cout << "■";
				else 
					cout << "●";
			}
				
		}
		cout << '\n';
	}
}

void array_2d::set_color(int fore)
{
	SetConsoleTextAttribute
			(GetStdHandle(STD_OUTPUT_HANDLE), fore);
}

int array_2d::get_score() { return score; }

// 뿌요뿌요 게임 블록 추가, 삭제 함수들
void array_2d::insert(vector<block*> v)
{
	int nx, ny;
	for (block* b : v)
	{
		nx = b->get_x();
		ny = b->get_y();
		block_array[nx][ny] = b;
	}

	if (explo_cnt > 0)
	{
		score += explo_cnt;
		explo_cnt = 0;
	}
}

void array_2d::insert(int x, int y, block* b)
{
	block_array[x][y] = b;
}

void array_2d::delete_block(int x, int y)
{
	block_array[x][y] = NULL;
}

// 특정 위치의 블록을 가져오는 함수
block* array_2d::get_block(int x, int y)
{
	if (x < 0 || y < 0 || x >= H || y >= W)
		return NULL;
	else
		return block_array[x][y];;
}

// 모든 블록을 내리는 함수
void array_2d::down_all()
{
	int flag;
	for (int i = H - 2; i > 0; i--)
	{
		flag = 0;
		for (int j = 1; j < W - 1; j++)
		{
			if (block_array[i][j] == NULL)
			{
				++flag;
				continue;
			}

			int nx = i;
			while (block_array[nx][j]->can_down())
			{
				block_array[nx][j]->down();
				block_array[nx][j]->set_group
									(new color_block(block_array[nx][j]));
				block_array[nx][j] = NULL;
				++nx;
			}
			block_array[nx][j]->can_merge();
		}
	}

	

	for (int i = H - 2; i > 0; i--)
	{
		flag = 0;
		for (int j = 1; j < W - 1; j++)
		{
			if (block_array[i][j] == NULL)
			{
				++flag;
				continue;
			}

			if (block_array[i][j]->can_explosion())
				insert_explosion(block_array[i][j]->get_group());
		}
		if (flag == W - 2)
			break;
	}
}