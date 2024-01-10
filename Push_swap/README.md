## 42 - Push_swap

The essence of the project is to sort the integer stack by a limited set of instructions, using the smallest possible number of actions.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

## Usage
  ```
 make && ./push_swap 5 7 9 3 1565 71 
   ```
## Example

	$>./push_swap 2 1 3 6 5 8
	sa
	pb
	pb
	pb
	sa
	pa
	pa
	pa
