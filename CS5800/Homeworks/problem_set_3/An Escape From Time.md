Ulrich from 2019 travels to Winden 1953 to accomplish a secret mission. He travels using the popular Winden Caves. After he has finished his secret mission in Winden - 1953, he now has to return to the 2019. He can travel to 2019 using the caves. However, the cops of Winden know that Ulrich is on the loose, and are attempting to stop him by spreading his picture to the police at their bus stop.

You must help Ulrich escape Winden-1953 by determining which buses he should take to reach the caves. However, because the police are actively looking for him, Ulrich has decided that he cannot sit still at any one bus stop for too long. Thus you need to determine which busses he should take so that his layover is never too long.

**Details of traveling**
At the very start, Ulrich is at stop 1, at time 0. Suppose that Jim arrives at stop $x$ at time $t$. Then he can move to stop $y$ if and only if:

There is a bus going from $x$ to $y$ at time $t1$, where $t1 \geq t$, but $t1 - t \leq T$, the max time he can spend at the stop.

If there is such a bus ride, labeled as $x, y, t1, t2$, then after taking this bus, he will be at stop $y$ at time $t2$.

**Input Format**

Line 1: $N\ M\ T$
$10 \leq N \leq 200000$
$50 \leq M \leq 500000$
$1 \leq T \leq 100$

- $N$ is the label of the destination bus stop (1 is the starting point, $N$ is the destination outside the country). Ulrich always starts at stop 1 at time 0.
- $M$ is the number of bus rides which appear on the schedule.

- $T$ is the max time Ulrich can spend at any one stop without being caught by the cops of Winden. Note that he is allowed to spend exactly $T$ time steps at a stop, but not a moment more.

Next $M$ Lines: $x\ y\ t_1\ t_2$

$1 \leq x, y \leq 200000$
$0 \leq t_1 \leq t_2 \leq 5000000$

- $x$ is the stop label where a bus will be leaving from
- $y$ is the stop label where this bus will arrive
- $t_1$ is the time the bus will leave stop $x$
- $t_2$ is the time the bus will arrive at stop $y$

**Constraints**

$10 \leq N \leq 200000$
$50 \leq M \leq 500000$
$1 \leq T \leq 100$

$1 \leq x, y \leq 200000$
$0 \leq t_1 \leq t_2 \leq 5000000$

**Output Format**

"NO" if, no matter what busses Ulrich takes, he will not be able to reach stop N without being caught.

"YES $T_{min}$" if he can escape , where $T_{min}$ is the time that he arrives at stop $N$. If there are multiple such paths, you should find the one with smallest possible $T_{min}$.

**Sample Input**

4 5 20
1 2 15 20
1 3 1 6
2 4 25 30
3 4 2 7
3 4 30 35

**Sample Output**

YES 30

**Explanation**

Ulrich could take the following busses:

- Stop 1 to Stop 2, leaves at 15, arrives at 20
- Stop 2 to Stop 4, leaves at 25, arrives at 30

The only other bus that arrives earlier at stop 4 leaves stop 3 at time 2, but it is not possible to get to stop 3 before time 2.
