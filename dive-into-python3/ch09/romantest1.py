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

if __name__ == '__main__':
    #print(__name__)
    #print(KnowValues.known_values)
    unittest.main()
else:
    print("test")
