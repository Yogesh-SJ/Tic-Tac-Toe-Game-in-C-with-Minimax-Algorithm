# 🎮 Tic-Tac-Toe Game in C with Minimax Algorithm  

## 📌 Overview  
This is a **Tic-Tac-Toe** game implemented in **C**, featuring an **AI opponent powered by the Minimax Algorithm**.  
The AI plays optimally, making it **impossible to defeat**—you can either **tie** or **lose** if you make a mistake.  

## 🎮 How It Works  
- The game runs in the **terminal**.  
- You play as **'X'**, while the AI plays as **'O'**.  
- The game prompts you to enter the row and column (1-3) where you want to place your mark.  
- After each player’s move, the AI makes its optimal move using the **Minimax Algorithm**.  
- The game continues until a player **wins** or the grid is **full** (resulting in a **tie**).  

## 🏆 Game Rules  
1. The game is played on a **3x3 grid**.  
2. Players take turns placing their marks (**'X'** for the player, **'O'** for the AI).  
3. The first player to get **three in a row** (vertically, horizontally, or diagonally) wins.  
4. If all 9 squares are filled and no one has three in a row, the game ends in a **tie**.  

## 🔥 Features  
✅ **AI powered by Minimax Algorithm**  
✅ **Unbeatable AI**—you can only win if you modify the code to weaken it  
✅ **Command-line interface** for easy interaction  
✅ **Play again option** after each match  

## 🛠️ Installation & Compilation  
To compile and run the program on **Linux** or **Windows (with GCC)**:  

```sh
gcc tic_tac_toe.c -o tic_tac_toe

🖥️ Example Gameplay

./tic_tac_toe
 1 | 2 | 3
---|---|---
 4 | 5 | 6
---|---|---
 7 | 8 | 9

Enter row (1-3): 1  
Enter column (1-3): 1  

 X |   |   
---|---|---
   | O |   
---|---|---
   |   |   

(continues until game ends)
```

## 🤖 AI Strategy (Minimax Algorithm)
- The Minimax Algorithm evaluates all possible moves and selects the best one.
- If the AI can win immediately, it does so.
- If the AI can't win immediately, it blocks the opponent’s winning move.
- If neither player can win immediately, it picks the best possible move to force a tie at worst.
