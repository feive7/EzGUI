#include <iostream>

#include "ezgui/gui.h"

int main() {
	// Create GUI
	GUI main_gui(500,273,"EzGUI");
	main_gui.makeBorderless();          // Hide top bar
	main_gui.setBackgroundColor(BLANK); // Make transparent

	main_gui.addImageLabel(0, 0, 500, -1, "../../../aeroplayer.png");
	main_gui.addRawButton(426, 87, 35, 33, "echo Volume up");
	main_gui.addRawButton(415, 133, 36, 32, "echo Volume down");
	main_gui.addRawButton(36, 88, 35, 32, "echo Pause");
	main_gui.addRawButton(47, 133, 35, 32, "echo Next");
	main_gui.addRawButton(76, 176, 36, 33, "echo Back");

	main_gui.show();

	std::cout << "GUI closed" << std::endl;

	return 0;
}