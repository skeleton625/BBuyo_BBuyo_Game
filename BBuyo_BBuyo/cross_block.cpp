#pragma once
#include "cross_block.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5) : big_block(CROSS)
{
	block* b1 = new block(c1);
	b1->set_location(0, 3);
	block* b2 = new block(c2);
	b2->set_location(1, 2);
	block* b3 = new block(c3);
	b3->set_location(2, 2);
	block* b4 = new block(c4);
	b4->set_location(3, 2);
	block* b5 = new block(c5);
	b5->set_location(2, 3);

	v.push_back(b1);
	v.push_back(b2);
	v.push_back(b3);
	v.push_back(b4);
	v.push_back(b5);
}