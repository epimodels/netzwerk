import unittest

# Import pybind11-based netzwerk extension module from package netzwerk
from netzwerk import netzwerk

class MainTest(unittest.TestCase):
    def test_add(self):
        # test that 1 + 1 = 2
        self.assertEqual(netzwerk.add(1, 1), 2)

    def test_subtract(self):
        # test that 1 - 1 = 0
        self.assertEqual(netzwerk.subtract(1, 1), 0)

if __name__ == '__main__':
    unittest.main()
