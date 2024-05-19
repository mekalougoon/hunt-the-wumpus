FIT1048: Major Project Assignment 3
The Witch of Caverton Realm
Tameka Marin Lougoon 

EXTRA FUNCTIONALITY
- difficulty levels
- scoring system
- move witch (wumpus) after random number of turns
- implemented theme into story + feedback
- ascii art locations and hazards

THINGS TO NOTE
- hazard locations are displayed at the start when they are created, after entering name and difficulty. I have included a numbered map in the reflection document as this is required for the 'cheat' displayed locations.

- I made it so that even if you shoot an invalid direction, it is counted as an attack/weapon loss. 
  This is because while is isn't possible to go through an entrance/portal that doesn't exist (hence the fact that you get an 
  error message that states please choose a correct exit for turns, and the counter remains the same) it IS possible to just straight up miss an attack. 
  (Hence why I chose to increment the attack counter, even on a miss or 'invalid' direction.) I just wanted to point this out in case you thought that I hadn't been able to/didn't consider this fact;
  If I had wanted an incorrect attack not to count, I would have just done it the exact same way that I did the location/turns and the counter for that.

- Witch = Wumpus
  Quciksand = Bats (randomise location)
  Corrupted Crypt  = Bottomless Pits (kill player/end game)