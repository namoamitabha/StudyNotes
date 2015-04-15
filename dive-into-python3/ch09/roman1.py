# roman1.py
import re

class OutOfRangeError(ValueError): pass

class NotIntegerError(ValueError): pass

class InvalidRomanNumeralError(ValueError): pass

roman_numeral_pattern = re.compile('^M{0, 3}(CM|CD|D?C{0, 3})(XC|XL|L?X{0, 3})(IX|IV|V?I{0, 3})$', re.VERBOSE)

roman_numeral_map = (('M',  1000),
                     ('CM', 900),
                     ('D',  500),
                     ('CD', 400),
                     ('C',  100),
                     ('XC', 90),
                     ('L',  50),
                     ('XL', 40),
                     ('X',  10),
                     ('IX', 9),
                     ('V',  5),
                     ('IV', 4),
                     ('I',  1))

def to_roman(n):
    '''convert integer to Roman numeral'''

    if not (0 < n < 4000):
        raise OutOfRangeError('number out of range (must be less than 4000)')

    if not isinstance(n, int):
        raise NotIntegerError('non-integer can not be converted')

    result = ''
    for numeral, integer in roman_numeral_map:
        while n >= integer:
            result += numeral
            n -= integer
            #print('subtracting {0} from input, adding {1} to output'.format(integer, numeral))

    return result

def from_roman(s):
    '''convert Roman numeral to integer'''

    if not roman_numeral_pattern.search(s):
        raise InvalidRomanNumeralError('Invalid Roman numeral: {0}'.format(s))

    result = 0
    index = 0 
    for numeral, integer in roman_numeral_map:
        while s[index:index+len(numeral)] == numeral:
            result += integer
            index += len(numeral)

    return result

