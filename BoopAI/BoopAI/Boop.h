#pragma once
#include "DNA.h"
#include "Point.h"
#include "Food.h"
#include "NeuralNetwork.h"
#include <ctime>

class Boop {
	const double DegToRad = 3.14159265 / 180;
public:
	int foodEaten;
	NeuralNetwork nn;
	Point *location; // Location
	Point *target;
	DNA *dna;          // DNA
	float health;     // Life timer
	// DNA will determine size and maxspeed
	float r;
	float maxspeed;
	float survived;
	std::clock_t spawned;

	// Create a "boop" creature
	Boop(Point *l, DNA *dna_);

	void run(Food *f);

	// A boop can find food and eat it
	void eat(Food *f);

	// At any moment there is a teeny, tiny chance a boop will reproduce
	Boop *reproduce(Boop *parent);

	// Method to update location
	void update(Food *f);

	// Wraparound
	void borders();

	// Method to display
	void display();

	// Death
	bool dead();
};