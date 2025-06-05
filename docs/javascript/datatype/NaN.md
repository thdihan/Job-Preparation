# NaN

## Not a number - NaN

A property of `global object`.

-   `typeof NaN` is `number`! :
    -   [Medium: NaN and typeof](https://javascriptrefined.io/nan-and-typeof-36cd6e2a4e43)
    -   [Medium: Why Does typeof NaN Return 'Number' in JavaScript? The Mystery Explained](https://medium.com/@conboys111/why-does-typeof-nan-return-number-in-javascript-the-mystery-explained-ca93f7090b9a)

```js
typeof NaN;

> "number";
```

## There are several ways in which NaN can happen:

-   Division of zero by zero
-   Dividing an infinity by an infinity
-   Multiplication of an infinity by a zero
-   Any operation in which NaN is an operand
-   Converting a non-numeric string or undefined into a number

## NaN is unordered

According to the IEEE 754 floating-point standard, comparison with NaN always returns an unordered result. That is, NaN is not equal to, greater than, or less than anything, including itself:

```js
NaN < 1; // false
NaN > 1; // false
NaN == NaN; // false
// But we can still check for NaN:
isNaN(NaN); // true
```

## Booleans are not NaNs

```js
isNaN(true); // false
isNaN(false); // false
```

This is because booleans are considered and implemented as numerical values with a single binary digit (i.e., bit), thus they are coerced into their respective bit representations:

```js
Number(true); // 1
Number(false); // 0
```
