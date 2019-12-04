#pragma once
#include <set>
#include <vector>
using namespace std;
// �ѿ�ѿ� �������� ����, ���� ����
#define W 7
#define H 14
#define SAFE_DELETE(p) { if(p) delete(p); p = NULL; }

// �ѿ�ѿ� ������ ��ü���� ������ �����ϴ� Ŭ����
class array_2d
{
private:
	int color[5] = { 15, 1, 2, 4, 8 };
	int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	// ���ĵ� ����� set ���׾�ʿ��� ������ �Լ�
	void remove_explosion();
	// �ѿ�ѿ� ������ ���� ����
	static int explo_cnt;
	static int score;
	// �ѿ�ѿ� ������ ��(����)
	static class block *block_array[H][W];
	// �ѿ�ѿ� ���ӿ��� ���� ��ü ���� ����
	static set<class color_block*> explosion_s;
public:
	// �ѿ�ѿ� ������
	array_2d();
	
	// �ѿ�ѿ� ���ӿ��� �� ��� ���� ���� �ľ� �Լ�
	bool can_make(int types);
	
	// �ѿ�ѿ� ���� ������ ��� �Լ���
	void print();
	void set_color(int back);
	int get_score();

	// ������ ��� ���� �Լ�
	int explosion(int& cnt);
	// ��� ����� ������ �Լ�
	void down_all();
	// ���� �Լ���
	// �ѿ�ѿ� ���� ��� �߰�, ���� �Լ���
	static void insert(vector<class block*> v);
	static void insert(int x, int y, class block* b);
	// ����� �߰��ϴ� �Լ�
	static void insert_explosion(class color_block* group);
	// Ư�� ��ġ�� ����� �������� �Լ�
	static block *get_block(int x, int y);
	static void delete_block(int x, int y);
};