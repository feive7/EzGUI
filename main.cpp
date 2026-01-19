#include <iostream>

#include "ezgui/gui.h"
void ChangeVolume(int amount) {
	if (amount == 0) return;
	printf("Volume %s %i\n", (amount > 0 ? "up" : "down"), abs(amount));
}
void TogglePlay(bool& state) {
	state = !state;
	printf("%s\n", (state ? "Playing" : "Paused"));
}
void Skip(int count) {
	if (count == 0) return;
	printf("Skip %s %i\n", (count > 0 ? "forward" : "backward"), abs(count));
}

int main() {
	// Create GUI
	GUI main_gui(500,273,"EzGUI");
	main_gui.makeBorderless();          // Hide top bar
	main_gui.setBackgroundColor(BLANK); // Make transparent

	// Fake controls
	bool playing = true;

	main_gui.addImageLabel(143, 67, 211, 79, "../../../test_image.png");
	main_gui.addImageLabel(0, 0, 500, -1, "../../../aeroplayer.png");

	main_gui.addRawButton(426, 87, 35, 33, std::bind(ChangeVolume, 1));
	main_gui.addRawButton(415, 133, 36, 32, std::bind(ChangeVolume, -1));
	main_gui.addRawButton(36, 88, 35, 32, std::bind(TogglePlay,playing));
	main_gui.addRawButton(47, 133, 35, 32, std::bind(Skip, 1));
	main_gui.addRawButton(76, 176, 36, 33, std::bind(Skip, -1));

	main_gui.show();

	std::cout << "GUI closed" << std::endl;

	return 0;
}