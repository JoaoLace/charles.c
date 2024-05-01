#ifndef __CHARLES_H__
#define __CHARLES_H__

#include <stdio.h>
#include <vector>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600

typedef float Neuron;

float cell_speed = 4;

sf::RenderWindow *window;
bool running = true;
typedef struct cell
{
    cell(){
        this-> sprite.setFillColor(color);
        this-> sprite.setRadius(size);
        this-> sprite.setPosition(inital_position.x, inital_position.y);
    }

    Neuron neuron_left;
    Neuron neuron_right;

    sf::Color color;
    sf::CircleShape sprite;

    size_t size;

    sf::Vector2i inital_position;

    void reproduce();
    void walk();
};

std::vector <cell> cells_vector;

void init_window(){
    window = new sf::RenderWindow(sf::VideoMode(WIDTH,HEIGHT),"Charles",sf::Style::Titlebar);
    window->setPosition(sf::Vector2i(600,300));
    window->setFramerateLimit(30);
}

void update_event()
{
 sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {
                     window->close();
                     running = false;
                }    
        }
}

void render_cells(){
    for (const cell& cell_unit : cells_vector)
    {
        window->draw(cell_unit.sprite);
    }
}
void cell::walk(){
       if (neuron_left > neuron_right){
            sprite.move(-cell_speed,0.f);
       }else if (neuron_right > neuron_left){
           sprite.move(cell_speed,0.f);
       }
}
void cells_move(){
for (cell& cell_unit : cells_vector)
    {
        cell_unit.walk();
    }
}
void update(){
    update_event();
    cells_move();
}

void render(){
    window->clear();
    render_cells();
    window->display();
}

sf::Color random_color(int key){
    switch (key) {
        case 1:
            return sf::Color::Red;
        case 2:
            return sf::Color::Green;
        case 3:
            return sf::Color::Blue;
        case 4:
            return sf::Color::Magenta;
        default:
            return sf::Color::White; 
}}

void cell::reproduce(){
    // TODO
}


cell creat_cell(){
    cell temp;

    temp.inital_position = {rand() % 800, rand() % 600};
    temp.neuron_left = rand() % 10;
    temp.neuron_right = rand() % 10;
    temp.sprite.setFillColor(random_color(rand() % 5 + 1));
    temp.sprite.setPosition(rand() % 800, rand() % 600);
    temp.size = rand() % 10;

    return temp;
}

void init_cells(size_t number_of_cells){
    for (size_t i = 0; i < number_of_cells; ++i){
       cells_vector.push_back(creat_cell());
    }
}

void run(){
    init_window();
    init_cells(300);
    while (running)
    {
       update();
       render();
    }
    
}

#endif