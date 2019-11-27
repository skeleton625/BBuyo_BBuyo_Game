#include "block.h"

// 블록 객체 생성자
block::block(int color)
{
	this->color = color;
	x = 0, y = 0;
}
// 블록 객체 소멸자
block::~block()
{
	if(group != NULL)
		delete(group);
}

// 우로 한 칸 이동
void block::right()
{
	if (can_right())
		++y;
}
// 좌로 한 칸 이동
void block::left()
{
	if (can_left())
		--y;
}
// 아래로 한 칸 이동
void block::down()
{
	if (can_down())
		++x;
}
// 못 내려갈 때까지 이동
void block::down_all()
{
	while (can_down())
		++x;
}
// 매개변수 블록과 현재 블록의 그룹을 합침
void block::merge(block* b)
{
	b->get_group()->insert(group->get_set());
	group->insert(b->get_group()->get_set());
}


// 이도 가능 여부 파악 함수들
bool block::can_down() {}
bool block::can_left() {}
bool block::can_right() {}
bool block::can_merge(block* b) {}
bool block::can_explosion(block* b) {}
// ??
bool find_merge();

// 정의, 반환 함수들
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
