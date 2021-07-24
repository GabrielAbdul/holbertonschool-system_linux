#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

void race_state(int *id, size_t size);
/**
 * struct car_s - represents a car in a race
 * @id: id
 * @laps: # of laps
 */
typedef struct car_s
{
    int id;
    int laps;
    struct car_s *next;
} car_t;

int newCar(car_t *cars, int id);
car_t *pushCar(car_t **cars, int id);
void addLaps(car_t *cars, int id);
void free_everything(car_t *cars);
#endif /* LAPS_H */