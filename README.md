# INTRODUCTION
```
This is an console application which can find the shortest path from a graph.
```

# MAKEFILE
```
to make the exe file called lem-in:
make

to recomplile all:
make re

to clean .o files:
make clean

to clean .o files and exe file:
make fclean
```

# HOW IT WORKS
```
write on the standard input the graph as:

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

the result of the command "./lem-in < file1" is:
L1-node1 L2-node2 L3-node3
L2-node1 L3-node1 L4-node1
L5-node1

Explanations:
we have 5 voyagers, the constraint is that we have only one place in each node.
the node start is node0 with coordinates x = 1  and y = 0.
the node end is node1 with coordinates x = 5 and y = 0.

the result format:
Each line corresponds to one turn where each voyager can move from a room to another room linked and free.

So for the example we can solve the problem in a minimum of 3 turns.

```
