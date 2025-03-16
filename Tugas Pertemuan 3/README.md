# 🤖 3D Arm and Finger Simulation OpenGL

## 📄 Description
This project demonstrates a 3D arm and finger animation built using OpenGL (GLUT). The simulation includes basic body parts such as the upper arm, lower arm, hand, and fingers. The project uses basic transformations like translation and rotation to simulate the movement of each arm segment.

The functions used in this project include:

- **`glTranslatef()`**: Used to translate (move) objects in 3D space. This function is used to position each arm, hand, and finger part at the appropriate coordinates.
- **`glRotatef()`**: Used to rotate objects in 3D space. This function is used to rotate the arm parts (shoulder, elbow, palm, fingers) based on keyboard input.
- **`glScalef()`**: Used to scale objects. This function is used to enlarge or shrink body parts such as the arms and fingers.
- **`glutWireCube()`**: Used to draw cube-shaped objects as a representation of the arm and finger parts.
- **`glPushMatrix()` and `glPopMatrix()`**: These functions are used to save and restore the model matrix state, allowing separate manipulation of objects without affecting others.
- **`glutPostRedisplay()`**: Requests GLUT to redraw the display whenever there is a change in the position or rotation of an object.
- **`glutKeyboardFunc()`**: Sets the function to receive keyboard input and change the position or rotation of objects based on the key pressed.

This simulation allows user interaction through keyboard input to control the rotation of each body part, such as the shoulder, elbow, palm, and fingers.

## 🎮 Screenshot
![3D Arm Simulation Screenshot](https://github.com/user-attachments/assets/ffee9b8b-a367-4bc8-bdc6-600e15be6c54)

## 🌟 Features
- **3D Arm Simulation**: Displays the upper arm, lower arm, and palm that can be rotated with control.
- **Fingers**: Adds five fingers (little finger, ring finger, middle finger, index finger, thumb) that can be rotated individually.
- **3D Transformations**: Uses translation and rotation to manipulate the position and orientation of the arm and finger parts.
- **Keyboard Controls**:
  - **'s' / 'S'**: Controls the rotation of the upper arm (shoulder).
  - **'e' / 'E'**: Controls the rotation of the lower arm (elbow).
  - **'f' / 'F'**: Controls the rotation of the palm.
  - **'1' - '5'**: Controls the rotation of each finger (little finger, ring finger, middle finger, index finger, thumb).
  - **Esc**: Exits the program.

## 📝 Author
- **Adriano Bawan**
- **Date**: March 16, 2025
