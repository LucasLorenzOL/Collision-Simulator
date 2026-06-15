#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <string>
#include <fstream>

#include "ball_header.hpp"

// Default settings
#define WIDTH 1280
#define HEIGHT 720
#define N 6
#define RADIUS 50.0f
#define CV 1

int main(int argc, char **argv) {

    unsigned int width = WIDTH; 
    unsigned int height = HEIGHT;
    unsigned int numBalls = N;
    float radius = RADIUS;
    float cv = CV;
    
    // Open config file
    std::ifstream configFile("../config/config.txt", std::ios::in);

    // If user input custom settings on terminal
    if(argc == 6) {
        try {
            width = std::stoi(argv[1]);
            height = std::stoi(argv[2]);
            numBalls = std::stoi(argv[3]);
            radius = std::stof(argv[4]);
            cv = std::stof(argv[5]);
        }
        catch(...) {}
    }
    else {

        // Uses config file settings instead
        if(configFile.is_open()) {

            std::string str;
            
            // Read the keyword and assign to the respective variable
            while(configFile >> str) {
                if(str == "width")
                    configFile >> width;
                else if(str == "height")
                    configFile >> height;
                else if(str == "num_balls")
                    configFile >> numBalls;
                else if(str == "radius")
                    configFile >> radius;
                else if(str == "CV")
                    configFile >> cv;
            }

            configFile.close();
        }
        else
            // If config file is not found, show error and use default settings
            std::cerr << "O arquivo de configuracoes nao foi encontrado!" << std::endl;

    }

    // Setup window
    sf::RenderWindow window = {sf::VideoMode({width, height}), "BALLS"};

    // Setup ball list
    std::vector<Bola> ballList;

    // Tries to load a font from assets folder
    sf::Font font;
    if(!font.openFromFile("../assets/Roboto-Regular.ttf")) {
        std::cerr << "Error: Roboto-Regular.ttf not found!" << std::endl;
        return -1;
    }
    
    // Kinectic energy data text
    sf::Text data(font, "", 15);
    data.setFillColor(sf::Color::White);
    data.setStyle(sf::Text::Bold);
    data.setPosition({10.0f, 10.0f});

    float ecTotal;

    // Create balls with random: Color, Speed and Position.
    for(int i = 0; i < numBalls; i++)
        ballList.push_back(Bola(radius, window, ballList));

    // Main loop
    while(window.isOpen()) {
        
        // Input reader state
        while(const std::optional<sf::Event> event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>())
                window.close();
        }

        // Update state
        for(int i = 0; i < numBalls; i++)
            updateBallPosition(ballList[i]);

        
        // Collision check state
        for(int i = 0; i < numBalls; i++)
            checkWallCollision(ballList[i], window);

        // checkBallCollision() returns the total kinectic energy of the system
        ecTotal = checkBallCollision(ballList, numBalls, cv);

        // Update the data of the system
        data.setString("Energia cinetica do sistema: " + std::to_string(ecTotal));

        // Rendering state
        window.clear(sf::Color::Black);

        for(int i = 0; i < numBalls; i++)
            window.draw(ballList[i].shape);

        window.draw(data);

        window.display();

    }

    return 0;
}
