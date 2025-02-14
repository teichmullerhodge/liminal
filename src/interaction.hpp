#ifndef INTERACTION_HPP
#define INTERACTION_HPP


#include "raylib.h"
#include "shapes.hpp"
#include <time.h>
#include <vector>
#include <iostream>

namespace Interaction {


    void handle_change_figure_click(std::vector<_2dShapes>* applicationShapesRef, 
                                    ApplicationState* State, 
                                    _2dCoord* mousePos){
                
                uint32_t absoluteDistance = 0;
                uint32_t appIndex = -1;
                uint32_t xDistance = 9999999;
                uint32_t yDistance = 9999999;

                for(auto &shape : *applicationShapesRef) {

                        uint32_t currentxDistance = abs(shape.coordinates.x - mousePos->x);
                        uint32_t currentyDistance = abs(shape.coordinates.y - mousePos->y);

                        xDistance = currentxDistance < xDistance ? currentxDistance : xDistance;
                        xDistance = currentxDistance < xDistance ? currentxDistance : xDistance;
                        


                }

        
    }
};



#endif 