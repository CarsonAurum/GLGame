# Titan Of Air
Titan Of Air is a very-early-stage OpenGL cross-platform strategy game.
This game will allow players on windows, osx, and linux to roleplay as the CEO
of their very own multi-million dollar airline -- controlling how planes are ordered,
to  determining which services/ammenities are offered, fighting with other corporations
to become kind of the stock market, and much more!

## Project Status
The game is in its infancy at the moment. The OpenGL rendering pipeline is half-complete
(which is generous given the window doesn't stay open more than a single frame) and 
much of the core functionality is yet to be created. The current tasks being addressed
in current updates to this repository primarily focus around the app's core architecture
and the internal Entity-Component System (ECS) managed by the game's internal mechanics.


#### Roadmap
In the future, as the project progresses through the next few months, graphics will be 
laughably simple as texture/model art will only be acquired from professionals after
the mechanics of gameplay and internal design is constructed and refined.

Once a base game has been completed (possibly with bugs and simple graphics), this repository
will be removed and a public access steam alpha/beta process will begin to help refine
the game with assistance from players.

## Dependencies
To build this project, CMake is required. All source code for dependencies is included in 
the `lib` folder. This includes many common libraries like `GLAAD`, `GLFW`, `OPUS`,
and many `BOOST` libraries within the `lib/boost` folder. *Note that not all boost sources are 
linked to the final binary to reduce bloat while still providing source-code access
for flexibility should the project's needs change.*

## Collaboration
While outside help is encouraged, pull requests will likely only be accepted if they
fully comply with the style guidelines that I use within all the other code written.
While I cannot provide a full documentation over the expectations for this style,
many of the common constructs are repeated throughout existing code should you want
to contribute and style your code to match the rest of the project. I am welcome
to suggestions as well via discord. Reach out for more information.

#### Documentation
For those interested in contribution, documentation is critical. My style is to document
all public and protected members, leaving private members undocumented. Comments within
code segments should be rare: Code should speak for itself!