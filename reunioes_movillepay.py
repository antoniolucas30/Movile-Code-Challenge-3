qntAgenda = int(input())
qntHoras = int(input())
primeiro = 0
ultimo = -1
horasPassadas = 0
vecAgenda = []

for i in range(24):
  vecAgenda.append(1)

for i in range(qntAgenda):

  inputHorarios = str(input()).split()

  for s in inputHorarios:

    n1 = int(s[0:s.find(',')])
    n2 = int(s[s.find(',') + 1:len(s)])

    for k in range(n1, n2):
      vecAgenda[k] = 0

for i in range(24):
  
  if(vecAgenda[i] == False):
    primeiro = i + 1
    ultimo = i
    horasPassadas = 0
  
  elif(vecAgenda[i] == True):
    ultimo += 1
    horasPassadas += 1

  if(horasPassadas == qntHoras):
    break

if(horasPassadas == qntHoras):
  print("O primeiro horario possivel para a reuniao eh das {}h00 as {}h00".format(primeiro, ultimo))

else:
  print("Nao existe horario no dia para marcar a reuniao")
