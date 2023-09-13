import random
import string

all_letters = string.ascii_letters

#shuffle
random_letters = random.sample(all_letters, len(all_letters))
dict1 = {}
dict1_swap = {}

for i in range(len(all_letters)):
    dict1[all_letters[i]] = random_letters[i]

#dict swap부분 이거 사용하여 decrypt사용해도 괜찮음
#메모리 사용은 2배지만 시간 상으로는 괜찮을 듯 하다.
for key, value in dict1.items():
    dict1_swap[value] = key

plaintext = input("input plaintext: ")

def encryption(plaintxt):
    result = ""
    for char in plaintxt:
        if char in all_letters:
            result += dict1[char]
        else:
            result += char

    return result

def find_key(txt):
    result = None
    for i in all_letters:
        if dict1[i]==txt:
            result = i
            break;
    return result

def decryption(ciphertxt):
    result = ""
    for char in ciphertxt:
        if char in all_letters:
            decrypttxt = find_key(char)
            result += decrypttxt
        else:
            result += char
    return result


a = encryption(plaintext)
print(a)
b = decryption(a)
print(b)



