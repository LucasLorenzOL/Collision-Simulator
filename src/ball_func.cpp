#include "ball_header.hpp"
#include "vector_math.hpp"

// Update ball position with it velocity
void updateBallPosition(Bola &bola) {
    bola.shape.move(bola.velocity);
}

// Checks for collisions between balls and window border
void checkWallCollision(Bola &bola, sf::RenderWindow &window) {

    float posX = bola.shape.getPosition().x;
    float posY = bola.shape.getPosition().y;
    float radius = bola.shape.getRadius();

    // Inverts the direction of the velocity if a collision is detected
    if(posX + radius >= window.getSize().x || posX - radius <= 0)
        bola.velocity.x = -bola.velocity.x;

    if(posY + radius >= window.getSize().y || posY - radius <= 0)
        bola.velocity.y = -bola.velocity.y;

}

// Checks for collisions between balls
float checkBallCollision(std::vector<Bola> &listaBolas, unsigned short numBolas, float cv) {

    float dx, dy, radius, radius2, sumRadius;
    float sumVel = 0;

    for(int i = 0; i < numBolas; i++) {

        Bola& bola = listaBolas[i];
        radius = bola.shape.getRadius();

        for(int j = i + 1; j < numBolas; j++) {

            Bola& bola2 = listaBolas[j];
            radius2 = bola2.shape.getRadius();

            sumRadius = radius + radius2;

            dx = bola.shape.getPosition().x - bola2.shape.getPosition().x;
            dy = bola.shape.getPosition().y - bola2.shape.getPosition().y;

            // If the distance between 2 balls is less than the sum of the radius, then
            if((dx * dx) + (dy * dy) <= sumRadius * sumRadius) {

                sf::Vector2f collisionAxis = {dx, dy};
                
                // Velocity projection on collision axis
                sf::Vector2f v1_n;
                sf::Vector2f v2_n;
                sf::Vector2f vCM_n;

                // overlap between ball1 and ball2
                sf::Vector2f overlap;

                float distance = std::sqrt((dx * dx) + (dy * dy));
                float v1Scalar, v2Scalar;

                // Normalized collision axis
                collisionAxis = scalarProduct(collisionAxis, (1/distance));

                // Scalar obtained from dot product with ball velocity and collision axis
                v1Scalar = dotProduct(bola.velocity, collisionAxis);
                v2Scalar = dotProduct(bola2.velocity, collisionAxis);

                // Projected velocities
                v1_n = scalarProduct(collisionAxis, v1Scalar);
                v2_n = scalarProduct(collisionAxis, v2Scalar);

                // Projected center of mass velocity (constant)
                vCM_n = vectorialSum(v1_n, v2_n);
                vCM_n = scalarProduct(vCM_n, 0.5f);

                // Updates balls velocities using the formula
                bola.velocity.x += (1 + cv)*vCM_n.x - (1 + cv)*v1_n.x;
                bola.velocity.y += (1 + cv)*vCM_n.y - (1 + cv)*v1_n.y;

                bola2.velocity.x += (1 + cv)*vCM_n.x - (1 + cv)*v2_n.x;
                bola2.velocity.y += (1 + cv)*vCM_n.y - (1 + cv)*v2_n.y;

                // Turns the collision instantaneous
                overlap = scalarProduct(collisionAxis,  0.5f * (sumRadius - distance));

                bola.shape.move(overlap);
                bola2.shape.move(scalarProduct(overlap, -1));
            }

        }
    }

    // Calculates the v² for kinectic energy formula
    for(const auto& bola : listaBolas) {
        sumVel += (bola.velocity.x * bola.velocity.x) + (bola.velocity.y * bola.velocity.y);
    }

    // Returns the total kinectic energy of the system
    return sumVel * 0.5f;
}