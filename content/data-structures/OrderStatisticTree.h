/**
 * Author: me
 * Date: 2024-09-16
 * License: CC0
 * Source: https://github.com/hoke-t/tamu-kactl/blob/master/content/data-structures/OrderStatisticTree.h
 * Description: A set (not multiset!) with support for finding the n'th
 * element, and finding the index of an element.
 * To get a map, change \texttt{null\_type}.
 * Time: O(\log N)
 */

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

// find_by_order(x): return iterator to k-th largest element(count from 0)
// order_of_key(x): number of element strictly less than x

typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update
> ost;
