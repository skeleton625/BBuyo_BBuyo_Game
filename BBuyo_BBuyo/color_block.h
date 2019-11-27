#pragma once
#include <set>
#include "block.h"
using namespace std;

class color_block
{
// ���� �� ���� ��ü
private:
	set<block*> s;
public:
	// ���� �� ���� ��ü ������
	color_block(block* b);
	// �ش� ��ü�� ���� �� ���ӿ� �Ű����� ���� �� ������ ���ϴ� �Լ�
	void insert(set<block*> s);
	// �ش� ��ü�� ���� �� ���� ��ȯ �Լ�
	set<block*> get_set();
	// �ش� ��ü�� ���� �� ���� ���� ��ȯ �Լ�
	int get_set_size();
	// �ش� ��ü�� ���� �� ���ӿ� �ִ� ��� ����� �����ϴ� �Լ�
	void explosion();
};