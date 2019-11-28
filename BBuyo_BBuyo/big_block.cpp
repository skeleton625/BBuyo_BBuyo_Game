#include "block.h"
#include "array_2d.h"
#include "big_block.h"

// ū ����� ������, �Ҹ���
big_block::big_block(int _type)
{
	this->block_type = _type;
	mid_x = 1, mid_y = 2;
}

big_block::~big_block()
{
	while(!v.empty())
		v.pop_back();
}

// ū ����� �̵� ���� ���� Ȯ�� �Լ���
bool big_block::can_left()
{
	for (block* b : v)
	{
		if (!b->can_left())
			return false;
	}
	return true;
}

bool big_block::can_right()
{
	for (block* b : v)
	{
		if (!b->can_right())
			return false;
	}

	return true;
}

bool big_block::can_down()
{
	int x, y;
	block* tmp;
	for (block* b : v)
	{
		x = b->get_x() - 1;
		y = b->get_y();
		tmp = array_2d::get_block(x, y);
		if (tmp != NULL && tmp->get_fixed())
			return false;
	}
	return true;
}

bool big_block::can_rotate()
{
	int x, y;
	for (block* b : v)
	{
		x = b->get_x();
		y = b->get_y();
		rotate_vertex(x, y);
		if (array_2d::get_block(x, y)->get_fixed())
			return false;
	}
	return true;
}

void big_block::rotate_vertex(int& x, int& y)
{
	int nx = (y - mid_y) * -1;
	int ny = (x - mid_x);
	x = nx + mid_y;
	y = ny + mid_x;
}

// ū ����� �̵�, ȸ�� �Լ�
bool big_block::move(int input)
{
	switch (input)
	{
		case 0:
			if (can_left())
			{
				left();
				return true;
			}
			break;
		case 1:
			if (can_right())
			{
				right();
				return true;
			}
			break;
		case 2:
			if (can_down())
			{
				down();
				return true;
			}
			break;
		default:
			return false;
	}
	return false;
}

void big_block::rotate()
{
	if (!can_rotate())
		return;

	int x, y;
	for (block* b : v)
	{
		x = b->get_x();
		y = b->get_y();
		rotate_vertex(x, y);
		b->set_location(x, y);
	}
}
// ū ����� ��� ����� �̵���Ű�� �Լ�
void big_block::left()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->left();
	--mid_y;
}

void big_block::right()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->right();
	++mid_y;
}

void big_block::down()
{
	for (block* b : v)
		array_2d::delete_block(b->get_x(), b->get_y());
	for (block* b : v)
		b->down();
	--mid_x;
}

void big_block::down_all()
{
	for (block* b : v)
		b->down_all();
	mid_x = v[2]->get_x();
}

void big_block::fix_blocks()
{
	for (block* b : v)
	{
		b->set_fixed(true);
		b->can_merge();
	}
}