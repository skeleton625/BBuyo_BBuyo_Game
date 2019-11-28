#pragma once
#include <set>
#include <vector>
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
	// 폭파된 블록을 set 컨테어너에서 제거한 함수
	void remove_explosion(class color_block* group);
	// 뿌요뿌요 게임의 맵(보드)
	static class block* block_array[H][W];
	// 뿌요뿌요 게임에서 터질 객체 저장 변수
	static set<class color_block*> explosion_s;
public:
	// 뿌요뿌요 생성자
	array_2d();
	
	// 뿌요뿌요 게임에서 새 블록 생성 여부 파악 함수
	bool can_make(int types);
	
	// 뿌요뿌요 게임 데이터 출력 함수들
	void print();
	int get_score();

	// 합쳐진 블록 폭파 함수
	void explosion();
	// 정적 함수들
	// 뿌요뿌요 게임 블록 추가, 삭제 함수들
	static void insert(vector<class block*> v);
	static void insert(int x, int y, class block* b);
	// 블록을 추가하는 함수
	static void insert_explosion(class color_block* group);
	// 특정 위치의 블록을 가져오는 함수
	static block* get_block(int x, int y);
	static void delete_block(int x, int y);
};