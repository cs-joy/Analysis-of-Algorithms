## Comparison Sort Algoritm

A comparison sort is a type of sorting algorithm that only reads the list elements through a single abstract comparison operation (often a "less than or equal to" operator or a three-way comparison) that determines which of two elements should occur first in the final sorted list. The only requirement is that the operator forms a total preorder over the data, with:

- if a ≤ b and b ≤ c then a ≤ c (transitivity)
- for all a and b, a ≤ b or b ≤ a (connexity).
It is possible that both a ≤ b and b ≤ a; in this case either may come first in the sorted list. In a stable sort, the input order determines the sorted order in this case.

A metaphor for thinking about comparison sorts is that someone has a set of unlabelled weights and a balance scale. Their goal is to line up the weights in order by their weight without any information except that obtained by placing two weights on the scale and seeing which one is heavier (or if they weigh the same).


read more to visit [wikipedia](https://en.wikipedia.org/wiki/Comparison_sort)