#include "int2.h"

const int2 int2::Left	= {-1, 0};
const int2 int2::Right	= {1, 0};
const int2 int2::Up		= {0, -1};
const int2 int2::Down	= {0, 1};
const int2 int2::Zero	= {0, 0};

int2::int2()
{
}

int2::int2(int _x) :
	x(_x)
{
}

int2::int2(int _x, int _y) :
	x(_x),
	y(_y)
{
}

int2::~int2()
{
}
