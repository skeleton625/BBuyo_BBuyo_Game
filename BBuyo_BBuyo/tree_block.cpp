#include "tree_block.h"

tree_block::tree_block(int c1, int c2, int c3) : big_block(TREE)
{
	block* b1 = new block(c1);
	b1->set_location(0, 3);
	block* b2 = new block(c2);
	b2->set_location(1, 3);
	block* b3 = new block(c3);
	b3->set_location(2, 3);

	v.push_back(b1);
	v.push_back(b2);
	v.push_back(b3);
}