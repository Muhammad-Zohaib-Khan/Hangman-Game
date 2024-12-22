**Hangman Game with Visual Representation**
Developed using Object-Oriented Programming in C++

This project is a fully functional Hangman Game that incorporates visual feedback and an engaging user experience. The game is centered around guessing fruit names, offering a fun and interactive way to challenge the player's vocabulary and memory.

**Key Features:**

Random Word Selection: The game selects a random fruit name from a predefined list, ensuring that each playthrough provides a unique challenge. The word is chosen using the rand() function, and the game is seeded with the current time for added randomness.
Interactive User Experience: Players input single-letter guesses, with immediate feedback provided for correct, incorrect, and previously guessed letters. The game ensures valid input by prompting the player to enter only alphabetic characters.
Visual Hangman Representation: The game includes dynamic ASCII art, which progressively depicts the hangman figure as incorrect guesses are made. This adds a layer of excitement and tension to the game as players see the consequences of their mistakes.

Game Flow and Logic:
The game tracks the player’s remaining attempts, displays the current state of the word (with guessed letters revealed), and maintains a list of all guessed letters.
The player wins by correctly guessing the word before running out of attempts, or loses if they exceed the maximum number of wrong guesses.
The game ends with either a win message displaying the correctly guessed word or a loss message revealing the correct word.
Robust Error Handling:
The program includes error handling to ensure players can only input valid letters. It prevents repeated guesses and provides clear messages for invalid or already guessed letters.

**Technical Details:**
Programming Language: C++
Core Concepts:
Object-Oriented Design: The game logic is encapsulated within a HangmanGame class, which manages the game state and interactions.
Dynamic Memory Management: The game utilizes dynamic memory allocation for storing words and guessed letters, demonstrating a strong grasp of memory management in C++.
String Manipulation: Utilizes C++ standard libraries like cstring to manipulate strings, handle word comparisons, and manage game state.

This project showcases my ability to design and implement interactive applications in C++ using object-oriented principles. It highlights my skills in memory management, input validation, and program flow control, while also providing a fun, user-centered experience. Through this project, I deepened my understanding of C++ core concepts and improved my ability to create engaging, functional software applications.
