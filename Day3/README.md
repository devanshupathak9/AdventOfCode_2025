## Day 3: Lobby

### Part 1
You descend a short staircase, enter the surprisingly vast lobby, and are quickly cleared by the security checkpoint. When you get to the main elevators, however, you discover that each one has a red light above it: they're all offline.

"Sorry about that," an Elf apologizes as she tinkers with a nearby control panel. "Some kind of electrical surge seems to have fried them. I'll try to get them online soon."

You explain your need to get further underground. 

"Well, you could at least take the escalator down to the printing department, not that you'd get much further than that without the elevators working. That is, you could if the escalator weren't also offline."

"But, don't worry! It's not fried; it just needs power. Maybe you can get it running while I keep working on the elevators."

There are batteries nearby that can supply emergency power to the escalator for just such an occasion. The batteries are each labeled with their joltage rating, a value from 1 to 9. You make a note of their joltage ratings (your puzzle input). For example:

```
987654321111111
811111111111119
234234234234278
818181911112111
```

The batteries are arranged into banks; each line of digits in your input corresponds to a single bank of batteries. Within each bank, you need to turn on exactly two batteries; the joltage that the bank produces is equal to the number formed by the digits on the batteries you've turned on. For example, if you have a bank like `12345` and you turn on batteries 2 and 4, the bank would produce `24` jolts. (You cannot rearrange batteries.)

You'll need to find the largest possible joltage each bank can produce. In the above example:

- In `987654321111111`, you can make the largest joltage possible, `98`, by turning on the first two batteries.
- In `811111111111119`, you can make the largest joltage possible by turning on the batteries labeled `8` and `9`, producing `89` jolts.
- In `234234234234278`, you can make `78` by turning on the last two batteries (marked `7` and `8`).
- In `818181911112111`, the largest joltage you can produce is `92`.

The total output joltage is the sum of the maximum joltage from each bank, so in this example:

```
98 + 89 + 78 + 92 = 357
```

There are many batteries in front of you (data.txt). **Find the maximum joltage possible from each bank; what is the total output joltage?**

### Part 2

#### The Challenge

The escalator remains stationary. The Elf explains that it likely requires more joltage to overcome the static friction of the system. She presses the big red "joltage limit safety override" button, repeatedly confirming "yes, I'm sure" while you wait and decorate the lobby.

Your task now is to generate the largest joltage by activating exactly **twelve batteries** within each bank.

#### Rules

- The joltage output for the bank is the number formed by the digits of the twelve batteries you activate.
- You must select exactly twelve batteries from each bank to maximize the joltage.

#### Example

Given the same input as before:

```
987654321111111
811111111111119
234234234234278
818181911112111
```

The largest joltages for each bank are:

- From `987654321111111`, activate all digits except some `1`s at the end to produce `987654321111`.
- From `811111111111119`, activate all digits except some `1`s to produce `811111111119`.
- From `234234234234278`, activate all digits except a `2`, a `3`, and another `2` near the start to produce `434234234278`.
- From `818181911112111`, activate all digits except some `1`s near the front to produce `888911112111`.

#### Total Output Joltage

The total output joltage is the sum of the largest joltages from each bank:

```
987654321111 + 811111111119 + 434234234278 + 888911112111 = 3121910778619
```

**What is the new total output joltage?(data.txt)**
