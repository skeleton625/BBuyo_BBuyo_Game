#pragma once
#include <set>
#include "block.h"
using namespace std;

class color_block
{
// 같은 색 모임 객체
private:
	set<block*> s;
public:
	// 같은 색 모임 객체 생성자
	color_block(block* b);
	// 해당 객체의 같은 색 모임에 매개변수 같은 색 모임을 합하는 함수
	void insert(set<block*> s);
	// 해당 객체의 같은 색 모임 반환 함수
	set<block*> get_set();
	// 해당 객체의 같은 색 모임 숫자 반환 함수
	int get_set_size();
	// 해당 객체의 같은 색 모임에 있는 모든 블록을 삭제하는 함수
	void explosion();
};