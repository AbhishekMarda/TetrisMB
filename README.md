# TetrisMB

Welcome to TetrisMB! This is a command line based graphical tetris game.

### Installation

#### macOS / Xcode
1. Clone the repository and open in Xcode. 
1. Press `cmd + B` or build the files.
1. Open terminal
1. Drag and drop the build executable file from the file inspector on the left onto the terminal and remove "Tetris" from the end
1. Press enter to go into this directory
1. Type `./Tetris`, press enter, and follow the directions

#### Other
1. Copy files from the "Tetris" folder located in the root folder
1. Make an executable file
1. Run it and follow the instructions

### Notes
This implementation allows the user to modify the game experience based on their preferences.

1. In `globals.h` change the constant beside `TRUE_RANDOM_SIZE_4_DISTRIBUTION` to `0` to enable our random block generator. Keep in mind that this does not allow for a truly random distribution between difference block appearances. However, this does allow for a variable block size to be generated.
1. In `globals.h` change `MAX_ROWS` and `MAX_SIZE` to increase or decrease the grid size based on your preference. Note that any margin beneath 10 may result in unexpected behavior.
1. In `globals.h` change `BLOCK_SIZE` to the block size you would like to play with. By default, it is set to 4. Ensure that `TRUE_RANDOM_SIZE_4_DISTRIBUTION` is `0` before you play the game with a modified block size.

