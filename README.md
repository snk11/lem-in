# INTRODUCTION
```
It's an console application which the goal is to obatin the shortest and fastest path from graph.
```

# MAKEFILE
```
to make the exe file called lem-in:
make

to re:
make re

to clean .o files:
make clean

to clean .o files and exe file:
make fclean
```

# HOW IT WORKS
```
put a file in argument.

for example in a file called "file1":
5
##start
node0 1 0
##end
node1 5 0
node2 9 0
node3 13 0
node0-node2
node2-node1
node0-node3
node3-node2
node1-node0

the result of the command "./lem-on < file1" is:
L1-node1 L2-node2 L3-node3
L2-node1 L3-node1 L4-node1
L5-node1

Explanation:
we have 5 voyagers, the constain is that we have only one place in each node.
the node start is node0 with coordinates x = 1  and y = 0.
the node end is node1 with coordinates x = 5 and y = 0.

the result format:
Each line corresponds to one turn where each voyager can move from a room to another room linked and free.

So the for the example we can solve the problem in a minimum of 3 turn.

```