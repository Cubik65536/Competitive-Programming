>  Note: This is the same problem as the Senior Problem 1, since there's no different (not even in how marks are distributed), this solution should work for both J4 and S1.

For this problem, the idea is simple: each wet tiles need 3 meter of tapes. And then, we can remove unnessary tapes.

The logic for removing the tapes is:

1. If there's any wet tiles at the left hand side of the current tile remove 1 from the number of the tape.
2. If there's any wet tiles at the right hand side of the current tile remove 1 from the number of the tape.
3. If there's any wet tiles below (for the 1st row) or at the top (for the 2nd row) of the current tile, and the column numbers is an odd number (or an even number when using an array so the first column is numbered 0), remove 1 from the number of the tape. The second requirement is needed because only these rows have a shared side with the other tile on the other row that should be removed.

With this idea in mind, all we have to do is to use an two dimensional array to store the status of each tile, and then iterate through the array and remove tapes with the logic mentioned above.