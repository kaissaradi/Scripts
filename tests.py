#Kais Saradi    HW1
import unittest
from credit_card_validator import credit_card_validator

#test cases 
class TestCase(unittest.TestCase):
#Verify Empty strings return false
#Chosen by testing possible error values
  def test_none(self):
    card_num = None
    self.assertFalse(credit_card_validator(card_num))
  def test_empty(self):
    card_num = ""
    self.assertFalse(credit_card_validator(card_num))

  def test_1(self):
    card_num = 3495905348577269
    self.assertFalse(credit_card_validator(card_num))  

#Verify Corect values for Visa, Mastercard, and AMEX for each prefix return true
#Chosen using partition category testing
  def test_visa_true(self):
    card_num = 4195905348577260
    self.assertTrue(credit_card_validator(card_num))

  def test_MC_true(self):
    card_num = "5574 725955631327"
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

  def test_AMEX_true(self):
    card_num = 348069335632374
    self.assertTrue(credit_card_validator(card_num))
  def test_AMEX_true(self):
    card_num = 377656744122643
    self.assertTrue(credit_card_validator(card_num))

#Visa Verification
#Verify incorrect prefix with correct checksum and length returns false
#chosen using Category partition testing
  def test_visa_prefix1(self):
    card_num = 3195905348577262
    self.assertFalse(credit_card_validator(card_num))

#Verify incorrect prefix with incorrect checksum returns False
#chosen using Category partition testing
  def test_visa_prefix2(self):
    card_num = 3195905348577260
    self.assertFalse(credit_card_validator(card_num))

#Verify wether an incorrect checksum returns false with correct prefix and length
#chosen using Category partition testing
  def test_visa_chksum(self):
    card_num = 4195905348577269
    self.assertFalse(credit_card_validator(card_num))

#Verify correct card number with length less than 16 and correct checksum returns false
#chosen using Category partition testing
  def test_visa_length(self):
    card_num = 477656744122642
    self.assertFalse(credit_card_validator(card_num))

#Verify incorrect length <16 with incorrect checksum and prefix returns false
#chosen using Category partition testing
  def test_visa_length1(self):
    card_num = 477656744122640
    self.assertFalse(credit_card_validator(card_num))

#Verify card number with length greater than 16 and incorrect checksum returns false
#chosen using Category partition testing
  def test_visa_length(self):
    card_num = 41959053485772600
    self.assertFalse(credit_card_validator(card_num))

#Verify card number with length greater than 16 and correct checksum returns false
#chosen using Category partition testing
  def test_visa_length1(self):
    card_num = 41959053485772606
    self.assertFalse(credit_card_validator(card_num))

#Master Card
#Verify incorrect prefix and incorrect checksum returns False
#chosen using Category partition testing
  def test_MC_prefix(self):
    card_num = 5091154074631832
    self.assertFalse(credit_card_validator(card_num))

#Verify incorrect prefix and correct checksum returns False
#chosen using Category partition testing
  def test_MC_prefix_1(self):
    card_num = 5091154074631833
    self.assertFalse(credit_card_validator(card_num))

#Verify incorrect checksum for each prefix returns false
#chosen using Category partition testing
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
    
#Verify length less than 16 and incorrect prefix returns false
#chosen using Category partition testing
  def test_MC_len1(self):
    card_num = 511964977807524
    self.assertFalse(credit_card_validator(card_num))

#Verify length less than 16 and correct prefix returns false
#chosen using Category partition testing
  def test_MC_len2(self):
    card_num = 272099620094691
    self.assertFalse(credit_card_validator(card_num))

#Verify length greater than 16 and incorrect prefix returns false
#chosen using Category partition testing
  def test_MC_len3(self):
    card_num = 55747259556313275
    self.assertFalse(credit_card_validator(card_num))

#Verify length greater than 16 and correct prefix returns false
#chosen using Category partition testing
  def test_MC_len4(self):
    card_num = 27209962009469720
    self.assertFalse(credit_card_validator(card_num))

#AMEX
#Verify incorrect checksum for each prefix returns False
#chosen using Category partition testing
  def test_AMEX_chksum(self):
    card_num = 348069335632370
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_chksum1(self):
    card_num = 377656744122640
    self.assertFalse(credit_card_validator(card_num))
  
#Verify incorrect prefix returns false for prefixes below 34, above 37, and between
#chosen using Category partition testing
  def test_AMEX_prefix(self):
    card_num = 358069335632371
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_prefix1(self):
    card_num = 387656744122641
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_prefix3(self):
    card_num = 337656744122642
    self.assertFalse(credit_card_validator(card_num))
    
  #Verify length less than 15 for each prefix returns false
  #chosen using Category partition testing
  def test_AMEX_len(self):
    card_num = 34806933563231
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_len1(self):
    card_num = 37765674412262
    self.assertFalse(credit_card_validator(card_num))

  #Verify length greater than 15 for each prefix returns false
  #chosen using Category partition testing
  def test_AMEX_len2(self):
    card_num = 3480693356323746
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_len3(self):
    card_num = 3776567441226432
    self.assertFalse(credit_card_validator(card_num))

  #Test length less than 15 for each prefix with incorrect checksum
  #chosen using Category partition testing
  def test_AMEX_len4(self):
    card_num = 3480693356323740
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_len5(self):
    card_num = 3776567441226430
    self.assertFalse(credit_card_validator(card_num))

  #Test length greater than 15 for each prefix with incorrect checksum
  #chosen using Category partition testing
  def test_AMEX_len6(self):
    card_num = 348069335632310
    self.assertFalse(credit_card_validator(card_num))
  def test_AMEX_len7(self):
    card_num = 377656744122620
    self.assertFalse(credit_card_validator(card_num))

#Verify AMEX card with Visa prefix
#chosen using Category partition testing
  def test_length(self):
    card_num = 448069335632373
    self.assertFalse(credit_card_validator(card_num))  

#Verify Visa card with AMEX prefix returns false
#chosen using Category partition testing
  def test_length2(self):
    card_num = 3495905348577269
    self.assertFalse(credit_card_validator(card_num))  


if __name__ == '__main__':
  unittest.main(verbosity=2)