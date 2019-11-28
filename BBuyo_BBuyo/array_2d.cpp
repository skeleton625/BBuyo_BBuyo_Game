#include <iostream>
#include "block.h"
#include "array_2d.h"
#include "big_block.h"
#include "color_block.h"

block* array_2d::block_array[H][W];
set<color_block*> array_2d::explosion_s;

// �ѿ�ѿ� ������
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

// �ѿ�ѿ� ���ӿ��� �� ��� ���� ���� �ľ� �Լ�
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

// ��� ���� ���� �Լ���
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

// �ѿ�ѿ� ���� ������ ��� �Լ���
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

// �ѿ�ѿ� ���� ��� �߰�, ���� �Լ���
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

// Ư�� ��ġ�� ����� �������� �Լ�
block* array_2d::get_block(int x, int y)
{
	if (x < 0 || y < 0 || x >= H || y >= W)
		return NULL;
	else
		return block_array[x][y];;
}