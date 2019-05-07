# E599 Lab3 
### ***Please see the [PDF file](../master/EE599_Lab3_v1.pdf) for the more detailed problem descriptions. Remember to check back on Blackboard periodically for any updates.***
**Assigned: Wednesday Jan. 23**

**Due: Wednesday Jan. 30 at 11:59pm**


**What You Will Practice**

In this lab, you are going to practice OOP, multidimensional array manipulation and sorting **in C++**.

**Problem Description -  &quot;3D Burnt Pancake Sorting&quot;**

A chef for a catering event is sloppy, and when he prepares a bunch of pancakes they come out all different sizes. The pancakes are burnt on one side; also they are randomly flipped with the burnt at the top or bottom side.  There are M pancakes, such that M = X\*Y\*Z, where X, Y and Z are known. They are placed in X\*Y piles in a rectangular pan, where there are Z pancakes in each pile. This means there are X rows and Y columns of the pancake piles.

**Part 1: Implement Solutions to Pancake Sorting Problems (40%)**

**1. The Original Pancake Sorting Problem (20%)**

You would like to rearrange each pile of the pancakes so that the the sizes of them are in ascending order, i.e. the smallest winds up on top, and so on, down to the largest at the bottom. The only operation you are allowed to perform is grabbing several pancakes from the top and flipping them over, repeating this (varying the number you flip) as many times as necessary.

**2. Burnt Pancake Sorting Problem (20%)**

The pancakes are burnt on one side, so that in addition to ordering them correctly by size, they must also be placed with the burnt side face down. Initially, the burnt side of a pancake could face either up or down.

**Part 2: Rearrange the 3D Pancake Volume (30%)**

**1. Sort the Interior Piles (15%)**

Run your Burnt Pancake Sorting solution for every &quot;interior&quot; pile of pancakes such that they are all sorted **ascendingly** , meaning the largest pancake is placed at the bottom of each pile and the smallest at the top. An &quot;interior&quot; column is defined as a pile (of size Z pancakes) with the coordinate variable x as neither zero nor X-1, and also the  coordinate variable y as neither zero, nor Y-1; with x iterating from 0 to X-1 and y from 0 to Y-1. Also for each pile the burnt side of each pancake should be **down** (e.g., from the top view, one would see the non-burnt side of the pancakes for all interior columns. Note that you should do the sorting for (X-2)\*(Y-2) piles of pancakes.

**2. Sort the Exterior Piles (15%)**

Run your Burnt Pancake Sorting solution for every &quot;exterior&quot; pile such that they are sorted **descendingly** and the burnt side for each pancake faces **up**. An exterior pile is defined as a pile (of size Z pancakes) such that its x or y coordinates follow one of these values: x=0, or x=X-1, or y=0, or y=Y-1.

**OOP Requirements (30%)**

You should Implement the following three classes:

1) Class _Pancake_ that includes an integer variable _Size_ and a bool variable _Burnt_. Burnt =1 means the top side is burnt (and 0 mean the down side is burnt). A method _flip\_pancake()_ should be included that flips the pancake, i.e., inverts Burnt.

2) Class _PancakePile_ should be defined. It should include an array of size Z of pancake objects of type Pancake. The array can be maintained based on a pointer, or statically sized (of size Z). This class should include four methods: a) _pancake\_sort\_ascending()_; b) _pancake\_sort\_descending()_; c) _pancake\_sort\_ascending\_burnt\_down()_; d) _pancake\_sort\_descending\_burnt\_up()_.

3) Class _MPancakePiles_ which must include X\*Y objects of type class _PancakePile_. This class should include two methods: a) _sort\_interior()_; b) _sort\_exterior()._

**Part 3: Implement Optimized Pancake Sorting Algorithm (Extra Credit: 30%)**

In the Part 1, the solution you implemented takes at most _2n−3_ flipping movements to leave the pancakes perfectly ordered, where n is the number of pancakes in the pile. Bill Gates, the one who founded Microsoft, proposed an optimized algorithm that gave an upper bound of _(5n+5)/3_ in his only academic paper titled _Bounds for Sorting by Prefix Reversal_ [1] in 1979. 30 years later, a team of researchers from the University of Texas at Dallas, led by Professor Hal Sudborough proposed a further improved algorithm to establish that upper limit at _18n/11_ [2]. Pick one of these two algorithms to implement a solution to the original pancake sorting problem. Compare its runtime with the one you implement in Part 1.

**Part 4 (Optional): Statistical Analysis of the Pancake Piles**
Design a Python script that performs statistical analysis of piles, in terms the variance of their sizes, various correlations between different piles, such as cross-correlation, anti-correlation, etc. Please be reminded that this part has been changed to optional, hence no submission is required for this part. 


**References**

[1] Gates, William H., and Christos H. Papadimitriou. &quot;[Bounds for sorting by prefix reversal](https://people.eecs.berkeley.edu/~christos/papers/Bounds%20For%20Sorting%20By%20Prefix%20Reversal.pdf).&quot; _Discrete Mathematics_ 27.1 (1979): 47-57.

[2] Chitturi, Bhadrachalam, et al. &quot;[An (18/11) n upper bound for sorting by prefix reversals](https://www.sciencedirect.com/science/article/pii/S0304397508003575).&quot; _Theoretical Computer Science_ 410.36 (2009): 3372-3390.# EE599-Lab3
