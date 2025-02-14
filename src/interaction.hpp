#ifndef INTERACTION_HPP
#define INTERACTION_HPP


#include "raylib.h"
#include "shapes.hpp"
#include <stdint.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <mutex>

namespace Interaction {


    void handle_change_figure_click(std::vector<_2dShapes>* applicationShapesRef, 
                                    ApplicationState* state, 
                                    _2dCoord* mousePos){
                
                uint32_t absoluteDistance = UINT32_MAX;
                uint32_t appIndex = 0;
                uint32_t counter = -1;
 
 
                for(auto &shape : *applicationShapesRef) {
                        counter++;
                        uint32_t currentxDistance = abs(shape.coordinates.x - mousePos->x);
                        uint32_t currentyDistance = abs(shape.coordinates.y - mousePos->y);
                        if((currentxDistance + currentyDistance) < absoluteDistance) {
                            absoluteDistance = currentxDistance + currentyDistance;
                            appIndex = counter;

                        }
                        


                }

                state->shapeCounter = appIndex;
        

    }



};




// S(400, 800)
// M(375, 490)
#endif 