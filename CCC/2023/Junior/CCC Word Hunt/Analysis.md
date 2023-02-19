For this problem, because *R* and *C* aren't very large numbers ($\le 100$), we can "brute force" the solution.

If we ignore the fact of "turning" the segment, this problem is not very complicated: we'll pick each cell as the start finding the word by appointing the direction.

For horizontal search, we can keep the row number the same and search by add or remove 1 from the column number. And this is also the basic idea for vertical search.

For diagonal search, the idea was still the same, but there's should be two directions: one for horizontal and another for vertical.

In each search function, what we have to do first is check if we are going out of the table, if it is, we can just `return`. And then we can check if current character is the character that we need. If it is not, then we don't need to continue, if it is, we can continue to search with the same direction till we find the word we need.

And when we want to start the search, all we have to do is to call the search functions and indicate the direction. So we'll have to call horizontal and vertical search twice each for both directions. And we have to call diagonal search four times so we can search in for directions (`-1, -1`, `-1, 1`, `1, -1`, `1, 1`).

If we count the fact that we can have a 90 degree angles for our segments, this will become a little bit more complicated. But all we have to do is to make some minor changes to our search functions. First of all, we add a `turned` parameter to our search function. This parameter indicates if we already changed the direction. And what we have to do is, when there's no turn before (and there's more than one steps done to avoid double counting), we try to find the word on, in addition of keeping the same direction, the two other directions (after we make the "90 degree turn"). And the logic is, if we are finding horizontally, then having a 90 degress is basically continue the search vertically on both directions. And it is also the same principal for vertical search. And for diagonal search, which is always our special case, the two ways of turning a 90 degress is to change one of the two directions to it's [additive inverse](https://en.wikipedia.org/wiki/Additive_inverse).