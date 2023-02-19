For this problem, we can solve the entire set of questions by solving each subtasks individually.

First, we have to handle the input. We need a variable *N* to store our number of person, and since we already know that there's 5 days in the schedule, we can use an array of length 5 to store how many people can attend to the event at *x + 1* day.

For the first subtask, "there will be exactly one day on which every person will be able to attend", we can just iterate through the array and print the index of array when the couter equals to *N*.

For the second subtask, "there will be exactly one day on which the largest number of people will be able to attend". So, we need two new variables. An integer *max* for the largest number of people, and another integer *day* for tracking down which day is the day. And then we can iterate the schedule, find the day with maximum number of people, and print the *day* as our result. This code will also work with the first subtack as the day where day on which every person will be able to attend is the day which the largest number of people will be able to attend.

For the third subtask, "there might be more than one day on which the largest number of people will be able to attend". So we will have to replace our interger *day* with an dynamic array (`vector` in C++, `ArrayList` in Java, etc.) *days* who tracks all the days on which the largest number of people will be able to attend. And we can iterate the schedule, and get into one of the following situations:

1. There's more people than what we stored in *max*, so we can clear the array *days*, and put the new date in.
2. There's as much people as what we stored in *max*, so we add this date to our array *days*.
3. There's less people than  what we stored in *max*, so we can just ignore that day.

At the end, we can print out all the values in the array *days*.