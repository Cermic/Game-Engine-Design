# Game-Engine-Design

A game engine that supports a text based game. This was created as a demonstration of use of multiple design patterns be implemented into a single project but working independently of each other. Includes the State pattern, Factory pattern, basic Facade pattern, Decorator pattern and Observer pattern.

This project was written with C++ and can be compiled with CMake and any relevant compiler.

## Brief Description of Patterns Used / Design
For our design we opted for using the State Pattern, the Factory Pattern, the Decorator Pattern, the Observer Pattern and the Façade Pattern. 
We believed that these would work well together because the State Pattern allows close control over the game. This being used in tandem with the Observer Pattern allows the game to function without the Subject having access to any of the code that runs the game itself as the Observer is notified when a state change happens and triggers the appropriate code.
The Factory and Decorator Patterns work well because we desired a combination and variety of different planets and NPCs. These Patterns also work independently from the rest of the game and so allow expansion and changes to the game without any changes being needed to these patterns.
We used the Façade pattern to hide the Factory from the rest of the classes so that it could act with complete independence from the rest of the program.

- The State pattern is used to control the flow of the game, handle game events and thus the player.
- The Factory pattern is used to create a very flexible generation system for creating enemies and NPCs. It allows for multiple variants to be created without the need for additional code and keep code separated.
- The Façade pattern is used to create an interface for the player and to keep the player states from being the primary game controller which is not their intention.
- The Decorator pattern is used to generate different types of planets without the need for extra code and to simulate a degree of random generation within the game.
- The Observer pattern updates the status of the player and indicates to the game when to change state.

## Future Potential Changes
In future I would propose the following changes:

-	The player should have a proper weapon that can change if they find a new one, it is damaged or a new one is bought from the shop. It is intended that the weapon supplier would take on this functionality.
-	The player should have a working inventory that can store their items along with their weapon, equipment and any other items that they would need. 
-	There should be an in game economy where items would devalue if you sold too many of the same thing to an NPC.
-	The menu could be changed to give more of the functionality back to the State pattern. This would allow more flexibility when adding more states to the game.
-	We would like to add in the player’s movement being affected depending on the planet type. For example, the player will move slower in a tropical environment than in an arid one. This creates additional factors for the player to consider when visiting a planet. The slower the movement speed, the more resources the player will use up when moving around.  
-	We would like the player to be able to find random loot on exploration.