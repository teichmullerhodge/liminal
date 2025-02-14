#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "raylib.h"
#include <stdint.h>
#include <vector>

typedef Vector2 _2dCoord;
typedef Vector3 _3dCoord;
typedef Vector4 _4dCoord;


///Implementation for 2d shapes

enum Shape {

    CIRCLE = 0,
    SQUARE,
    RECTANGLE
    // TRIANGLE,

};

typedef struct {

    uint8_t index;
    enum Shape currentShape;
    _2dCoord coordinates;
    Color shapeColor;
    unsigned int shapeSize;
    bool close;

} _2dShapes;


typedef struct {

	int shapeCounter;
    Color backgroundColor;
    

} ApplicationState;


_2dShapes new_default_shape(_2dCoord actualPosition){


	_2dShapes shape = {.index = 0, 
						.currentShape = Shape::CIRCLE, 
						.coordinates = actualPosition,
						.shapeColor = {0, 0, 255, 255},
						.shapeSize = 40,
						.close = false
						};
    return shape;


}

void change_shape(_2dShapes* shapeRef){

        if(shapeRef->index == 0){
            shapeRef->currentShape = Shape::CIRCLE;
            return;
        }
        if(shapeRef->index == 1){
            shapeRef->currentShape = Shape::SQUARE;
            return;
        }
        if(shapeRef->index == 2){
            shapeRef->currentShape = Shape::RECTANGLE;
            return;
        }
        
    }


void DrawShape(std::vector<_2dShapes>* shapesRef){

    for(auto &shape : *shapesRef){


            if(shape.currentShape == Shape::CIRCLE){
                DrawCircle(shape.coordinates.x, shape.coordinates.y, shape.shapeSize, shape.shapeColor);
            }
            if(shape.currentShape == Shape::SQUARE){
                DrawRectangle(shape.coordinates.x, 
                            shape.coordinates.y, 
                            shape.shapeSize, 
                            shape.shapeSize, 
                            shape.shapeColor);
            }
            if(shape.currentShape == Shape::RECTANGLE){
                DrawRectangle(shape.coordinates.x, 
                            shape.coordinates.y, 
                            shape.shapeSize, 
                            (shape.shapeSize/2), 
                            shape.shapeColor);

            }

        }

}





#endif