#include "raylib.h"

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,
             "raylib [core] example - window should close");

  SetExitKey(
      KEY_NULL); // Disable KEY_ESCAPE to close window, X-button still works

  bool exitWindowRequested = false; // Flag to request window to exit
  bool exitWindow = false;          // Flag to set window to exit

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  while (!exitWindow) {
    if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
      exitWindowRequested = true;

    if (exitWindowRequested) {
      if (IsKeyPressed(KEY_Y))
        exitWindow = true;
      else if (IsKeyPressed(KEY_N))
        exitWindowRequested = false;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    if (exitWindowRequested) {
      DrawRectangle(0, 100, screenWidth, 200, BLACK);
      DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30,
               WHITE);
    } else
      DrawText("Try to close the window to get confirmation message!", 120, 200,
               20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  CloseWindow(); // Close window and OpenGL context
  return 0;
}
