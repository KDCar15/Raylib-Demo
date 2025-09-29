#include <stdio.h>
#include <raylib.h>
#include <math.h>

void DrawTextWithShadow(Font font, const char* text, Vector2 pos, int size, float idk, Color color, float shadow_osy, float shadow_osx, Color shadowColor);

int main()
{
	char texto[] = "Raylib Demo 4 - SinF Test         Presented by: KDCar";
	int letters = (sizeof(texto) / sizeof(char));
	printf("%d", letters);
	
	InitWindow(320, 240, "Prueba");
	SetTargetFPS(60);

	const int RES_X = 320;
	const int RES_Y = 240;

	int pos_x = 320;
	int pos_y = (240 / 2) - (24 / 2);
	int offset_x = 0;
	
	Sound music = LoadSound("res/class9.mod");
	Font fontlol = LoadFont("res/ibm.ttf");
	
	Color cur_color = BLUE;
	Color des_color = RED;
	int pause = 0;

	while(!WindowShouldClose())
	{
		PlaySound(music);
		
		if(IsKeyPressed(KEY_SPACE))
			pause = !pause;

		if(!pause){
			pos_x -= 2;
			offset_x -= 2;
		}
		if((pos_x - 14) + (offset_x - 14) < (letters * -14) - 64)
		{
			pos_x = RES_X;
			offset_x = 0;
		}

		BeginDrawing();
		ClearBackground(cur_color);
		
		Rectangle rec = (Rectangle){
			0 + 25,
			0 + 25,
			RES_X - 50,
			RES_Y - 50, 
		};

		DrawRectangleRec(rec, (Color){0, 0, 0, 127});
		DrawRectangleLinesEx(rec, 4, (Color){255, 255, 255, 127});	
	
		for(int i = 0; i < letters; i++)
		{
			int text_pos_x = pos_x + (14 * i - 2) + offset_x;
			int text_pos_y = (int)(25 * sinf(( (float)pos_x + (14.0f*i) )/50.0f)) + pos_y;
			int text_pos_y_cos = (int)(25 * cosf(( (float)pos_x + (14.0f*i) )/50.0f)) + pos_y;
			Vector2 text_pos = (Vector2){text_pos_x, text_pos_y};

			DrawTextWithShadow(fontlol, TextFormat("%c", texto[i]), text_pos, 14, 0.0f, WHITE, 1, 1, BLACK);
		}

		EndDrawing();
	}
	
	UnloadFont(fontlol);
	UnloadSound(music);
	CloseWindow();
	return 0;
}

void DrawTextWithShadow(Font font, const char* text, Vector2 pos, int size, float idk, Color color, float shadow_osy, float shadow_osx, Color shadowColor)
{
	Vector2 pos_shadow = (Vector2){pos.x + shadow_osy, pos.y + shadow_osx};
		
	DrawTextEx(font, text, pos_shadow, size, idk, shadowColor);
	DrawTextEx(font, text, pos, size, idk, color);
}
