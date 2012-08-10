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
    * Must include collision detection (to avoid near-zero 
            anomalities[1]).
* Animate the bodies as a function of time.
* EXTRA: Trace the future trajectory of the body
* EXTRA++: Make this trace time-colored (so if two trajectories cross at
        a similar color, I can predict a collision!)
* Increase to 3-bodies.
* Increase to n-bodies.
* Enter the properties of the Solar system and try to simulate it.
* Separate the computation of the n-bodies from the graphic rendering
loop, to permit variable precision in the simulation step.

[1] When two bodies get too close, the influence they have over one
another greatly increase, while the calculation step doesn't, leading to
huge approximation errors.  The most common effect is that the two
bodies will be greatly accelerated at t\_n, then be computed to a new
much greater distance at t\_n+1.  Because the two bodies at t\_n+1 are
now so far from each other, the new force they exert on one another will
not be sufficient enough to sufficiently slow back the two bodies.
Although the two bodies will eventually come back closer, it will be
at a great speed and the effect will only amplify with time.
