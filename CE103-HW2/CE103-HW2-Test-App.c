#ifdef _WIN64
	#ifdef _DEBUG
		#pragma comment(lib, "..\\x64\\Debug\\CE103-HW2-Lib.lib")
	#else
		#pragma comment(lib, "..\\x64\\Release\\CE103-HW2-Lib.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment(lib, "..\\Debug\\CE103-HW2-Lib.lib")
	#else
		#pragma comment(lib, "..\\Release\\CE103-HW2-Lib.lib")
	#endif
#endif

#include "..\CE103-HW2-Lib\CE103-HW2-Lib.h"
#include <stdio.h>

int main()
{
	printf("CE103 Algorithms and Programming I HW-2\n");

	getch();

}
