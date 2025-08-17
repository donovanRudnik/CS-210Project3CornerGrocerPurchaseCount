#include "UserMenu.h"


int main() {
	UserMenu menu;
	int whileCheck;

	menu.PrintMenu();
	whileCheck = menu.GetMenuNumSelection();

	while (whileCheck != 4) {
		menu.MenuFunctions();
		menu.PrintMenu();
		whileCheck = menu.GetMenuNumSelection();
	}
	return 0;
}