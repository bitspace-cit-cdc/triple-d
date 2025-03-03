#  Valid Square  


Given the coordinates of four points in 2D space p1, p2, p3, and p4, return true if the four points construct a square. Additionally, for the square to be valid, its center must lie on the origin (0, 0).

The coordinate of a point pi is represented as `[xi, yi]`. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles). The new constraint requires that the center of the square coincides with the origin.

 
---
Example 1:

Input: p1 = `[1,1]`, p2 = `[-1,-1]`, p3 = `[-1,1]`, p4 = `[1,-1]`  
Output: true  
Explanation: The square has its center at the origin (0, 0).  

---
Example 2:

Input: p1 = `[0,0]`, p2 = `[1,1]`, p3 = `[1,0]`, p4 = `[0,1]`  
Output: false  
Explanation: The square’s center does not coincide with the origin.  

---
Example 3:

Input: p1 = `[2,2]`, p2 = `[-2,-2]`, p3 = `[-2,2]`, p4 = `[2,-2]`  
Output: true  
Explanation: The square is centered at the origin and satisfies all conditions.

--- 

Constraints:  

    p1.length == p2.length == p3.length == p4.length == 2  
    -104 <= xi, yi <= 104  
