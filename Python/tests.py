#Kais Saradi    HW1
import unittest
from credit_card_validator import credit_card_validator

#test cases 
class TestCase(unittest.TestCase):
  def test_none(self):
    card_num = None
    self.assertFalse(credit_card_validator(card_num))
  def test_empty(self):
    card_num = ""
    self.assertFalse(credit_card_validator(card_num))
  def test_nothing(self):
    self.assertFalse(credit_card_validator())
  #Tests to check Visa card numbers
  # verifies correct visa numbers
  def test_visa_true(self):
    card_num = 4195905348577260
    self.assertTrue(credit_card_validator(card_num))
  
  #Tests prefix less than 4
  def test_visa_prefix(self):
    card_num = 3195905348577260
    self.assertFalse(credit_card_validator(card_num))
  #incorrect prefix with correct checksum
  def test_visa_prefix1(self):
    card_num = 3195905348577262
    self.assertFalse(credit_card_validator(card_num))

  #Tests prefix greater than 4
  def test_visa_prefix2(self):
    card_num = 5195905348577260
    self.assertFalse(credit_card_validator(card_num))
  #incorrect prefix with correct checksum
  def test_visa_prefix3(self):
    card_num = 5195905348577267
    self.assertFalse(credit_card_validator(card_num))

  #Tests wether an incorrect checksum returns false
  def test_visa_chksum(self):
    card_num = 4195905348577269
    self.assertFalse(credit_card_validator(card_num))

  #test card number with length less than 16
  def test_visa_length(self):
    card_num = 419590534857726
    self.assertFalse(credit_card_validator(card_num))
  #incorrect length with correct checksum
  def test_visa_length1(self):
    card_num = 419590534857722
    self.assertFalse(credit_card_validator(card_num))
  #tests card number with length greater than 16
  def test_visa_length(self):
    card_num = 41959053485772600
    self.assertFalse(credit_card_validator(card_num))
  #incorrect length with correct checksum
  def test_visa_length1(self):
    card_num = 41959053485772606
    self.assertFalse(credit_card_validator(card_num))

  #Test cases for Master Card
  #Test correct card numbers for each prefix returning true
  def test_MC_true(self):
    card_num = 5574725955631327
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true1(self):
    card_num = 5372074015024718
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true2(self):
    card_num = 5119649778075227
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true3(self):
    card_num = 5446500089286470
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true4(self):
    card_num = 5218300721203165
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true5(self):
    card_num = 2221003275202169
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true6(self):
    card_num = 2720996200946972
    self.assertTrue(credit_card_validator(card_num))

  #Test prefix less than 51

  #Test prefix greater than 55

  #Tests prefix less than 2221

  #Tests prefix greater than 2720

  #Test incorrect checksum for each prefix
  def test_MC_chksum(self):
    card_num = 5574725955631320
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum1(self):
    card_num = 5372074015024710
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum2(self):
    card_num = 5119649778075220
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum3(self):
    card_num = 5446500089286471
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum4(self):
    card_num = 5218300721203160
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum5(self):
    card_num = 2221003275202160
    self.assertFalse(credit_card_validator(card_num))

  def test_MC_chksum6(self):
    card_num = 2720996200946970
    self.assertFalse(credit_card_validator(card_num))

  #Test length less than 16 for each prefix

  #Test length greater than 16 for each prefix


  #Tests to check AMEX card numbers
  # verifies correct AMEX numbers for each prefix
  def test_AMEX_true(self):
    card_num = 348069335632374
    self.assertTrue(credit_card_validator(card_num))

  def test_AMEX_true(self):
    card_num = 377656744122643
    self.assertTrue(credit_card_validator(card_num))

  #Test incorrect checksum for each prefix
  def test_AMEX_chksum(self):
    card_num = 348069335632370
    self.assertFalse(credit_card_validator(card_num))

  def test_AMEX_chksum1(self):
    card_num = 377656744122640
    self.assertFalse(credit_card_validator(card_num))

  #Test length less than 15 for each prefix

  #Test length greater than 15 for each prefix

if __name__ == '__main__':
  unittest.main(verbosity=2)
