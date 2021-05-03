tamMin = int(input())
senha = input()
vec = [0, 0, 0, 0]
totalCoisa = 4

verify = "!@#$%^&*()-+[];/.,><}{|\\!@#$%^&*()-_+=:?"
verify2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
verify3 = "abcdefghijklmnopqrstuvwxyz"
verify4 = "0123456789"

for i in senha:
  
  if(i in verify and vec[0] == 0):
    totalCoisa -= 1
    vec[0] = 1
  
  if(i in verify2 and vec[1] == 0):
    totalCoisa -= 1
    vec[1] = 1

  if(i in verify3 and vec[2] == 0):
    totalCoisa -= 1
    vec[2] = 1
  
  if(i in verify4 and vec[3] == 0):
    totalCoisa -= 1
    vec[3] = 1

print(max(totalCoisa, tamMin - len(senha)))

