export module Utils:Screen;

import <iostream>;
import <stdlib.h>;

export namespace Screen {
	void clear() {
#if defined _WIN32
		system("cls");
#else
		system("clear");
#endif
	}
}