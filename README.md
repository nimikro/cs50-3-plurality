# cs50-3-plurality - Summary
This is a command line application developed in C# that runs a plurality election. This is an exercise for Harvard's CS50 online course.

# Table of contents
1. [Plurality](#Plurality)
2. [Background](#Background)
3. [Understanding](#Understanding)
4. [Specification](#Specification)
5. [Usage](#Usage)


# Plurality
The program runs a plurality election, per the below.
```
$ ./plurality Alice Bob Charlie
Number of voters: 4
Vote: Alice
Vote: Bob
Vote: Charlie
Vote: Alice
Alice
```

# Background
Elections come in all shapes and sizes. In the UK, the Prime Minister is officially appointed by the monarch, who generally chooses the leader of the political party that wins the most seats in the House of Commons. The United States uses a multi-step Electoral College process where citizens vote on how each state should allocate Electors who then elect the President.

Perhaps the simplest way to hold an election, though, is via a method commonly known as the “plurality vote” (also known as “first-past-the-post” or “winner take all”). In the plurality vote, every voter gets to vote for one candidate. At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

# Understanding
The line #define MAX 9 is some syntax used here to mean that MAX is a constant (equal to 9) that can be used throughout the program. Here, it represents the maximum number of candidates an election can have.

The file then defines a struct called a candidate. Each candidate has two fields: a string called name representing the candidate’s name, and an int called votes representing the number of votes the candidate has. Next, the file defines a global array of candidates, where each element is itself a candidate.

Now, take a look at the main function itself. The program sets a global variable candidate_count representing the number of candidates in the election, copies command-line arguments into the array candidates, and asks the user to type in the number of voters. Then, the program lets every voter type in a vote, calling the vote function on each candidate voted for. Finally, main makes a call to the print_winner function to print out the winner (or winners) of the election.

# Specification
Completed the implementation of plurality.c in such a way that the program simulates a plurality vote election.

* Completed the vote function.
  * `vote` takes a single argument, a string called `name`, representing the name of the candidate who was voted for.
  * If `name` matches one of the names of the candidates in the election, then it updates that candidate’s vote total to account for the new vote. The `vote` function in this case returns true to indicate a successful ballot.
  * If `name` does not match the name of any of the candidates in the election, no vote totals change, and the `vote` function returns false to indicate an invalid ballot.
  * We assume that no two candidates will have the same name.
* Completed the `print_winner` function.
  * The function prints out the name of the candidate who received the most votes in the election, and then prints a newline.
  * It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, the program outputs the names of each of the winning candidates, each on a separate line.

# Usage
The program should behave per the examples below.
```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```
```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice
```
```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```
