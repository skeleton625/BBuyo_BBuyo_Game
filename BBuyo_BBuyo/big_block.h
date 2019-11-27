#pragma once
#include <vector>
#include "block.h"
using namespace std;

class big_block
{
protected:
	// ū ��Ͽ� ����� ��ϵ� ����
	vector<block*> v;
	// ū ��� ���� enum
	enum _type
	{ FOLD, TREE, CROSS };
private:
	// ū ����� �߰� ��� ��ġ ����
	int mid_x, mid_y;
	// ū ����� Ÿ�� ����
	_type block_type;
	// ū ����� �̵� ���� ���� Ȯ�� �Լ���
	bool can_left();
	bool can_right();
	bool can_down();
public:
	// ū ����� ������, �Ҹ���
	big_block(_type _type);
	~big_block();
	// ū ����� �̵�, ȸ�� �Լ�
	bool move(int input);
	void rotate();
	// ū ����� ��� ����� �̵���Ű�� �Լ�
	void left();
	void right();
	bool down();
	bool down_all();
};