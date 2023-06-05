// x+y = x xor y + 2(x & y)
// So if aise likhenge we will get the equation as
//  2(x&y) = a-b
// So if a < b can't find solution so zero pushback krdo vector mein
// And if not zero then x has to be smallest non negative and for bitwise and to come to a particular value smallest vhi hoga
// So x = (a -b)/2
// then y = (a - x)
// And then 2x+3y nikal ke pushback krdo
// https://codeforces.com/blog/entry/94447


// Now can be solved easily