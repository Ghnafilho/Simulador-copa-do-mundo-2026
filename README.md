# World Cup Simulator (Beta Version)

This project is a text-based World Cup tournament simulator developed in the C programming language. It is currently in its initial testing phase. The program allows users to simulate the entire competition by inputting match scores, calculating group standings, and determining which teams advance through the knockout brackets all the way to the grand final.

---

## Tournament Structure
The simulation strictly follows the chronological phases of the tournament:

*   **European Play-offs:** Decides the final UEFA qualification slots.
*   **Intercontinental Play-offs:** Determines the last remaining global slots for the tournament.
*   **Group Stage:** Round-robin format where teams play against each other within their assigned groups to secure points.
*   **Pre-Round of 16:** Preliminary knockout phase for specific qualifying teams.
*   **Round of 16:** Single-elimination matches for the top 16 teams.
*   **Quarter-finals:** The remaining 8 teams clash.
*   **Semi-finals:** The final 4 teams compete for a spot in the championship.
*   **Final:** The deciding match to crown the World Cup Champion.

---

## How to Run
To avoid local environment configuration issues and ensure a smooth execution, we highly recommend running this code using **GitHub Codespaces**.

### Execution via Codespaces
1.  Open a new, blank workspace in GitHub Codespaces.
2.  Create a new file named `copa.c` and paste the simulator's source code into it.
3.  Install the recommended C/C++ extensions when prompted by the editor.
4.  **Compilation & Execution:** 
    *   You can click the standard "Run" button in the top right corner of the interface.
    *   Alternatively, open the integrated terminal to compile the code manually (`gcc copa.c -o copa`) and then execute it (`./copa`).

---

## Important Notes & Warnings

> **Score Input Attention:** Please be extremely careful when entering match results. The current version lacks robust input validation. If you mistype a score, the system will save the incorrect value, which will permanently affect the tournament bracket and advancing teams.

> **Work in Progress:** As this software is in an early testing phase, unexpected bugs, logic errors, or crashes may occur during the simulation. 

---

## Contact & Support
If you encounter any bugs, have technical questions, or want to suggest improvements, feel free to reach out:

*   **GitHub:** Open an *Issue* directly in this repository detailing the steps to reproduce the bug.
*   **Instagram:** Send a direct message to [@ghnafilho](https://instagram.com/ghnafilho).
