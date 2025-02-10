#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP


#include "raylib.h"
#include "shapes.hpp"
#include <time.h>
#include <iostream>

namespace Movement {


    int handle_movement(_2dShapes* shapeRef){

        		if(IsKeyDown(KEY_Q)){
			shapeRef->close = true;
		}
		if(IsKeyDown(KEY_N)){
			
		}

		if(IsKeyDown(KEY_K)){
			shapeRef->index = shapeRef->index >= 2 ? 0 : shapeRef->index + 1;
			change_shape(shapeRef);			
		}
		if(IsKeyDown(KEY_KP_5)){
			shapeRef->shapeSize += 1;
		}
		if(IsKeyDown(KEY_KP_2)){
			shapeRef->shapeSize -= 1;
		}

		if(IsKeyDown(KEY_C)){
			
			unsigned char R =(unsigned char)rand() % 255;
			unsigned char G = (unsigned char)rand() % 255;
			unsigned char B = (unsigned char)rand() % 255;
			std::cout << G << '\n';
			shapeRef->shapeColor = {
								 .r = R, 
								 .g = G, 
								 .b =B, 
								 .a = (unsigned char)255
								};
		// std::this_thread::sleep_for(std::chrono::milliseconds(300));

		}
		if(IsKeyDown(KEY_UP)){
			shapeRef->coordinates.y -= 3;
		}
		if(IsKeyDown(KEY_DOWN)){
			shapeRef->coordinates.y += 3;
		}
		if(IsKeyDown(KEY_RIGHT)){
			shapeRef->coordinates.x += 3;
		}
		if(IsKeyDown(KEY_LEFT)){
			shapeRef->coordinates.x -= 3;
		}
        
    }
};



#endif 