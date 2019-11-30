#pragma once
#include <set>
#include <vector>
using namespace std;
// 뿌요뿌요 보드판의 가로, 세로 길이
#define W 7
#define H 14
#define SAFE_DELETE(p) { if(p) delete(p); p = NULL; }

// 뿌요뿌요 게임의 전체적인 관리를 진행하는 클래스
class array_2d
{
private:
	int color[5] = { 15, 1, 2, 4, 8 };
	// 폭파된 블록을 set 컨테어너에서 제거한 함수
	void remove_explosion();
	// 뿌요뿌요 게임의 현재 점수
	static int explo_cnt;
	static int score;
	// 뿌요뿌요 게임의 맵(보드)
	static class block *block_array[H][W];
	// 뿌요뿌요 게임에서 터질 객체 저장 변수
	static set<class color_block*> explosion_s;
public:
	// 뿌요뿌요 생성자
	array_2d();
	
	// 뿌요뿌요 게임에서 새 블록 생성 여부 파악 함수
	bool can_make(int types);
	
	// 뿌요뿌요 게임 데이터 출력 함수들
	void print();
	void set_color(int back);
	int get_score();

	// 합쳐진 블록 폭파 함수
	bool explosion();
	// 모든 블록을 내리는 함수
	void down_all();
	// 정적 함수들
	// 뿌요뿌요 게임 블록 추가, 삭제 함수들
	static void insert(vector<class block*> v);
	static void insert(int x, int y, class block* b);
	// 블록을 추가하는 함수
	static void insert_explosion(class color_block* group);
	// 특정 위치의 블록을 가져오는 함수
	static block *get_block(int x, int y);
	static void delete_block(int x, int y);
};