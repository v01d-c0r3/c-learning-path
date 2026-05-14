# Lesson: Operators, expressions & precedence

## Arithmetic operators

```c
int a = 17, b = 5;
printf("%d\n", a + b);  // 22  addition
printf("%d\n", a - b);  // 12  subtraction
printf("%d\n", a * b);  // 85  multiplication
printf("%d\n", a / b);  // 3   integer division — truncates!
printf("%d\n", a % b);  // 2   modulo (remainder)
```

**Integer division truncates toward zero** — `17 / 5` is `3`, not `3.4`. This is one of the most common bugs in C.

## Bitwise operators

Operate on the individual bits of an integer. Essential for systems programming.

```c
unsigned int x = 0b00001010;  // 10 in decimal

x & 0b00001111   // AND  — keeps only bits set in both:   0b00001010 = 10
x | 0b11110000   // OR   — sets bits set in either:       0b11111010 = 250
x ^ 0b11111111   // XOR  — flips bits set in either but not both: 0b11110101
~x               // NOT  — flips all bits
x << 2           // left shift  — multiply by 4:          0b00101000 = 40
x >> 1           // right shift — divide by 2:            0b00000101 = 5
```

### Practical bitwise recipes

```c
// Set bit N
value |= (1 << N);

// Clear bit N
value &= ~(1 << N);

// Toggle bit N
value ^= (1 << N);

// Test if bit N is set
if (value & (1 << N)) { ... }
```

## Logical operators

Return 1 (true) or 0 (false). Short-circuit: the right side is not evaluated if the result is already known.

```c
1 && 0   // AND — 0 (false)
1 || 0   // OR  — 1 (true)
!1       // NOT — 0 (false)

// Short-circuit example:
int x = 0;
if (x != 0 && 10/x > 2) { }  // safe — right side skipped when x==0
```

## Comparison operators

```c
a == b   // equal
a != b   // not equal
a <  b   // less than
a >  b   // greater than
a <= b   // less than or equal
a >= b   // greater than or equal
```

**Common bug:** using `=` (assignment) instead of `==` (comparison):
```c
if (x = 5) { }   // WRONG — assigns 5 to x, always true
if (x == 5) { }  // correct comparison
```

## Assignment operators

```c
x += 5;   // same as x = x + 5
x -= 3;   // same as x = x - 3
x *= 2;   // same as x = x * 2
x /= 4;   // same as x = x / 4
x %= 3;   // same as x = x % 3
x <<= 1;  // same as x = x << 1
x &= 0xFF;// same as x = x & 0xFF
```

## Increment and decrement

```c
x++;   // post-increment: use x, then add 1
++x;   // pre-increment:  add 1, then use x
x--;   // post-decrement
--x;   // pre-decrement
```

## Operator precedence (simplified, high to low)

| Precedence | Operators |
|-----------|-----------|
| Highest | `()` `[]` `.` `->` |
| | `!` `~` `++` `--` (unary) |
| | `*` `/` `%` |
| | `+` `-` |
| | `<<` `>>` |
| | `<` `<=` `>` `>=` |
| | `==` `!=` |
| | `&` |
| | `^` |
| | `\|` |
| | `&&` |
| | `\|\|` |
| Lowest | `=` `+=` `-=` etc. |

**When in doubt, use parentheses.** `(a + b) * c` is always clearer than relying on precedence rules.

---

## My notes

**What confused me:**

**What clicked:**

**Operator tricks I want to remember:**

**Things to look up later:**
