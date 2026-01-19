#include <iostream>
#include "raylib.h"

int main() {
	// Define window dimensions
	const int window_width = 800;
	const int window_height = 600;

	// Create window
	InitWindow(window_width, window_height, "EzGUI Demo");

	// Main loop
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Hello Raylib!", 5, 5, 20, BLACK);
		EndDrawing();
	}

	// Close window
	CloseWindow();

	return 0;
}