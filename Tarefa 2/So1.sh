#!/bin/bash  
  
# Read the user input  

read -p $'Digite o caminho \n' path  

#verificando se é executavel
if [ -x "$path" ];
then
 echo 'é executavel' 
else 
 echo 'transformando em executavel' 
 chmod +x "$path"
fi

#verificando shebang
if head -1 $path | grep "^#\!" > /dev/null;

then
    echo "arquivo tem shebang"
else
    # fazendo a cópia
    cp "$path" "$path".bak 
    echo "colocando shebang no arquivo"
    if [ "$(head -c 2 $path)" = '' ];
    then #verificando caso o arquivo é vazio
        echo 'arquivo vazio'
        echo "#!/bin/bash" >> "$path"
    else
        # copiando
        sed -i '1 i #!/bin/bash' "$path"
    fi
fi