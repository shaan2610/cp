#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
      template<
      typename Key, // Key type
      typename Mapped, // Mapped-policy
      typename Cmp_Fn = std::less<Key>, // Key comparison functor
      typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
      template<
      typename Const_Node_Iterator,
      typename Node_Iterator,
      typename Cmp_Fn_,
      typename Allocator_>
      class Node_Update = null_node_update, // A policy for updating node invariants
      typename Allocator = std::allocator<char> > // An allocator type
      class tree;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5