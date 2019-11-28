#include <iostream>
#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

block* array_2d::block_array[H][W];
set<color_block*> array_2d::explosion_s;

// 뿌요뿌요 생성자
array_2d::array_2d()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			block_array[i][j] = NULL;
	}
	score = 0;
	explosion_s = set<color_block*>();
}

// 뿌요뿌요 게임에서 새 블록 생성 여부 파악 함수
bool array_2d::can_make(int types)
{
	switch (types)
	{
	case 0:
		if (block_array[0][3] != NULL ||
			block_array[1][3] != NULL ||
			block_array[1][2] != NULL)
			return false;
	case 1:
		if (block_array[0][3] != NULL ||
			block_array[1][3] != NULL ||
			block_array[2][3] != NULL)
			return false;
	case 2:
		if (block_array[0][3] != NULL ||
			block_array[1][2] != NULL ||
			block_array[1][3] != NULL ||
			block_array[1][4] != NULL ||
			block_array[2][3] != NULL)
			return false;
	}
	return true;
}

// 블록 폭파 관련 함수들
void array_2d::explosion()
{
	for (color_block* blocks : explosion_s)
	{
		blocks->explosion();
		for (block* b : blocks->get_set())
			delete(b);
		remove_explosion(blocks);
	}
}
void array_2d::insert_explosion(color_block* group)
{
	explosion_s.insert(group);
}

void array_2d::remove_explosion(color_block* group)
{
	explosion_s.erase(group);
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
				cout << "0\t";
			else
				cout << block_array[i][j]->get_color() << '\t';
		}
		cout << '\n';
	}
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
}

void array_2d::insert(int x, int y, block* b)
{
	int nx, ny;
	nx = b->get_x();
	ny = b->get_y();
	block_array[nx][ny] = b;
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