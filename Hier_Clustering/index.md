# Lab 9
## Hierarchical CLustering

Hierarchical clustering (agglomerative) is a method of cluster analysis which seeks to build a hierarchy of clusters. It is often used for data analysis in various fields such as biology, marketing, and social sciences.

### Steps:
1. Assign each data point to its own cluster.
2. Find the closest pair of clusters and merge them into a single cluster.
3. Repeat the above step until all points are in a single cluster.

The time complexity of agglomerative hierarchical clustering is \(O(n^3)\) due to the need to compute distances between clusters at each step.