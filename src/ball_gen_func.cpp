#include <random>

#include "ball_gen.hpp"

// Generates a random color to the ball
sf::Color generateRandomColor() {

    std::uniform_int_distribution<int> color(15, 255);

    int r = color(generator);
    int g = color(generator);
    int b = color(generator);
    
    return sf::Color(r, g, b);
}

// Generates a random velocity to the ball
sf::Vector2f generateRandomVelocity() {

    std::uniform_real_distribution<float> velocityX(-0.15f, 0.15f);
    std::uniform_real_distribution<float> velocityY(-0.05f, 0.05f);

    float velX = velocityX(generator);
    float velY = velocityY(generator);

    return sf::Vector2f({velX, velY});
}