# Python script to translate logs from the Keylogger
# into human-readable text. ⌨️

import sys
import os

from dataclasses import dataclass

from Dictionaries.lower import LowerDict
from Dictionaries.upper import UpperDict


class Key:
    def __init__(self, buff):
        # test if line is a key press
        if buff[0] == '#' or buff[0] == '\n':
            self.isValid = False
        else:
            self.isValid = True

        # get info about key press
        buff = buff.split(' ')
        if len(buff) == 6:
            self.MakeCode = buff[0]
            self.Flags = buff[1]
            self.Reserved = buff[2]
            self.VKey = buff[3]
            self.Message = buff[4]
            self.ExtraInformation = buff[5]
        else:
            self.isValid = False

    # interpret key press
    def getVKey(self, upper=False):
        if (upper):
            if self.VKey in UpperDict:
                return UpperDict[self.VKey]
            else:
                return '?'
        else:
            if self.VKey in LowerDict:
                return LowerDict[self.VKey]
            else:
                return '?'

    def getScan(self):
        return self.scan


# Read file
if (len(sys.argv) != 2):
    print("Usage: log2text.py <logfile>")
    sys.exit(1)
if (sys.argv[1] == '-h' or sys.argv[1] == '--help'):
    print("Usage: log2text.py <logfile>")
    sys.exit(0)
if (not sys.argv[1].endswith('.log')):
    print("File is not a log file")
    sys.exit(1)
if (not os.path.isfile(sys.argv[1])):
    print("File not found")
    sys.exit(1)
if (not os.access(sys.argv[1], os.R_OK)):
    print("File not readable")
    sys.exit(1)
    
with open(sys.argv[1], 'r') as f:
    Lines = f.readlines()

# Initialize flags
shift = False
ctrl = False
alt = False

outString = ''
for line in Lines:
    key = Key(line)

    # check if line is valid
    if not key.isValid:
        continue

    # check if key is a modifier
    if key.VKey == '10':
        if key.Flags == '0':
            shift = True
        else:
            shift = False
        continue

    elif key.VKey == '11':
        if key.Flags == '0':
            ctrl = True
        else:
            ctrl = False
        continue

    elif key.VKey == '12':
        if key.Flags == '0':
            alt = True
        else:
            alt = False
        continue

    # build buffer
    if key.Flags == '0':
        buff = key.getVKey()

        if shift:
            buff = key.getVKey(True)
        if ctrl:
            buff = " CTRL + " + key.getVKey() + ' '
        if alt:
            buff = " ALT + " + key.getVKey() + ' '
    else:
        buff = ''

    outString += buff
print(outString)

# Write to file
cwd = os.getcwd()
filePath = cwd + "\\output.txt"
with open(filePath, 'w') as f:
    f.write(outString)

print("Output written to " + filePath)
