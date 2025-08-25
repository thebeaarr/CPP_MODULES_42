# C++ Fixed Point Implementation Deep Dive
## Connecting Theory to Your 42 School Code

### First, Let's Fix Your Code Errors

Your code has several syntax errors. Here's the corrected version:

```cpp
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyc) : _value(copyc._value) {  // Fixed syntax
    std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

Fixed &Fixed::operator=(const Fixed &op) {
    this->_value = op._value;  // Fixed syntax
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;  // Fixed syntax
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;  // Fixed syntax
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int &value) {
    this->_value = value << _fracbits;  // Fixed syntax
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value) {
    this->_value = (int)roundf(value * (1 << _fracbits));
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const {
    return (float)_value / (1 << _fracbits);
}

int Fixed::toInt() const {
    return _value >> _fracbits;  // Fixed syntax
}

std::ostream &operator<<(std::ostream &out, const Fixed &op) {
    out << op.toFloat();
    return out;
}
```

And the header file would be:
```cpp
// Fixed.hpp
#pragma once
#include <iostream>

class Fixed {
private:
    int _value;                    // The raw fixed-point value
    static const int _fracbits = 8; // Number of fractional bits (Q24.8)

public:
    Fixed();
    Fixed(const Fixed &copyc);
    Fixed(const int &value);
    Fixed(const float &value);
    ~Fixed();
    
    Fixed &operator=(const Fixed &op);
    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &op);
```

---

## Why Shift for Int and Calculate for Float?

### The Fundamental Difference

Your Fixed class uses **Q24.8 format**: 24 bits for integer part, 8 bits for fractional part.

```
Internal representation (_value):
[24 integer bits][8 fractional bits]
Scale factor = 2^8 = 256
```

### Integer Constructor: Why We Shift
```cpp
Fixed::Fixed(const int &value) {
    this->_value = value << _fracbits;  // _fracbits = 8
}
```

**Why shifting works for integers:**
- Integer 5 needs to become 5.0 in fixed point
- 5.0 in Q24.8 = 5 × 256 = 1280 (internal representation)
- 5 << 8 = 5 × 2^8 = 5 × 256 = 1280 ✓

**Binary visualization:**
```
Integer 5:     00000000 00000000 00000000 00000101
Shift left 8:  00000000 00000000 00000101 00000000
Result: 1280 = 5.0 in Q24.8 format
```

### Float Constructor: Why We Calculate
```cpp
Fixed::Fixed(const float &value) {
    this->_value = (int)roundf(value * (1 << _fracbits));
}
```

**Why we can't just shift floats:**
- Float 5.75 has both integer AND fractional parts
- We need: 5.75 × 256 = 1472 (internal representation)
- Shifting doesn't work for fractional values!

**Step by step:**
```cpp
float input = 5.75f;
// Step 1: (1 << _fracbits) = (1 << 8) = 256
// Step 2: value * 256 = 5.75 * 256 = 1472.0
// Step 3: roundf(1472.0) = 1472.0
// Step 4: (int)1472.0 = 1472
// Result: _value = 1472 represents 5.75 in Q24.8
```

---

## The Magic of (1 << _fracbits)

### Why Not Just Write 256?

```cpp
// These are equivalent when _fracbits = 8:
value * (1 << _fracbits)  // value * (1 << 8) = value * 256
value * 256               // Direct multiplication
```

**Why use bit shifting?**
1. **Generality**: Works for any _fracbits value
2. **Performance**: Bit shifts are faster than multiplication
3. **Clarity**: Shows the relationship to powers of 2
4. **Compile-time**: Modern compilers optimize this anyway

### Assembly Level Difference

```asm
; value * 256 (multiplication)
mov eax, [value]
imul eax, 256        ; Multiply instruction (slower)

; value * (1 << 8) (bit shift)  
mov eax, [value]
shl eax, 8           ; Shift left by 8 bits (faster)
```

---

## How roundf() Works

### The Precision Problem
```cpp
float value = 5.75f;
value * 256 = 1472.0f    // Perfect
```

But what about:
```cpp
float value = 5.333f;
value * 256 = 1365.248f  // Not an integer!
```

### roundf() to the Rescue
```cpp
roundf(1365.248f) = 1365.0f
(int)1365.0f = 1365
```

**What roundf() does:**
- `1365.248` → `1365` (rounds down)
- `1365.748` → `1366` (rounds up)
- `1365.500` → `1366` (rounds to even - banker's rounding)

### Visual Example
```
Float 3.14159 to Q24.8:
3.14159 * 256 = 804.24704
roundf(804.24704) = 804
804 in Q24.8 = 804/256 = 3.140625 (close to 3.14159)
```

---

## Conversion Back: toFloat() and toInt()

### toFloat() - Get Original Precision
```cpp
float Fixed::toFloat() const {
    return (float)_value / (1 << _fracbits);
}
```

**Example:**
```cpp
// _value = 1472 (represents 5.75)
return (float)1472 / 256;  // 5.75f
```

### toInt() - Extract Integer Part
```cpp
int Fixed::toInt() const {
    return _value >> _fracbits;
}
```

**Why right shift works:**
```
_value = 1472 (binary: 00000101 11100000)
                       [int=5  ][frac=224]
Right shift 8: 00000000 00000101 = 5
```

**Fractional part gets discarded automatically!**

---

## CPU and Assembly Deep Dive

### Memory Layout (32-bit system)
```
Fixed object memory:
Offset 0: _value (4 bytes)
Total size: 4 bytes

_value internal bits (Q24.8):
Bit 31-8: Integer part (24 bits) - range: -8,388,608 to +8,388,607
Bit 7-0:  Fractional part (8 bits) - precision: 1/256 = 0.00390625
```

### Assembly Analysis

**Integer Constructor:**
```cpp
Fixed(const int &value) { this->_value = value << 8; }
```
```asm
; Assembly equivalent (x86-64)
mov eax, [rdi]      ; Load integer value
shl eax, 8          ; Shift left by 8 (multiply by 256)
mov [rsi], eax      ; Store in _value
```

**Float Constructor:**
```cpp
Fixed(const float &value) { 
    this->_value = (int)roundf(value * (1 << 8)); 
}
```
```asm
; Assembly equivalent (x86-64)
movss xmm0, [rdi]   ; Load float into SSE register
movss xmm1, [256.0] ; Load 256.0
mulss xmm0, xmm1    ; Multiply: xmm0 = value * 256
call roundf         ; Call roundf function
cvttss2si eax, xmm0 ; Convert float to int (truncate)
mov [rsi], eax      ; Store in _value
```

### Performance Implications

**Operation speeds (typical x86 CPU):**
1. **Bit shifts** (`<<`, `>>`): 1 cycle
2. **Integer add/sub**: 1 cycle  
3. **Integer multiply**: 3-4 cycles
4. **Float multiply**: 4-5 cycles
5. **Float-to-int conversion**: 6-10 cycles

**Why Fixed Point is Fast:**
- Most operations use integer arithmetic
- Bit shifts instead of division/multiplication by powers of 2
- No floating point unit needed

---

## 42 School Context: Why This Matters

### Orthodox Canonical Form (OCF)
Your class follows OCF requirements:
```cpp
Fixed();                        // Default constructor
Fixed(const Fixed &copyc);      // Copy constructor  
Fixed &operator=(const Fixed &); // Assignment operator
~Fixed();                       // Destructor
```

### Additional Constructors (Evolution)
```cpp
Fixed(const int &value);        // Int conversion constructor
Fixed(const float &value);      // Float conversion constructor
```

### Memory Management
```cpp
// No dynamic memory allocation needed!
// _value is stored directly in the object
// No need for deep copy - shallow copy is fine
```

### Why 42 Teaches This

1. **Understanding binary representation**
2. **Performance optimization concepts**  
3. **Numerical precision awareness**
4. **Low-level programming skills**
5. **Alternative to floating point**

---

## Practical Example: Money Calculation

```cpp
// Using your Fixed class for money (cents precision)
Fixed price(19.99f);        // $19.99
Fixed tax_rate(0.08f);      // 8% tax
Fixed tax = price * tax_rate;  // Multiplication operator needed
Fixed total = price + tax;     // Addition operator needed

std::cout << "Price: $" << price << std::endl;   // $19.99
std::cout << "Tax: $" << tax << std::endl;       // $1.60 (approximately)  
std::cout << "Total: $" << total << std::endl;   // $21.59 (approximately)
```

### What Happens Internally:
```cpp
// price._value = (int)roundf(19.99f * 256) = 5117
// tax_rate._value = (int)roundf(0.08f * 256) = 20
// Multiplication: (5117 * 20) >> 8 = 399 (represents ~$1.56)
// Addition: 5117 + 399 = 5516 (represents ~$21.55)
```

---

## Next Steps for CPP02

To complete your 42 project, you'll need to implement:

### Arithmetic Operators:
```cpp
Fixed operator+(const Fixed &other) const;
Fixed operator-(const Fixed &other) const;  
Fixed operator*(const Fixed &other) const;
Fixed operator/(const Fixed &other) const;
```

### Comparison Operators:
```cpp
bool operator>(const Fixed &other) const;
bool operator<(const Fixed &other) const;
bool operator>=(const Fixed &other) const;
bool operator<=(const Fixed &other) const;
bool operator==(const Fixed &other) const;
bool operator!=(const Fixed &other) const;
```

### Increment/Decrement:
```cpp
Fixed &operator++();      // Pre-increment
Fixed operator++(int);    // Post-increment  
Fixed &operator--();      // Pre-decrement
Fixed operator--(int);    // Post-decrement
```

### Static Functions:
```cpp
static Fixed &min(Fixed &a, Fixed &b);
static const Fixed &min(const Fixed &a, const Fixed &b);
static Fixed &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed &a, const Fixed &b);
```

The key insight: **Your Fixed class bridges the gap between integer precision and floating point flexibility, giving you the best of both worlds for specific use cases.**

# The Complete Guide to Number Representation in Computers
## Understanding Integers, Fixed Point, and Floating Point

### Introduction: The Problem with Real Numbers

Computers are binary machines - they only understand 0s and 1s. But we need to represent all kinds of numbers:
- Whole numbers: 5, -12, 1000
- Decimal numbers: 3.14, 0.5, -2.75
- Very large numbers: 6.022 × 10²³ 
- Very small numbers: 0.000001

How do we fit all these different types into binary? That's where our three number systems come in.

---

## Part 1: Integers - The Foundation

### What Are Integers?
Integers are whole numbers: ..., -3, -2, -1, 0, 1, 2, 3, ...

### How Computers Store Integers
```
8-bit signed integer range: -128 to +127

Binary representation:
+5  = 00000101
-5  = 11111011 (two's complement)
+127= 01111111  
-128= 10000000
```

### Integer Arithmetic is Perfect (Within Range)
```c
int a = 5;
int b = 3;
int c = a + b;  // Always exactly 8
int d = a * b;  // Always exactly 15
```

### Integer Limitations
- **No fractions**: Can't represent 2.5 or 0.1
- **Limited range**: 32-bit int goes from -2,147,483,648 to +2,147,483,647
- **Overflow**: Adding 1 to maximum value wraps to minimum

---

## Part 2: Fixed Point - Integers Pretending to be Decimals

### The Core Idea
"Let's use integers, but pretend some bits represent fractional parts!"

### Example: Q8.8 Format (8 integer bits, 8 fractional bits)
```
Number: 12.75
Binary: 12 = 00001100, 0.75 = 11000000
Combined: 0000110011000000
Stored as integer: 3264
To get back: 3264 ÷ 256 = 12.75
```

### Fixed Point Arithmetic
```c
// Q16.16 format (scale factor = 65536)
typedef int32_t fixed_t;

// Converting to/from fixed point
fixed_t to_fixed(float f) {
    return (fixed_t)(f * 65536);
}

float from_fixed(fixed_t f) {
    return (float)f / 65536;
}

// Operations
fixed_t add_fixed(fixed_t a, fixed_t b) {
    return a + b;  // Simple addition
}

fixed_t mul_fixed(fixed_t a, fixed_t b) {
    return ((int64_t)a * b) >> 16;  // Multiply then scale down
}
```

### Fixed Point Example
```c
fixed_t price = to_fixed(19.99);    // $19.99
fixed_t tax_rate = to_fixed(0.08);  // 8% tax
fixed_t tax = mul_fixed(price, tax_rate);
fixed_t total = add_fixed(price, tax);

printf("Price: $%.2f\n", from_fixed(price));     // $19.99
printf("Tax: $%.2f\n", from_fixed(tax));         // $1.60
printf("Total: $%.2f\n", from_fixed(total));     // $21.59
```

### Fixed Point Characteristics
**Advantages:**
- **Predictable precision**: Always the same resolution
- **Fast**: Uses integer arithmetic
- **Deterministic**: Same input = same output, always
- **No special values**: No NaN, infinity, etc.

**Disadvantages:**
- **Limited range**: Can't represent very large or small numbers
- **Fixed precision**: Can't adapt to different magnitudes
- **Manual scaling**: Programmer must handle the scale factor

---

## Part 3: Floating Point - The Flexible Solution

### The Scientific Notation Approach
Floating point is like scientific notation: **1.23 × 10⁴**

In binary: **1.mantissa × 2^exponent**

### IEEE 754 Single Precision (32-bit)
```
Sign (1 bit) | Exponent (8 bits) | Mantissa (23 bits)
     0       |    10000010       | 10010000000000000000000

Represents: (-1)^0 × 1.1001 × 2^(130-127) = 1.5625 × 2³ = 12.5
```

### Floating Point Examples
```c
float small = 0.000001f;     // 1.0 × 2^-20 (approximately)
float large = 1000000.0f;    // 1.0 × 2^20 (approximately)  
float result = small + large; // Large number "eats" the small one
```

### The Precision Problem
```c
float x = 0.1f;
printf("%.17f", x);  // Prints: 0.10000000149011612

// Why? Because 0.1 in binary is:
// 0.000110011001100110011... (repeating forever)
// Computer cuts it off, causing error
```

### Floating Point Characteristics  
**Advantages:**
- **Huge range**: From ~10^-38 to ~10^+38
- **Automatic scaling**: Adjusts precision based on magnitude
- **Standard**: IEEE 754 works everywhere
- **Hardware support**: Built into modern CPUs

**Disadvantages:**
- **Variable precision**: Less precise for large numbers
- **Rounding errors**: 0.1 + 0.2 ≠ 0.3 exactly
- **Complex**: Special values (NaN, infinity, denormals)
- **Non-deterministic**: Slight variations possible across systems

---

## Part 4: Comparing All Three Systems

### Range Comparison (32-bit systems)
```
Integer (int32):
  Range: -2,147,483,648 to +2,147,483,647
  Precision: Perfect within range

Fixed Point (Q16.16):  
  Range: -32,768.0 to +32,767.99998
  Precision: 1/65536 ≈ 0.0000152 (constant)

Floating Point (float):
  Range: ±1.4×10^-45 to ±3.4×10^+38  
  Precision: ~7 decimal digits (variable)
```

### The Classic 0.1 + 0.2 Problem
```c
// Integer: Can't represent 0.1 or 0.2 at all!
int result = 0.1 + 0.2;  // Compilation error or truncates to 0

// Fixed Point: Consistent approximation
fixed_t a = to_fixed(0.1);    // 6553 (represents 0.099990844...)
fixed_t b = to_fixed(0.2);    // 13107 (represents 0.200012207...)  
fixed_t c = a + b;            // 19660 (represents 0.300003051...)
// Always the same "wrong" answer

// Floating Point: Variable approximation  
float x = 0.1f + 0.2f;        // 0.30000000596046448
// Might vary slightly on different systems
```

### Money Calculation Example
```c
// The Problem: $10.00 - $9.90 should equal $0.10

// Integer (cents): Perfect for money
int total_cents = 1000;        // $10.00
int spent_cents = 990;         // $9.90  
int change_cents = total_cents - spent_cents;  // 10 cents exactly

// Fixed Point: Predictable for money
fixed_t total = to_fixed(10.00);
fixed_t spent = to_fixed(9.90);
fixed_t change = total - spent;  // Consistently accurate

// Floating Point: Problematic for money
float total_f = 10.00f;
float spent_f = 9.90f;  
float change_f = total_f - spent_f;  // Might be 0.099999994 instead of 0.1
```

---

## Part 5: When to Use Which System

### Use Integers When:
- Counting things (users, items, iterations)
- Array indices and memory addresses
- Bit manipulation and flags
- Loop counters
- Exact whole number arithmetic is needed

```c
// Perfect use cases:
int user_count = 1500;
int array_index = 42;
int pixels = width * height;
```

### Use Fixed Point When:
- Financial calculations (money, accounting)
- Real-time systems (audio, control systems)
- Embedded systems without floating point units
- Game physics (for deterministic replay)
- When consistent precision is more important than range

```c
// Perfect use cases:
fixed_t account_balance = to_fixed(1234.56);  // Banking
fixed_t audio_sample = input * 32768;         // Audio processing
fixed_t game_position = to_fixed(player.x);   // Game coordinates
```

### Use Floating Point When:
- Scientific calculations
- 3D graphics and rendering  
- Machine learning and AI
- Mathematical functions (sin, cos, sqrt)
- When wide dynamic range is needed

```c
// Perfect use cases:
float distance = sqrt(x*x + y*y + z*z);      // 3D math
float physics_sim = force / mass;             // Physics
float neural_weight = 0.001234f;              // AI/ML
```

---

## Part 6: Common Pitfalls and Solutions

### Integer Overflow
```c
// Problem:
int big = 2000000000;
int bigger = big + 1000000000;  // Overflow! Wraps to negative

// Solution: Use larger type or check bounds
long long safe = (long long)big + 1000000000;
```

### Fixed Point Overflow in Multiplication  
```c
// Problem:
fixed_t a = to_fixed(30000.0);  
fixed_t b = to_fixed(30000.0);
fixed_t wrong = (a * b) >> 16;  // Overflow before shift!

// Solution: Use wider intermediate type
fixed_t correct = ((int64_t)a * b) >> 16;
```

### Floating Point Comparison
```c
// Problem:
float a = 0.1f + 0.2f;
if (a == 0.3f) {  // Might be false!
    printf("Equal");
}

// Solution: Compare with epsilon
float epsilon = 0.00001f;
if (fabs(a - 0.3f) < epsilon) {
    printf("Close enough");
}
```

---

## Part 7: Performance Comparison

### Speed (typical modern CPU):
1. **Integer**: Fastest (1 cycle for basic ops)
2. **Fixed Point**: Fast (integer speed + some overhead for scaling)
3. **Floating Point**: Slower (but hardware accelerated on modern CPUs)

### Memory Usage (32-bit systems):
- All three use the same amount of memory (4 bytes)
- But fixed point often allows using smaller data types

### Power Consumption:
1. **Integer**: Lowest power
2. **Fixed Point**: Low power (uses integer units)  
3. **Floating Point**: Higher power (dedicated FPU)

---

## Part 8: The Evolution Story

### 1940s-1950s: Integer Era
- Early computers: ENIAC, UNIVAC
- Only integers, programmers manually tracked decimal points
- "If you want 12.34, store 1234 and remember it's hundredths"

### 1960s-1980s: Fixed Point Rise
- Embedded systems, digital signal processors
- Audio equipment, industrial control
- Games consoles (Nintendo, early arcade machines)

### 1985-Present: Floating Point Dominance  
- IEEE 754 standard (1985)
- Hardware floating point units became standard
- Scientific computing explosion

### Today: All Three Coexist
- **Integers**: Still fundamental for counting, indexing
- **Fixed Point**: Resurging in mobile, IoT, finance, AI chips
- **Floating Point**: Standard for desktop/server applications

---

## Conclusion: The Right Tool for the Job

There's no "best" number system - only the best one for your specific needs:

**Choose based on:**
- **Range requirements**: How big/small are your numbers?
- **Precision needs**: Consistent vs. adaptive precision?
- **Performance constraints**: Speed, power, memory?  
- **Determinism**: Must results be identical everywhere?
- **Hardware**: What does your target system support?

**Remember:**
- **Integers** are perfect within their range
- **Fixed point** gives consistent precision within a limited range
- **Floating point** gives flexible precision over a huge range

Understanding all three makes you a better programmer who can choose the right tool for each specific problem.

The key insight: **All number systems are trade-offs.** Perfect representation of all real numbers is impossible in finite computer memory. The art is choosing the right compromise for your application.
