#include "raylib.h"
#include "shapes.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <vector>
#include "movement.hpp"
#include "interaction.hpp"

#define FPS 180




int main(int argc, char **argv){

	InitWindow(1600, 800, "Meu app");
	std::vector<_2dShapes> applicationShapes;

	_2dShapes shapes = {.index = 0, 
						.currentShape = Shape::CIRCLE, 
						.coordinates = {400, 300},
						.shapeColor = {255, 255, 255, 255},
						.shapeSize = 40,
						.close = false
						};

	ApplicationState appState = {.shapeCounter = 0, .backgroundColor = MAROON};
	srand(time(NULL));
	SetTargetFPS(FPS);
	bool isRunning = true;
	
	applicationShapes.push_back(shapes);

	while(!WindowShouldClose() && isRunning){


		
		
		if(IsKeyDown(KEY_Q)){
			
			isRunning = false;
			break;
		} 

		//capture the mouse clicked position
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			
			_2dCoord mousePos = GetMousePosition();
			Interaction::handle_change_figure_click(&applicationShapes, &appState, &mousePos);
						
		}
		
		
		
		

		Movement::handle_movement(&applicationShapes[appState.shapeCounter], &applicationShapes, &appState);
			ClearBackground(appState.backgroundColor);
			DrawShape(&applicationShapes);
		EndDrawing();
	}


	return 0;

}