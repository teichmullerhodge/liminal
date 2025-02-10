#include "raylib.h"
#include "shapes.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <vector>
#include "movement.hpp"

#define FPS 180


int main(int argc, char **argv){

	InitWindow(800, 600, "Meu app");
	std::vector<_2dShapes> shapesVector; //will use it later. 
	//Can you do this GOLANG DEV? 

	_2dShapes shapes = {.index = 0, 
						.currentShape = Shape::CIRCLE, 
						.coordinates = {400, 300},
						.shapeColor = {255, 255, 255, 255},
						.shapeSize = 40,
						.close = false
						};

	srand(time(NULL));
	SetTargetFPS(FPS);

	while(!WindowShouldClose() && shapes.close == false){

			Movement::handle_movement(&shapes);

			ClearBackground(MAROON);
			DrawText("Hello, world!", 400, 400, 40, RAYWHITE);
			DrawShape(&shapes);
		EndDrawing();
	}


	return 0;

}