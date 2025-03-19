#!/bin/bash
#colocando em um array os arquivos
my_array=( $(find . -name '*.sh' ) )
len=${#my_array[@]}

#fazendo o loop para ler o array
for (( i=0; i<$len; i++ )); 
do 
    echo 'verificando o arquivo '${my_array[$i]}
    echo "${my_array[$i]}" | ./So1.sh 
done
