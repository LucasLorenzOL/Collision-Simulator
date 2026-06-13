#pragma once

#include <SFML/Graphics.hpp>
#include <random>

static std::random_device rd;
static std::mt19937 generator(rd());

sf::Color generateRandomColor();

// Generate a random position to the ball, without creating 2 ball overlaping each other 
template <typename T>
sf::Vector2f generateRandomPosition(sf::RenderWindow &window, float radius, std::vector<T>& listaBolas) {

    // Capping the possible position
    std::uniform_real_distribution<float> distanceX(radius * 2, window.getSize().x - radius * 2);
    std::uniform_real_distribution<float> distanceY(radius * 2, window.getSize().y - radius * 2);

    // Generating position
    float posX = distanceX(generator);
    float posY = distanceY(generator);

    float dx;
    float dy;
    float radius2;

    bool isUnique = false;

    // Runs until ball position is unique
    while (!isUnique) {
        
        isUnique = true;
        
        // Checks if position is unique
        for(const auto& bola: listaBolas) {
            dx = bola.shape.getPosition().x - posX;
            dy = bola.shape.getPosition().y - posY;

            radius2 = bola.shape.getRadius();

            // If 2 balls are overlaping, then
            if((dx * dx) + (dy * dy) <= (radius + radius2) * (radius + radius2)) {

                // Generating new position
                posX = distanceX(generator);
                posY = distanceY(generator);

                isUnique = false;
                break;
            }
        }
    }

    return sf::Vector2f({posX, posY});
}

sf::Vector2f generateRandomVelocity();