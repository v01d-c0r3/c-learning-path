# Lesson: Control flow — if/else, switch, loops

## if / else if / else

```c
int score = 75;

if (score >= 90) {
    printf("A\n");
} else if (score >= 70) {
    printf("B\n");          // this runs
} else if (score >= 50) {
    printf("C\n");
} else {
    printf("Fail\n");
}
```

Braces `{}` are optional for single statements, but always use them — omitting them causes bugs when you add a second line later.

## switch

Use switch when comparing one variable against many constant values:

```c
int day = 3;
switch (day) {
    case 1: printf("Monday\n");    break;
    case 2: printf("Tuesday\n");   break;
    case 3: printf("Wednesday\n"); break;  // runs this
    default: printf("Weekend\n");  break;
}
```

**Always include `break`** — without it, execution falls through to the next case. This is sometimes intentional but usually a bug.

## for loop

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);   // prints 0 1 2 3 4
}
// structure: for (initialise; condition; update)
```

## while loop

```c
int n = 1;
while (n <= 5) {
    printf("%d\n", n);
    n++;
}
```

Use `while` when you don't know how many iterations you need upfront.

## do-while loop

Runs the body at least once before checking the condition:

```c
int input;
do {
    printf("Enter a positive number: ");
    scanf("%d", &input);
} while (input <= 0);
```

## break and continue

```c
for (int i = 0; i < 10; i++) {
    if (i == 3) continue;  // skip 3
    if (i == 7) break;     // stop at 7
    printf("%d ", i);      // prints: 0 1 2 4 5 6
}
```

## FizzBuzz — a classic example

```c
for (int i = 1; i <= 30; i++) {
    if      (i % 15 == 0) printf("FizzBuzz\n");
    else if (i % 3  == 0) printf("Fizz\n");
    else if (i % 5  == 0) printf("Buzz\n");
    else                  printf("%d\n", i);
}
```

Note: check `% 15` first — if you check `% 3` first, numbers divisible by 15 print "Fizz" and never reach the FizzBuzz check.

---

## My notes

**What confused me:**

**What clicked:**

**Loop patterns I want to remember:**

**Things to look up later:**
