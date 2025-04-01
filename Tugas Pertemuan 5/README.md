# ❄️ 3D Snowman Object Simulation - OpenGL

## 📄 Description
This project demonstrates a 3D simulation using OpenGL that displays a 3D snowman as the main object in the scene, complete with basic lighting. The snowman is created using multiple spheres for the body, head, and other features, with cylinders representing its arms, nose, and hat. The simulation allows the user to interact with the snowman by rotating the camera and observing the object from different angles. Basic lighting is applied to enhance the visualization of the snowman and its features in the 3D space.

The functions used in this project include:

- **`drawSphere()`**: Draws a sphere, which is used to represent the snowman’s body and head.
- **`drawCylinder()`**: Draws a cylinder, used for the snowman’s arms, nose, and hat.
- **`drawSnowman()`**: Constructs the entire snowman by combining spheres and cylinders for its body, head, arms, and accessories.
- **`display()`**: Renders the 3D scene, applies camera rotations, and swaps buffers to update the view.
- **`reshape()`**: Adjusts the viewport and projection matrix when the window is resized.
- **`mouse()`**: Handles mouse input for rotating the scene when the user clicks and drags the mouse.
- **`motion()`**: Updates the camera’s rotation based on the mouse’s movement.
- **`keyboard()`**: Handles keyboard input to exit the program when the Escape key is pressed.
- **`init()`**: Initializes the OpenGL environment, enabling lighting, depth testing, and setting the clear color for the background.

## 🎮 Screenshot
![3D Snowman Object Screenshot](https://github.com/user-attachments/assets/b8a066cc-0834-47e0-ade8-0295e46554c6)

## 🌟 Features
- **3D Snowman Simulation**: Displays a 3D snowman that can be interacted with by rotating and zooming the camera.
- **Camera Controls**: Rotate and move the camera around the scene using mouse movements.
- **Lighting**: Basic lighting is applied to illuminate the snowman and make it visually more appealing.
- **Mouse Controls**: Click and drag the mouse to rotate the snowman and view it from different angles.
- **Keyboard Control**:
  - **Esc**: Exit the program.

## 📝 Author
- **Adriano Bawan**
- **Date**: April 1, 2025
