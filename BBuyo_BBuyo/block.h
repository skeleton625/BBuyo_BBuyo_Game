#pragma once
#include "color_block.h"

class block
{
private:
	// 현재 블록 정보 변수들
	int color;
	int x, y;
	color_block* group;
	// 현재 블록의 기능 가능 여부 확인 함수들
	bool can_left();
	bool can_right();
	bool can_down();
	bool can_merge(block* b);
	bool can_explosion(block* b);
public:
	// 블록 객체의 생성자, 소멸자
	block(int color);
	~block();
	// 블록의 정보 반환 함수들
	int get_x();
	int get_y();
	int get_color();
	color_block* get_group();
	// 블록의 정보 설정 함수들
	void set_group(color_block* group);
	void set_location(int x, int y);

	// 블록의 이동 함수들
	void right();
	void left();
	void down();
	void down_all();

	// 블록의 합병 함수들
	void merge(block* b);
	void find_merge();
};
