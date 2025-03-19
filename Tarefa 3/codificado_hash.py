def OWF(char,bit):#algoritmo OWF
    x0=a=b=15
    m=2**bit
    for i in char:
        x1=(a*(x0+ord(i))+b)%m
        x0=x1
    return x0

def code(char,x0):#codificar
    var=[]
    m=2**8
    a=b=2
    for i in char:
        x1=(a*(x0)+b)%m
        x0=x1
        var.append(chr(x0^ord(i)))
    return ''.join(var)


char=input('escreva a palavra:')
x0=int(input('digite a senha:'))

print('Codificada ou Decodificada',code(char,x0))

bits=int(input('digite a quantidade de bits'))

print('Hashcode',OWF(char,bits))