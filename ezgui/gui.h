#pragma once
#include "raylib.h"

class GUI {
	void draw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Hello Raylib!", 5, 5, 20, BLACK);
		EndDrawing();
	}
public:
	const int width;
	const int height;
	const char* title;
	GUI(int width, int height, const char* title) : width(width), height(height), title(title) {}
	void show() {
		// Load window assets
		Image favicon = LoadImage("../../../favicon.png");

		// Create window
		InitWindow(width, height, title);
		SetWindowIcon(favicon);

		// Draw the window while open
		while (!WindowShouldClose()) {
			draw();
		}

		// Close window
		CloseWindow();
	}
};