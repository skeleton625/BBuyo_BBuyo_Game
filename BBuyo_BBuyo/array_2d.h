#pragma once
#include <vector>
#include "block.h"
#include "color_block.h"
using namespace std;
// 뿌요뿌요 보드판의 가로, 세로 길이
#define W 5
#define H 12

// 뿌요뿌요 게임의 전체적인 관리를 진행하는 클래스
class array_2d
{
private:
	// 뿌요뿌요 게임의 현재 점수
	int score;
	// 뿌요뿌요 게임의 맵(보드)
	static block* block_array[W][H];
	// 뿌요뿌요 게임에서 터질 객체 저장 변수
	set<color_block*> explosion_s;
	// 뿌요뿌요 게임에서 새 블록 생성 여부 파악 함수
	bool can_make(int type);
	// 뿌요뿌요 게임에서 블록의 이동 여부 파악 함수
	bool can_move(int x, int y);
	// 뿌요뿌요 겡미에서 블록의 폭파 여부 파악 함수
	bool can_explosion();
public:
	// 뿌요뿌요 생성자
	array_2d();
	// 블록 폭파 관련 함수들
	void explosion();
	void insert_explosion(color_block* group);
	void remove_explosion(color_block* group);
	// 뿌요뿌요 게임 데이터 출력 함수들
	void print();
	int get_score();
	// 정적 함수들
	// 뿌요뿌요 게임 블록 추가, 삭제 함수들
	static void insert(vector<block*> v);
	static void insert(int x, int y, block* b);
	static void delete_block(int x, int y);
	// 특정 위치의 블록을 가져오는 함수
	static block* get_block(int x, int y);
};