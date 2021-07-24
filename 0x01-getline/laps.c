#include "laps.h"

/**
 * race_state - keeps track of # of laps made by cars in a race
 * @id: array of int representing the “identifier” of each car.
 * @size: is the size of this array
 */
void race_state(int *id, size_t size)
{
	size_t i;
	car_t *car;
	static car_t *cars;

	/* if size is 0 free everything and return */
	if (size == 0)
	{
		free_everything(cars);
		return;
	}

	/* loop through array of cars */
	for (i = 0; i < size; i++)
	{
		/* if new car, add to list of cars, else increment its laps */
		if (newCar(cars, id[i]))
			cars = pushCar(&cars, id[i]);
		else
			addLaps(cars, id[i]);
	}

	printf("Race state:\n");
	for (car = cars; car; car = car->next)
		printf("Car %d [%d laps]\n", car->id, car->laps);
}

/**
 * newCar - determines if input car is new or not
 * @cars: list of cars
 * @id: car we are checking
 * Return: 1 if new car, else 0
 */
int newCar(car_t *cars, int id)
{
	car_t *car;

	for (car = cars; car; car = car->next)
	{
		/* if a car in the list has the id of the input car, ret 0 */
		if (car->id == id)
			return (0);
	}
	return (1);
}

/**
 * pushCar - adds car into list sorted by id
 * @cars: list of cars
 * @id: car to push
 * Return: list of cars
 */
car_t *pushCar(car_t **cars, int id)
{
	car_t *tmp = NULL;
	car_t *car = malloc(sizeof(car_t));

	if (!car)
		return (NULL);

	car->id = id;
	car->laps = 0;
	car->next = NULL;
	printf("Car %d joined the race\n", car->id);
	/* if cars is null or input id should be before first car */
	if (*cars == NULL || (*cars)->id >= car->id)
	{
		car->next = *cars;
		*cars = car;
		return (*cars);
	}

	tmp = *cars;
	/* loop until the new car id is < next car in list */
	while (tmp->next && tmp->next->id < car->id)
		tmp = tmp->next;

	car->next = tmp->next;
	tmp->next = car;

	return (*cars);
}

/**
 * addLaps - increments laps of cars we've seen before
 * @cars: list of cars
 * @id: car to increment laps
 */
void addLaps(car_t *cars, int id)
{
	car_t *car = cars;

	while (car && car->id != id)
		car = car->next;
	car->laps++;
}

/**
 * free_everything - frees all cars
 * @cars: list of cars
 */
void free_everything(car_t *cars)
{
	if (!cars)
		return;

	free_everything(cars->next);
	free(cars);
}
