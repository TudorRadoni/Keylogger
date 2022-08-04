# Interpreter algorithm

## Algorithm

### Main logic

Here is a brief description of the algorithm.

1. Read line
2. Check if line is valid
3. Split line into codes
4. Check for flags (CTRL, SHIFT or ALT)
5. Build buffer
6. Write buffer to file & output to console

### Interpreting flags

- If `SHIFT` is pressed, print all characters as UPPERCASE until it is released
- If `CTRL` is pressed, print *"CTRL + " + character*
- If `ALT` is pressed, print *"ALT + " + character*

## References

- [RAWKEYBOARD structure](https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-rawkeyboard)
- [Virtual-Key Codes](https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes)
