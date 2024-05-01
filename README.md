# Charles Library

Charles is a simple library for simulating a population of cells moving around and reproducing in a window using the SFML library.

## Features

- Simulates a population of cells with individual characteristics.
- Cells move based on randomly generated neuron values.
- Each cell has a random color and size.

## Requirements

- SFML library
- C++ compiler

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/JoaoLace/charles.git
    ```

2. Include the library files in your project.

## Usage

1. Include the Charles library header file in your C++ code:

    ```cpp
    #include "charles.h"
    ```

2. Call the `run()` function to start the simulation:

    ```cpp
    int main() {
        Charles::run();
        return 0;
    }
    ```

## Customization

You can customize the behavior of the cells by modifying the parameters in the `config` struct and the by calling the function Charles::set_config() on the main file (before calling run()), that takes as paramenparameters -> int width (of the screen) , int height (of the screen), int cell_speed, int cell_max_size (radius), int cell_population (how much cells per generation):

    ```cpp
    int main() {
        Charles::run();
        return 0;
    }
    ```
    

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.txt) file for details.
