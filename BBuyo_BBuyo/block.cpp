#include "block.h"

// ��� ��ü ������
block::block(int color)
{
	this->color = color;
	x = 0, y = 0;
}
// ��� ��ü �Ҹ���
block::~block()
{
	if(group != NULL)
		delete(group);
}

// ��� �� ĭ �̵�
void block::right()
{
	if (can_right())
		++y;
}
// �·� �� ĭ �̵�
void block::left()
{
	if (can_left())
		--y;
}
// �Ʒ��� �� ĭ �̵�
void block::down()
{
	if (can_down())
		++x;
}
// �� ������ ������ �̵�
void block::down_all()
{
	while (can_down())
		++x;
}
// �Ű����� ��ϰ� ���� ����� �׷��� ��ħ
void block::merge(block* b)
{
	b->get_group()->insert(group->get_set());
	group->insert(b->get_group()->get_set());
}


// �̵� ���� ���� �ľ� �Լ���
bool block::can_down() {}
bool block::can_left() {}
bool block::can_right() {}
bool block::can_merge(block* b) {}
bool block::can_explosion(block* b) {}
// ??
bool find_merge();

// ����, ��ȯ �Լ���
int block::get_color() { return color; }
int block::get_x() { return x; }
int block::get_y() { return y; }
color_block* block::get_group() { return group; }
void block::set_group(color_block* group) { this->group = group; }
void block::set_location(int x, int y)
{
	this->x = x;
	this->y = y;
}
