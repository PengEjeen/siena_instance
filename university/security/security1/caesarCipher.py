import random
import string

#A-Z, a-z 
all_letters = string.ascii_letters

#단어 셔플
key = random.randrange(0, len(all_letters))


text = "Hello World"

#Caesar Encryption
def encrypt(plaintext):
    ciphertext = ""

    for char in plaintext:
        if char in all_letters:
            tempChar = all_letters.find(char)
            encIndexValue = (tempChar + key)%len(all_letters)

            ciphertext += all_letters[encIndexValue] #index -> char
        
        else:
            ciphertext += char
    return ciphertext

#Casesat Decryption
def decrypt(text):
    ciphertext = ""

    for char in text:
        if char in all_letters:
            tempChar = all_letters.find(char)
            decIndexValue = (tempChar - key)%len(all_letters)

            ciphertext += all_letters[decIndexValue]
        else:
            ciphertext += char
    return ciphertext

a = encrypt(text)
print(a)
b = decrypt(a)
print(b)
