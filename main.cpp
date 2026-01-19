#include <iostream>

#include "ezgui/gui.h"

int main() {
	// Create GUI
	GUI main_gui(500,500,"EzGUI");
	main_gui.addLabel(40, 64, 20, "Hello EzGUI!");

	main_gui.show();

	std::cout << "GUI closed" << std::endl;

	return 0;
}