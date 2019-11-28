#include "block.h"
#include "color_block.h"

// ���� �� ���� ��ü ������
color_block::color_block(block* b)
{
	s = set<block*>();
	s.insert(b);
}

// �ش� ��ü�� ���� �� ���ӿ� �Ű����� ���� �� ������ ���ϴ� �Լ�
void color_block::insert(set<block*> s)
{
	for (block* b : s)
		s.insert(b);
}

// �ش� ��ü�� ���� �� ���� ��ȯ �Լ�
set<block*> color_block::get_set() { return s; }

// �ش� ��ü�� ���� �� ���� ���� ��ȯ �Լ�
int color_block::get_set_size() { return s.size(); }

// �ش� ��ü�� ���� �� ���ӿ� �ִ� ��� ����� �����ϴ� �Լ�
void color_block::explosion()
{
	for (block* b : s)
		b->set_color(0);
}