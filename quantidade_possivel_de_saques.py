total = int(input())
lista = list(set((map(int, input().split()))))
resultado = 0

def func(moedasAtuais, indexAtual):

  global resultado

  if(moedasAtuais > total):
    return None

  elif(moedasAtuais == total):
    resultado += 1
    return None

  for i in range(indexAtual, len(lista)):
    func(moedasAtuais + lista[i], i)


if(total < 0 or total > 1000):
  print(-1)

else:
  func(0, 0)
  print(resultado)
