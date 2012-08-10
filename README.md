# n-body simulation
## An homemade planetarium
The aim of this demo is to try out OpenGL with a topic that I dig.

## What is this math?!
Meh, I suck at calculus and stuff.  In fact, I hope this project will
motivate me in mastering it by giving me a purpose to learn.

## What is this C++?!
I'm learning C++ with this project.  However, `freeglut` (the library I 
use to manage the basic OpenGL stuff) makes it really hard to use OO
 programming, thus the procedural style.

If I keep working on this side-project long enough, I'll eventually port
it to use SDL.

## TODO
* Create a scene with 2-bodies.
* Give physic properties to the bodies.
    * Must include mass;
    * Must include volume;
    * Must include position/speed/acceleration;
    * Must include collision detection.
* Animate the bodies as a function of time.
* EXTRA: Trace the future trajectory of the body
* EXTRA++: Make this trace time-colored (so if two trajectories cross at
        a similar color, I can predict a collision!)
* Increase to 3-bodies.
* Increase to n-bodies.
* Enter the properties of the Solar system and try to simulate it.
* Separate the computation of the n-bodies from the graphic rendering
loop, to permit variable precision in the simulation step.
