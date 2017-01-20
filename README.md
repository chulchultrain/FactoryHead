# FactoryHead
Increase Win Rate in Pokemon Platinum Battle Factory. 

#For Who
This project is for players of the Pokemon Platinum(and HeartGold/SoulSilver) Battle Factory.

#More on what it does
Given what we know about the opposing Pokemon, we can draw ourselves a more complete picture about that Pokemon.
The Battle Factory has a set Pokemon Entry List that the Factory Trainers get their Pokemon from.

That list can be found at http://www.psypokes.com/platinum/frontier_pokemon.php. 

Now, given the little information and few hints that the guy that allows you to trade a Pokemon between matches gives you, 
we can map that information to the Pokemon in that list that are consistent with that information. That is what my project does.

You feed it a little information, and it will retrieve the list of Pokemon consistent with that information.

#Requirements
GCC 4.6.3

#How to Use
First, compile with command make EntryFilterTester
Then, create your criteria file with the requirements below:
file name:"inputfile.txt"
file format: 
Three tags(each on separate lines):

Name:

Type:

Moves:

Then below each tag you should have that information in a line.
If you have more than one move or one type known, then put them on separate lines.

e.g.:

Name:

Type:

Fire

Flying

Moves:

Flamethrower

Should be no trailing or leading whitespaces in any of the lines.

#Tested on:
Ubuntu 12.04 32-bit machine with GCC 4.6.3

#Other helpful resources
Now, species and movesets do not give us the full picture. However, I have found a site that calculates damage done
between two entries. That site is http://pokemonshowdown.com/damagecalc/

#Future Projects
That damage calculator site does not have everything to fully simulate a battle.(It does not account for stat changes due to things like swords dance, and effectively is only one turn deep. This gives motivation to create a Battle Simulator that accounts for all these things and can fully simulate and follow a battle N turns deep.

#Problems
I have recently found out that the PsyPokes Pokemon Entry List is not 100% accurate with respect to EVs(every other aspect
of data is accurate). Also, this list does not include Pokemon abilities(e.g. Synchronize, Sand Veil).

#Potential Fixes
As I play through Battle Factory and use this and the damage calculator site, I will calculate any mistakes in EVs and record
Pokemon abilities in the Entry List in this repo.

