#pragma once
#include <vector>
#include "block.h"
#include "color_block.h"
using namespace std;
// �ѿ�ѿ� �������� ����, ���� ����
#define W 5
#define H 12

// �ѿ�ѿ� ������ ��ü���� ������ �����ϴ� Ŭ����
class array_2d
{
private:
	// �ѿ�ѿ� ������ ���� ����
	int score;
	// �ѿ�ѿ� ������ ��(����)
	static block* block_array[W][H];
	// �ѿ�ѿ� ���ӿ��� ���� ��ü ���� ����
	set<color_block*> explosion_s;
	// �ѿ�ѿ� ���ӿ��� �� ��� ���� ���� �ľ� �Լ�
	bool can_make(int type);
	// �ѿ�ѿ� ���ӿ��� ����� �̵� ���� �ľ� �Լ�
	bool can_move(int x, int y);
	// �ѿ�ѿ� �۹̿��� ����� ���� ���� �ľ� �Լ�
	bool can_explosion();
public:
	// �ѿ�ѿ� ������
	array_2d();
	// ��� ���� ���� �Լ���
	void explosion();
	void insert_explosion(color_block* group);
	void remove_explosion(color_block* group);
	// �ѿ�ѿ� ���� ������ ��� �Լ���
	void print();
	int get_score();
	// ���� �Լ���
	// �ѿ�ѿ� ���� ��� �߰�, ���� �Լ���
	static void insert(vector<block*> v);
	static void insert(int x, int y, block* b);
	static void delete_block(int x, int y);
	// Ư�� ��ġ�� ����� �������� �Լ�
	static block* get_block(int x, int y);
};