#ifndef CHARLES_H
#define CHARLES_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

#define WIDTH 800
#define HEIGHT 600
float cell_speed = 3.f;

namespace Charles {
    struct Configuration {
        Configuration(int width, int height, int cell_speed, int cell_max_size,
                      int cell_population){
            this->width = width;
            this->height = height;
            this->cell_speed = cell_speed;
            this->cell_max_size = cell_max_size;
            this->cell_population = cell_population;
        }
        int width;
        int height;
        int cell_speed;
        int cell_max_size;
        int cell_population;
    };
    struct Cell {
        // Constructor
        Cell() {
            sprite.setFillColor(color);
            sprite.setRadius(size);
            sprite.setPosition(initial_position.x, initial_position.y);
        }

        // Member variables
        float neuron_left;
        float neuron_right;
        sf::Color color;
        sf::CircleShape sprite;
        size_t size;
        sf::Vector2i initial_position;

        void check_colision();
        // Member functions
        void reproduce(); 
        // TODO: Implement reproduction
        void walk();
    };

    // Global variables
    float cell_speed;;
    sf::RenderWindow *window;
    bool running = true;
    std::vector<Cell> cells_vector;

    Configuration config(800,600,5,20,300);

    void set_config(int width, int height, int cell_speed, int cell_max_size,
    int cell_population);
        

    // Function to initialize the window
    void init_window();

    // Function to handle update events
    void update_event();

    // Function to render cells
    void render_cells();

    // Function to move cells
    void cells_move();

    // Function to update the simulation
    void update() ;

    // Function to render the simulation
    void render();

    // Function to generate a random color
    sf::Color random_color(int key); 

    // Function to create a cell
    Cell create_cell();
    
    // Function to initialize cells
    void init_cells(size_t number_of_cells);
    
    // Function to run the simulation
    void run();

// Functions definitions // 
    void set_config(int width, int height, int cell_speed, int cell_max_size,
        int cell_population){
            config.width = width;
            config.height = height;
            config.cell_speed = cell_speed;
            config.cell_max_size = cell_max_size;
            config.cell_population = cell_population;
        }
    void Cell::check_colision(){
        float x = sprite.getPosition().x;
        float y = sprite.getPosition().y;
        if (x <= 0){
            sprite.setPosition(0,y);
        }
        if (x >= config.width - (size * 2)){
            sprite.setPosition(config.width - (size * 2),y);
        }
        if (y <= 0){
            sprite.setPosition(x,0);
        }
        if (y >= config.height){
            sprite.setPosition(x,config.height);
        }
    }

    void Cell::walk(){
        cell_speed = config.cell_speed;
        check_colision();
            if (neuron_left > neuron_right) {
                sprite.move(-cell_speed, 0.f);
            } else if (neuron_right > neuron_left) {
                sprite.move(cell_speed, 0.f);
            }
    }
    
    void update_event() {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
                running = false;
            }
        }
    }
    void init_window() {
        window = new sf::RenderWindow(sf::VideoMode(config.width, config.height), "Charles", sf::Style::Titlebar);
        window->setPosition(sf::Vector2i(600, 300));
        window->setFramerateLimit(30);
    }
    void render_cells() {
        for (const Cell& cell_unit : cells_vector) {
            window->draw(cell_unit.sprite);
        }
    }
    void cells_move() {
        for (Cell& cell_unit : cells_vector) {
            cell_unit.walk();
        }
    }
    void update(){
        update_event();
        cells_move();
    }
    void render() {
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
        }
    }
    Cell create_cell() {
            Cell temp;
            temp.initial_position = {rand() % 800, rand() % 600};
            temp.neuron_left = rand() % 10;
            temp.neuron_right = rand() % 10;
            temp.sprite.setFillColor(random_color(rand() % 5 + 1));
            temp.sprite.setPosition(rand() % 800, rand() % 600);
            temp.size = rand() % 10;
            return temp;
        }
    void run(){
        init_window();
        init_cells(config.cell_population);
        while (running) {
            update();
            render();
        }
    }
    void init_cells(size_t number_of_cells){
        for (size_t i = 0; i < number_of_cells; ++i) {
            cells_vector.push_back(create_cell());
        }
    }
} // namespace Charles

#endif // CHARLES_H
