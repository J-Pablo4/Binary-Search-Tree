//
// Created by jplop on 02/11/2022.
//

#ifndef ARBOLES_BINARIOS_SET_H
#define ARBOLES_BINARIOS_SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct set Set;
Set* set_new(int (*compare)(void* a, void* b));

Set* set_add(Set *set, void *element);

int set_contains(Set *set, void *element);

#endif //ARBOLES_BINARIOS_SET_H
