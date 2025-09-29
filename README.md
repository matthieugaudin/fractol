## Project Overview

Fract-ol is a fractal explorer built in C with the MiniLibX graphics library as part of the 42 curriculum.  
It allows interactive visualization of famous fractals with zooming, panning, and color customization.


## Project Structure

```md
fract-ol
├── include
│   └── fractol.h
├── libft
├── mlx_linux
├── src
│   └── *.c
├── Makefile
└── README.md
```


## Features

- Mandelbrot set
- Julia sets (with interactive parameters)
- Burning Ship set
- Adjustable iteration depth
- Keyboard navigation with arrow keys
- Mouse-following zoom
- Color shifting
- RGB color interpolation


## Installation and Usage

1. Clone the repository:
```bash
git clone https://github.com/matthieugaudin/fractol.git
cd fractol
```
2. Compile the project
```bash
make
```
3. Display the usage/help message
```bash
./fractol
```
4. Test the program with different arguments
```bash
./fractol mandelbrot
./fractol julia
./fractol burningship
```


## How Fract-ol Works

- Parse user arguments to select fractal type
- Initialize MiniLibX library
- Map each pixel to a complex number
- Iterate the fractal formula
- Assign colors based on iteration count
- Draw the computed image to the window
- Listen for user inputs (keyboard/mouse) to update the view in real-time


## Conclusion

This project taught me how to use a graphical library and experiment with interactive rendering.
I learned the basics of graphics programming while practicing with complex numbers and real-time inputs.
If you have any questions or need more details, feel free to contact me.
