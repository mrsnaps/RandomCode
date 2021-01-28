//
// Created by natha on 27/01/2021.
//

#include "grammerRemover.h"
std::string grammerGone(std::string x){
    std::vector<char> toRemove= {'!','-',',','.'};
    for (int i = 0; i < x.length(); ++i) {
        for (int j = 0; j < toRemove.size(); ++j) {
            if (x[i] == toRemove[j]){
                x[i] = ' ';
            }
        }
    }
    return x;
}