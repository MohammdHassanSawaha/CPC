#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<ll> st;
// order_of_key (k) : Number of items strictly smaller than k .
// fl_by_order(k) : K-th element in a set (counting from zero).
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_setl;
typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_setg;
