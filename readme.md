# FdF - Wireframe Renderer Project Overview

## Project Description

The FdF (Fil de Fer) project is a graphical journey aimed at creating a 3D wireframe representation of landscapes. Harnessing the power of the MiniLibX library at 42 School, this program transforms a map of coordinates into an interactive visual terrain model. It incorporates fundamental programming operations like opening, reading, writing files, and dynamic memory allocation, along with mathematical and graphic capabilities, showcasing the versatility of C programming in graphical visualization.

## Enhanced Features

Beyond the core requirements, I have integrated an array of advanced features to elevate the user experience and showcase technical proficiency:
- **Multiple Projections**: Choose from isometric, orthogonal, and trigonometric projections to view the landscape from different perspectives.
- **3D Transformations**: Execute translations, rotations, and scaling on all three axes (X, Y, Z) for complete manipulation of the map's view.
- **Map Management**: Features include centering the map, resetting it to the last saved state (defaulting to the original state), and dynamically switching between maps by entering a new map name.
- **Special Option**: An exclusive rainbow effect feature adds a splash of color and creativity to the rendering.

## Usage

The program is executed as follows:
```
./fdf file_path/file.fdf
```

## Controls (AZERTY Keyboard on Linux)
- **Rotation**: A/Q (X-axis), Z/S (Y-axis), E/D (Z-axis)
- **Scaling**: U/J (X-axis), I/K (Y-axis), O/L (Z-axis)
- **Translation**: P/M (X-axis), ^/ù (Y-axis), $/* (Z-axis)
- **View Modes**: & (Isometric), é (Orthogonal), " (Trigonometric)
- **Map Management**: Spacebar (Center), Enter (Save State), Del (Reset)
- **Special Feature**: ² (Rainbow Effect)
- **Quit Programm**: Esc (you can also use the x button on the corner of the window)

This project is a testament not just to the ability to craft complex graphical representations, but also to a commitment to expanding user interaction within the realm of graphical programming.

Explore this project and its capabilities on the [GitHub repository], where you're also welcome to contribute and share ideas for further enhancements.