#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    x = x >> n;
    x = x & 1; 
    return x;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    int y = * x;
    y = get_bit(y, n); //判断第n位的数字     
    v = v << n;         //将要插入的数字移动到第n位
    if(!y){          
        * x = * x ^ v; //异或，要插入的数字会改变，不插入的部分保持
    }
    else{               //当要插入的位置是1时，会得到要插入值的反面，要插入1 却插入了0
        unsigned z = 1;
        z = z << n;     
        v = v ^ z;      //改变要插入的值
        * x = * x ^ v;  //插入
    }
}
// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    unsigned z = 1;
    z = z << n;
    * x = * x ^ z; 
}

