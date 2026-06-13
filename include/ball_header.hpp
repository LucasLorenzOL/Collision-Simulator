#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "ball_gen.hpp"

struct Bola {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Bola(float radius, sf::RenderWindow &window, std::vector<Bola>& listaBolas) {
        shape.setRadius(radius);
        shape.setOrigin({radius, radius}); // Turns the "origin" the center of the ball
        shape.setFillColor(generateRandomColor());
        shape.setPosition(generateRandomPosition(window, radius, listaBolas));

        velocity = generateRandomVelocity();
    }
};

void updateBallPosition(Bola &bola);
void checkWallCollision(Bola &bola, sf::RenderWindow &window);
float checkBallCollision(std::vector<Bola> &listaBolas, unsigned short numBolas, float cv);