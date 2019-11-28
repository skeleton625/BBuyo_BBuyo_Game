#pragma once
#include <set>
#include <vector>
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
	// ���ĵ� ����� set ���׾�ʿ��� ������ �Լ�
	void remove_explosion(class color_block* group);
	// �ѿ�ѿ� ������ ��(����)
	static class block* block_array[H][W];
	// �ѿ�ѿ� ���ӿ��� ���� ��ü ���� ����
	static set<class color_block*> explosion_s;
public:
	// �ѿ�ѿ� ������
	array_2d();
	
	// �ѿ�ѿ� ���ӿ��� �� ��� ���� ���� �ľ� �Լ�
	bool can_make(int types);
	
	// �ѿ�ѿ� ���� ������ ��� �Լ���
	void print();
	int get_score();

	// ������ ��� ���� �Լ�
	void explosion();
	// ���� �Լ���
	// �ѿ�ѿ� ���� ��� �߰�, ���� �Լ���
	static void insert(vector<class block*> v);
	static void insert(int x, int y, class block* b);
	// ����� �߰��ϴ� �Լ�
	static void insert_explosion(class color_block* group);
	// Ư�� ��ġ�� ����� �������� �Լ�
	static block* get_block(int x, int y);
	static void delete_block(int x, int y);
};