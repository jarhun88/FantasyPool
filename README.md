# FantasyPool
A quick Fantasy team setup Program

The FantasyPool algorithm is designed to save time as it does the player and fantasy game setup, randomly chooses the 
order of player draft selection, and once the players submit their draft selection, the algorithm will "lock" player's 
successful drafts and if a draft had previously been picked by another player, will delete that draft pick and move onto the 
next draft choice. The player is then notified to choose another draft pick in order to make up for the deleted pick. 
Finally, all player drafts are revealed, at which point they can enter them into a fantasy league website, enjoy!

This program uses a custom linked list with head and tail pointers in order to store player draft pick data.
The Stdlib unordered_map is utilized in order to maintain which draft picks have already been "locked" as to prevent the same
player from being drafted into multiple teams. 
