#include <iostream>

#include "ezgui/gui.h"

int main() {
	// Create GUI
	GUI main_gui(500,500,"EzGUI");
	main_gui.addImageLabel(0, 0, 500, 500, "../../../test_image.png");
	main_gui.addTextLabel(5, 5, 20, WHITE, "Hello EzGUI!");
	main_gui.addTextButton(200, 200, 40, WHITE, "Hello!", { 200,200,255,255 }, { 100,100,255,255 }, "echo Hello World");

	main_gui.show();

	std::cout << "GUI closed" << std::endl;

	return 0;
}