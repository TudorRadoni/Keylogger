UpperDict = {
    # Other keys
    '0': 'ERROR',           # Defined by me
    '08': '\b',             # Backspace
    '09': '\t',             # Tab
    '0C': 'CLEAR',          # Clear
    '0D': '\n',             # Enter
    '10': 'SHIFT',          # Shift
    '11': 'CTRL',           # Ctrl
    '12': 'ALT',            # Alt
    '13': 'PAUSE',          # Pause
    '14': 'CAPS LOCK',      # Caps Lock
    '1b': 'ESC',            # Esc
    '20': ' ',              # Space
    '21': 'PAGE UP',        # Page Up
    '22': 'PAGE DOWN',      # Page Down
    '23': 'END',            # End
    '24': 'HOME',           # Home
    '25': 'LEFT ARROW',     # Left Arrow
    '26': 'UP ARROW',       # Up Arrow
    '27': 'RIGHT ARROW',    # Right Arrow
    '28': 'DOWN ARROW',     # Down Arrow
    '29': 'SELECT',         # Select
    '2a': 'PRINT',          # Print
    '2b': 'EXECUTE',        # Execute
    '2c': 'PRINT SCREEN',   # Print Screen
    '2d': 'INSERT',         # Insert
    '2e': 'DELETE',         # Delete
    '2f': 'HELP',           # Help

    # Numeric keys
    '30': ')',
    '31': '!',
    '32': '@',
    '33': '#',
    '34': '$',
    '35': '%',
    '36': '^',
    '37': '&',
    '38': '*',
    '39': '(',

    # Alphabet keys
    '41': 'A',
    '42': 'B',
    '43': 'C',
    '44': 'D',
    '45': 'E',
    '46': 'F',
    '47': 'G',
    '48': 'H',
    '49': 'I',
    '4a': 'J',
    '4b': 'K',
    '4c': 'L',
    '4d': 'M',
    '4e': 'N',
    '4f': 'O',
    '50': 'P',
    '51': 'Q',
    '52': 'R',
    '53': 'S',
    '54': 'T',
    '55': 'U',
    '56': 'V',
    '57': 'W',
    '58': 'X',
    '59': 'Y',
    '5a': 'Z',

    # Other keys
    '5b': 'LWIN',           # Left Windows key
    '5c': 'RWIN',           # Right Windows key
    '5d': 'APPS',           # Applications key
    '5f': 'SLEEP',          # Computer Sleep key

    # Numeric keypad
    '60': 'NUMPAD 0',       # Numeric keypad 0
    '61': 'NUMPAD 1',       # Numeric keypad 1
    '62': 'NUMPAD 2',       # Numeric keypad 2
    '63': 'NUMPAD 3',       # Numeric keypad 3
    '64': 'NUMPAD 4',       # Numeric keypad 4
    '65': 'NUMPAD 5',       # Numeric keypad 5
    '66': 'NUMPAD 6',       # Numeric keypad 6
    '67': 'NUMPAD 7',       # Numeric keypad 7
    '68': 'NUMPAD 8',       # Numeric keypad 8
    '69': 'NUMPAD 9',       # Numeric keypad 9

    # Operator keys
    '6a': 'MULTIPLY',       # Multiply key
    '6b': 'ADD',            # Add key
    '6c': 'SEPARATOR',      # Separator key
    '6d': 'SUBTRACT',       # Subtract key
    '6e': 'DECIMAL',        # Decimal key
    '6f': 'DIVIDE',         # Divide key

    # Function keys
    '70': 'F1',             # F1 key
    '71': 'F2',             # F2 key
    '72': 'F3',             # F3 key
    '73': 'F4',             # F4 key
    '74': 'F5',             # F5 key
    '75': 'F6',             # F6 key
    '76': 'F7',             # F7 key
    '77': 'F8',             # F8 key
    '78': 'F9',             # F9 key
    '79': 'F10',            # F10 key
    '7a': 'F11',            # F11 key
    '7b': 'F12',            # F12 key
    '7c': 'F13',            # F13 key
    '7d': 'F14',            # F14 key
    '7e': 'F15',            # F15 key
    '7f': 'F16',            # F16 key
    '80': 'F17',            # F17 key
    '81': 'F18',            # F18 key
    '82': 'F19',            # F19 key
    '83': 'F20',            # F20 key
    '84': 'F21',            # F21 key
    '85': 'F22',            # F22 key
    '86': 'F23',            # F23 key
    '87': 'F24',            # F24 key

    # Other keys
    '90': 'NUMLOCK',                # NUM LOCK key
    '91': 'SCROLL LOCK',            # SCROLL LOCK key
    'a0': 'LSHIFT',                 # Left SHIFT key
    'a1': 'RSHIFT',                 # Right SHIFT key
    'a2': 'LCONTROL',               # Left CONTROL key
    'a3': 'RCONTROL',               # Right CONTROL key
    'a4': 'LALT',                   # Left ALT key
    'a5': 'RALT',                   # Right ALT key
    'a6': 'BROWSER BACK',           # Browser Back key
    'a7': 'BROWSER FORWARD',        # Browser Forward key
    'a8': 'BROWSER REFRESH',        # Browser Refresh key
    'a9': 'BROWSER STOP',           # Browser Stop key
    'aa': 'BROWSER SEARCH',         # Browser Search key
    'ab': 'BROWSER FAVORITES',      # Browser Favorites key
    'ac': 'BROWSER HOME',           # Browser Start and Home key
    'ad': 'VOLUME MUTE',            # Volume Mute key
    'ae': 'VOLUME DOWN',            # Volume Down key
    'af': 'VOLUME UP',              # Volume Up key
    'b0': 'MEDIA NEXT TRACK',       # Next Track key
    'b1': 'MEDIA PREVIOUS TRACK',   # Previous Track key
    'b2': 'MEDIA STOP',             # Stop Media
    'b3': 'MEDIA PLAY/PAUSE',       # Play/Pause Media
    'b4': 'LAUNCH MAIL',            # Start Mail key
    'b5': 'LAUNCH MEDIA SELECT',    # Select Media key
    'b6': 'LAUNCH APP1',            # Start Application 1 key
    'b7': 'LAUNCH APP2',            # Start Application 2 key
    'ba': ':',                      # For the US standard keyboard, the ';:' key
    'bb': '+',
    'bc': '<',
    'bd': '_',
    'be': '>',
    'bf': '?',                     # For the US standard keyboard, the '/?' key
    'c0': '~',                     # For the US standard keyboard, the '`~' key
}
