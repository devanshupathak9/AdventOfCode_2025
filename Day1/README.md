## Day 1: Secret Entrance 

The Elves have good news and bad news.

### Good News
The Elves have discovered project management! This has equipped them with tools to prevent their usual Christmas emergency. For instance, they now know that the North Pole decorations need to be completed soon to ensure other critical tasks can start on time.

### Bad News
The Elves have realized they face a new emergency: their resource planning shows no time left to decorate the North Pole!

To save Christmas, you must finish decorating the North Pole by **December 12th**.

### How It Works
Collect stars by solving puzzles. Two puzzles will be available each day; the second puzzle unlocks after completing the first. Each puzzle grants one star. Good luck!

---

### The Challenge
You arrive at the secret entrance to the North Pole base, ready to start decorating. However, the password has been changed, and you can't get in. A document taped to the wall explains:

> "Due to new security protocols, the password is locked in the safe below. Please see the attached document for the new combination."

The safe has a dial with numbers **0 through 99** in order and an arrow. As you turn the dial, it clicks at each number.

The attached document (your puzzle input) contains a sequence of rotations, one per line, to open the safe. Each rotation starts with:
- **L** or **R**: Direction to turn the dial (Left or Right).
- A distance value: Number of clicks to rotate in that direction.

#### Example
If the dial starts at **11**:
- A rotation of `R8` moves the dial to **19**.
- A rotation of `L19` moves it to **0**.

Since the dial is circular:
- Turning left from **0** one click points to **99**.
- Turning right from **99** one click points to **0**.

If the dial starts at **5**:
- A rotation of `L10` moves it to **95**.
- A rotation of `R5` moves it to **0**.

The dial starts at **50**.

---

### The Decoy Safe
Your North Pole security training revealed the safe is a decoy. The actual password is the number of times the dial points to **0** after any rotation in the sequence.

#### Example Input
Suppose the attached document contains the following rotations:
```
L68
L30
R48
L5
R60
L55
L1
L99
R14
L82
```

#### Example Process
1. Dial starts at **50**.
2. Rotate `L68` → **82**.
3. Rotate `L30` → **52**.
4. Rotate `R48` → **0**.
5. Rotate `L5` → **95**.
6. Rotate `R60` → **55**.
7. Rotate `L55` → **0**.
8. Rotate `L1` → **99**.
9. Rotate `L99` → **0**.
10. Rotate `R14` → **14**.
11. Rotate `L82` → **32**.

The dial points to **0** a total of **3 times**. Thus, the password is **3**.

---

### Your Task
Analyze the rotations in your attached document(data.txt). What is the actual password to open the door?