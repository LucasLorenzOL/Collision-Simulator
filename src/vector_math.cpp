#include "vector_math.hpp"

float dotProduct(sf::Vector2f &vector1, sf::Vector2f &vector2) {
    return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

sf::Vector2f scalarProduct(sf::Vector2f &vector1, float scalar) {
    return sf::Vector2f({vector1.x * scalar, vector1.y * scalar});
}

sf::Vector2f vectorialSum(sf::Vector2f &vector1, sf::Vector2f &vector2) {
    return sf::Vector2f({vector1.x + vector2.x, vector1.y + vector2.y});
}

float vectorLenght(sf::Vector2f &vector) {
    return std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
}
