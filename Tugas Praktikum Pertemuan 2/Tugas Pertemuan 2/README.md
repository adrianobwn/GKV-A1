# 🚗 OpenGL 2D Car Simulation

## 📄 Description
This project is a 2D car simulation built using OpenGL (GLUT). The project demonstrates basic 2D graphics concepts, including drawing simple shapes to create a car object with a background. The functions used in this project include:

- **`glTranslatef()`**: Used to move objects in 2D space. This function is used to position the car and other elements (wheels, windows) on the screen.
- **`glColor3f()`**: Used to set the color of objects. This is used to color the car body (red), windows (light blue), and wheels (black).
- **`glBegin(GL_QUADS)` and `glEnd()`**: These functions are used to draw rectangular-shaped objects (e.g., car body, windows, bumper).
- **`glVertex3f()`**: Used to define the coordinates of the points of the object being drawn. This function is used to draw the sides of the rectangular objects.
- **`glBegin(GL_POLYGON)`**: Used to draw circular objects (e.g., car wheels). This function draws a circle using points calculated through trigonometric functions.
- **`glFlush()`**: This function is used to ensure all objects are drawn and displayed on the screen.

## 🎮 Screenshot
![Screenshot 2025-03-08 112410](https://github.com/user-attachments/assets/49ba75b1-3316-4e87-bfc2-bbeed28c8810)

## 🌟 Features
- **Car Object**: Drawn with basic shapes (rectangles for the body and windows, circles for the wheels).
- **Background**: A blue background.
- **Color Usage**: Red for the car body, light blue for the windows, and gray for the wheels.
- **2D Transformations**: Uses translation to position the car and other elements on the screen.

## 📝 Author
- **Adriano Bawan**
- **Date**: March 3, 2025

