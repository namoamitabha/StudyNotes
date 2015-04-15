import roman1
import unittest

class KnowValues(unittest.TestCase):

    known_values = ((1, 'I'),
                    (2, 'II'),
                    (3, 'III'),
                    (4, 'IV'),
                    (5, 'V'),
                    (6, 'VI'),
                    (7, 'VII'),
                    (8, 'VIII'),
                    (9, 'IX'),
                    (10, 'X'))

    def test_to_roman_known_values(self):
        '''to_roman should give known result with known input'''
        #print(self.known_values)
        for integer, numeral in self.known_values:
            result = roman1.to_roman(integer)
            #print(result)
            self.assertEqual(numeral, result)


class ToRomanBadInput(unittest.TestCase):

    def test_too_large(self):
        '''to_roman should fail with large input'''
        self.assertRaises(roman1.OutOfRangeError, roman1.to_roman, 4000)

    def test_zero(self):
        '''to_roman should fail with 0 input'''
        self.assertRaises(roman1.OutOfRangeError, roman1.to_roman, 0)

    def test_negative(self):
        '''to_roman should fail with negative input'''
        self.assertRaises(roman1.OutOfRangeError, roman1.to_roman, -1)

    def test_non_integer(self):
        '''to_roman should fail with non-integer input'''
        self.assertRaises(roman1.NotIntegerError, roman1.to_roman, 0.5)

if __name__ == '__main__':
    #print(__name__)
    #print(KnowValues.known_values)
    unittest.main()
else:
    print("test")
