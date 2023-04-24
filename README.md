<h1 align="center">📖 PHILOSOPHERS</h1>
	

Think about Thinking how to Think when you Think that you don't Think how to Think about Thinking better to become a better Thinker, oh well fork() it.

<img src="https://cdn3.emoji.gg/emojis/5590-pepethink.png" width="350px" alt="pepethink">

# The Dining Philosopher Problem

Five philosophers dine together at the same table. Each philosopher has their own place at the table. There is a fork between each plate.
The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat.
Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork.
Thus two forks will only be available when their two nearest neighbors are thinking, not eating.
After an individual philosopher finishes eating, they will put down both forks.
The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve.
i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think

<img src="https://github.com/zstenger93/philosophers/blob/master/philosophers.png" alt="philosophers">

# Threads

Philo threads shouldn't communiate with each other.
I have 2 extra thread to monitor death and philo's being full

# Routine

## Eat
1 Philosopher -> init_death_sentece();

else

grab forks

print eating

update last time eaten

update meal counter

drop the forks

## Sleep
Sleep
## Think
Think if it has to until the next meal.

# Monitor death
If we find a philosopher dead, set the flag for the loop false to stop eating
and print the message of death.

# Monitor full philosophers
If all the philosophers had meals equal to the number_of_meals then break and finish the program.

# Mutex lock
If you are using multiple thing in one lock and let's say one of them is used in
a different lock somewhere else, then you need to use that lock within the lock
ass well in order to not to have data races.

