/* This class represents a node inside a A-star Grid */
/* F = G + H as a path scoring */
/* Choose the node with lower F */
#pragma once

class Node
{
public:
	Node();
	~Node();

	int get_F() const {
		return G + H;
	}

private:
	int G; /* Movement Cost from the starting node to this */
	int H;
};
