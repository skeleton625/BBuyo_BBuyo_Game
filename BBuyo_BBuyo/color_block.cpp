#include "block.h"
#include "color_block.h"

// 같은 색 모임 객체 생성자
color_block::color_block(block* b)
{
	s = set<block*>();
	s.insert(b);
}

// 해당 객체의 같은 색 모임에 매개변수 같은 색 모임을 합하는 함수
void color_block::insert(set<block*> s)
{
	for (block* b : s)
		s.insert(b);
}

// 해당 객체의 같은 색 모임 반환 함수
set<block*> color_block::get_set() { return s; }

// 해당 객체의 같은 색 모임 숫자 반환 함수
int color_block::get_set_size() { return s.size(); }

// 해당 객체의 같은 색 모임에 있는 모든 블록을 삭제하는 함수
void color_block::explosion()
{
	for (block* b : s)
		b->set_color(0);
}