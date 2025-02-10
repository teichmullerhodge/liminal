#ifndef SHAPES_HPP
#define SHAPES_HPP

#include "raylib.h"
#include <stdint.h>
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
    // if(shapeRef->index == 3){
    //     shapeRef->currentShape = Shape::TRIANGLE;
    //     return;
    // }

}


void DrawShape(_2dShapes* shapeRef){
    if(shapeRef->currentShape == Shape::CIRCLE){
        DrawCircle(shapeRef->coordinates.x, shapeRef->coordinates.y, shapeRef->shapeSize, shapeRef->shapeColor);
    }
    if(shapeRef->currentShape == Shape::SQUARE){
        DrawRectangle(shapeRef->coordinates.x, 
                     shapeRef->coordinates.y, 
                     shapeRef->shapeSize, 
                     shapeRef->shapeSize, 
                     shapeRef->shapeColor);
    }
    if(shapeRef->currentShape == Shape::RECTANGLE){
        DrawRectangle(shapeRef->coordinates.x, 
                     shapeRef->coordinates.y, 
                     shapeRef->shapeSize, 
                     (shapeRef->shapeSize/2), 
                     shapeRef->shapeColor);

    }



}



#endif