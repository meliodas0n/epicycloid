#include<raylib.h>
#include<rlgl.h>
#include<math.h>

float Map(float X, float A, float B, float C, float D) {
	return (X - A) * (D - C) / (B - A) + C;
}

int main() {
	int WIDTH = 1000;
	int HEIGHT = 800;

	InitWindow(WIDTH, HEIGHT, "GAME");
	SetTargetFPS(144);

	int StepFactor = 2;
	int Radius = HEIGHT / 2 - 40;
	int NodeSize = 500;
	Vector2 Nodes[10000];

	for (int I = 0; I < NodeSize; ++I) {
		float Angle = Map(I, 0, NodeSize, 0, PI * 2);
		Nodes[I].x = Radius * cosf(Angle);
		Nodes[I].y = Radius * sinf(Angle);
	}

	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_LEFT)) --StepFactor;
		if (IsKeyPressed(KEY_RIGHT)) ++StepFactor;

		BeginDrawing();
		ClearBackground((Color) { 32, 32, 32, 255 });
		rlTranslatef(WIDTH / 2, HEIGHT / 2, 0);

		for (int I = 0; I < NodeSize; ++I) {
			Vector2 BeginLine = Nodes[I];
			Vector2 EndLine = {
				Nodes[I * StepFactor % NodeSize].x,
				Nodes[I * StepFactor % NodeSize].y
			};

			DrawLineV(BeginLine, EndLine, WHITE);
		}

		EndDrawing();
	}
}