#include "utilities.h"
void flush()
{
	char c;
	while(c = getchar())
	{
		if(c == '\n')
		break;
	}
}
