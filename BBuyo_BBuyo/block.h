#pragma once
#include "color_block.h"

class block
{
private:
	// ���� ��� ���� ������
	int color;
	int x, y;
	color_block* group;
	// ���� ����� ��� ���� ���� Ȯ�� �Լ���
	bool can_left();
	bool can_right();
	bool can_down();
	bool can_merge(block* b);
	bool can_explosion(block* b);
public:
	// ��� ��ü�� ������, �Ҹ���
	block(int color);
	~block();
	// ����� ���� ��ȯ �Լ���
	int get_x();
	int get_y();
	int get_color();
	color_block* get_group();
	// ����� ���� ���� �Լ���
	void set_group(color_block* group);
	void set_location(int x, int y);

	// ����� �̵� �Լ���
	void right();
	void left();
	void down();
	void down_all();

	// ����� �պ� �Լ���
	void merge(block* b);
	void find_merge();
};
