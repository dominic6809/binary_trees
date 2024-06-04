# 0x1D. C - Binary trees

# Binary Trees in C

## Overview

This project explores the concept and implementation of binary trees in the C programming language. A binary tree is a hierarchical data structure consisting of nodes, where each node has at most two children, referred to as the left child and the right child. Binary trees are widely used in computer science for various applications, including data storage, searching, and sorting.

## Description

The project covers various aspects of binary trees, including their creation, manipulation, traversal, and analysis. Below is an overview of key concepts and functionalities:

### Binary Tree Node

A binary tree node is the basic building block of a binary tree. It contains a value and pointers to its left and right children (or NULL if no child exists). The project includes functions to create new binary tree nodes and perform basic operations on them.

### Binary Tree Traversal

Traversal refers to visiting and processing each node in the binary tree in a specific order. Three common methods of traversal are:
- Pre-order traversal: Visit the current node, then recursively traverse the left and right subtrees.
- In-order traversal: Recursively traverse the left subtree, visit the current node, then recursively traverse the right subtree. In a binary search tree, this traversal visits nodes in sorted order.
- Post-order traversal: Recursively traverse the left and right subtrees, then visit the current node.

The project includes functions to perform each type of traversal.

### Binary Search Trees (BST)

A binary search tree is a type of binary tree where the value of each node is greater than all values in its left subtree and less than all values in its right subtree. BSTs are commonly used for efficient searching and insertion operations. The project includes functions to insert, search, and delete nodes in a binary search tree.

### AVL Trees

AVL trees are self-balancing binary search trees where the heights of the two child subtrees of any node differ by at most one. This balancing property ensures that the tree remains approximately balanced, leading to efficient search, insertion, and deletion operations. The project includes functions to maintain AVL tree properties, such as rotations and balancing.

### Heap Trees

Heap trees are specialized binary trees that satisfy the heap property. In a max heap, the value of each node is greater than or equal to the values of its children. In a min heap, the value of each node is less than or equal to the values of its children. Heaps are commonly used for implementing priority queues. The project includes functions to insert, extract, and convert heap trees.

## Compilation and Usage

To compile the project, use the provided Makefile:

```bash
make
```

## Author
This project was implemented by [Musyoki Dominic].


