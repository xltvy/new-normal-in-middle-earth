# new-normal-in-middle-east

Bogazici University

Computer Engineering Department

Fall 2020

CMPE 250 - Data Structures and Algorithms

Project 1

Altay Acar

***

A simulation based simple war game set in the world of Lord of the Rings.

War Rules:
- Middle-Earth hosts five different character types: Hobbits, Men, Elves, Dwarfs, and Wizards. Each community contains exactly one of these characters; 5 characters in total.
- Only two communities involve in a war and they attack each other in rounds. The attack is performed by a character of the attacking community towards a character in the defending community. For instance, in round 1, the Wizard of community 1 can attack the Dwarf of community 2 and in round 2 the Men of community 2 can attack the Hobbit of community 1. As a convention, community 1 attacks first.
- Each character has predefined attack and defense points. The damage of an attack is computed by subtracting the defense point of the defender from the attack point of the attacker. If the damage is larger than 0, the health of the defender decreases by that amount. When the health of a character drops to 0 or below, the character is dead. As an edge case, negative health scores are considered as 0.
- If a dead character tries to attack or defend, it is replaced by the name-wise alphabetically next alive character in its community. If there is no alphabetically next alive character, then it is replaced by the alphabetically previous alive character.
- Hobbit is the most important character type. If the hobbit of a community dies, the community loses the war. In addition, if all other community members die, Hobbit becomes defenseless and the war is lost again.
- The maximum number of rounds a war can last is predefined. If none of the end conditions is met when the round limit is reached, the war ends in a draw.
- Some characters have special skills that they might use per certain number of rounds.
  > Elves can convey half of their health (integer division) to the hobbit of its community per 10 rounds. In other words, at least 10 rounds must pass for an Elf to trigger its special skill, since the beginning of the war and the last use of the skill. After using the special skill, Elves can still attack the defender.
  > Dwarfs can call another dwarf with its own attributes and they attack defender together. This doubles the damage on the opponent for this round and then the callee disappears. Dwarfs can trigger this skill per 20 rounds.
  > Wizards can turn the last killed community member back to life with the initial health of the killed member, per 50 rounds. After the resurrection, the wizard still attacks the defender. If all members of the community are alive, the special skill is not triggered at all, so that the wizard would not have to wait for 50 rounds.

Files:
- Character.h and Character.cpp for creating characters.
  > This class consists of the attributes of characters, constructors, operator overloaders, and de- structor.
- main.cpp for I/O operations and simulating the war.

Testing:
- Code will be run with the following command to the CLI:
  > g++ main.cpp Character.h Character.cpp -std=c++11 -o project1.out
  > ./project1.out inputFile outputFile

Input:
- All input files have the following format:
- The first line states the maximum number of rounds this war can last and the next 5 lines list the characters of the first community. Each of these lines comprise two strings and three integers to denote the character name, type, attack point, defense point, and initial health, respectively. The next 5 lines contain the same information for community-2, in the same format. The community descriptions are followed by maximum number of rounds lines. Each of these following lines specifies the attacking move in the corresponding round by three strings: name of the attacker, name of the defender, whether the attacker triggers the special skill or not. Note that the attacker cannot trigger a special skill arbitrarily, even if it tries to do so: a number of necessary rounds must pass to reload the skill and the character must have a special skill in the first place!
- Below is an example:
  > max number of rounds
  > community1 char1 name type attack defense health
  > community1 char2 name type attack defense health
  > community1 char3 name type attack defense health
  > community1 char4 name type attack defense health
  > community1 char5 name type attack defense health
  > community2 char1 name type attack defense health
  > community2 char2 name type attack defense health
  > community2 char3 name type attack defense health
  > community2 char4 name type attack defense health
  > community2 char5 name type attack defense health
  > attacker name defender name attacker name defender name if special attacker name defender name if special
  > attacker name defender name if special

Output:
- The output file must consist of 13 lines. The first line must state the winner: Community-1, Community-2, or Draw.
- Each of the second and third lines must contain one integer to denote the number of rounds passed and total number of casualties, respectively.
- The remaining 10 lines must have the same format. They must contain the health record of each character in the order they were presented. Each line must start with the name of the character and must be followed by a space-separated list of integers. Keep in mind that the size of the health records is equal to the number of rounds the war lasted plus 1.
- Below is an example:
  > attacker name defender name if special
  > attacker name defender name if special
  > attacker name defender name if special
  > attacker name defender name if special
  > attacker name defender name if special
  > ...
